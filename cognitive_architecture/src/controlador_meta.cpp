#include "rclcpp/rclcpp.hpp"
#include <string>
#include <memory>
#include <thread>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "cognitive_architecture/robot.hpp"

using namespace std;

int tipo;
int task;
int num_bots;

int main(int argc, char **argv)
{
    // Configuración de entorno para Gazebo
    setenv("GAZEBO_MASTER_URI", "http://localhost:11345", 1);
    setenv("ROS_DOMAIN_ID", "1", 1);

    // SOLUCIÓN ZOMBI: Leemos 5 argumentos obligatorios para evitar preguntas
    if (argc < 5)
    {
        cerr << "USO: meta_exe tipo num_bots task MODO(1=Train, 2=Mirror)" << endl;
        return 0;
    }

    rclcpp::init(argc, argv);

    double Goalx = 10.0;
    double Goaly = 10.0;
    cout << "Meta Fija establecida en: " << Goalx << ", " << Goaly << endl;

    tipo = atoi(argv[1]);
    num_bots = atoi(argv[2]);
    task = atoi(argv[3]);
    char senal = *argv[4]; // <--- LEEMOS EL MODO DIRECTAMENTE DEL ARGUMENTO

    cerr << "Lanzando " << num_bots << " robots..." << endl;
    vector<Robot> robots;

    for (int i = 1; i <= num_bots; ++i)
    {
        robots.push_back(Robot(i, to_string(tipo)[0], task, num_bots, Goalx, Goaly));
        cerr << "Robot " << i << " inicializado." << endl;
    }

    vector<thread> threads;
    for (int i = 0; i < static_cast<int>(robots.size()); i++)
    {
        threads.push_back(thread([&robots, i]()
                                 { robots[i].ejecutar(); }));
    }

    if (tipo == 0)
    {
        // YA NO HAY CIN, USAMOS LA VARIABLE 'senal' LEÍDA ARRIBA
        if (senal == '1'){
            cout << "--- MODO ENTRENAMIENTO ---" << endl;
             threads.push_back (thread([]() 
                {   
                    system("export GAZEBO_MASTER_URI=http://localhost:11346");
                    system("export ROS_DOMAIN_ID=2");
                    system("ros2 launch cognitive_architecture meta_trainning.launch.py task:=1"); }));

            threads.push_back (thread([arg1 = string(argv[1]), arg3 = string(argv[3])]() 
                {   
                    system("export GAZEBO_MASTER_URI=http://localhost:11346");
                    system("export ROS_DOMAIN_ID=2");
                    ostringstream command;
                    command << "ros2 run cognitive_architecture meta_exe " << arg1 << " 1 " << arg3 << " 0"; 
                    system(command.str().c_str()); }));
        }
        else if (senal == '2') {
             cout << "--- INICIANDO PROTOCOLO DE IMITACIÓN (MIRRORING) ---" << endl;
             // Esperamos un poco a que todo cargue
             std::this_thread::sleep_for(std::chrono::seconds(2));
             robots[0].mirroring();
        }
    }

    for (auto &thread : threads) thread.join();
    rclcpp::shutdown();

    return 0;
}
