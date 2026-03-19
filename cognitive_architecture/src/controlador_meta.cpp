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

int main(int argc, char **argv)
{
    setenv("GAZEBO_MASTER_URI", "http://localhost:11345", 1);
    
    if (argc < 5)
    {
        cerr << "USO: meta_exe tipo num_bots task MODO(1=Train, 2=Mirror)" << endl;
        return 0;
    }

    rclcpp::init(argc, argv);

    double Goalx = 10.0;
    double Goaly = 10.0;
    int tipo = atoi(argv[1]);
    int num_bots = atoi(argv[2]);
    int task = atoi(argv[3]);
    char senal = *argv[4]; 

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "SISTEMA INICIADO - Desplegando enjambre de %d robots...", num_bots);
    
    // CAMBIO VITAL: Vector de punteros inteligentes para proteger la memoria
    vector<shared_ptr<Robot>> robots;

    for (int i = 1; i <= num_bots; ++i)
    {
        // Creamos el robot y lo guardamos de forma segura
        auto nuevo_robot = make_shared<Robot>(i, to_string(tipo)[0], task, num_bots, Goalx, Goaly);
        robots.push_back(nuevo_robot);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Robot %d -> ONLINE", i);
    }

    vector<thread> threads;
    for (int i = 0; i < static_cast<int>(robots.size()); i++)
    {
        // Accedemos con -> porque ahora son punteros
        threads.push_back(thread([&robots, i]()
                                 { robots[i]->ejecutar(); }));
    }

    if (tipo == 0)
    {
        if (senal == '2') {
             RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "MODO IMITACIÓN - Sincronizando enjambre...");
             std::this_thread::sleep_for(std::chrono::seconds(2));
             // Acceso seguro al primer robot
             robots[0]->mirroring();
        }
    }

    for (auto &thread : threads) {
        if (thread.joinable()) thread.join();
    }

    rclcpp::shutdown();
    return 0;
}
