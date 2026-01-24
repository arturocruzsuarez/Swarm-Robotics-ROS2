#include "robot.h"

Robot::Robot(int id , char tipo, int task, int numMates, double goalx, double goaly) {
    id_ = id;
    tipo_ = tipo;
    task_ = task;
    numMates_= numMates;
    dropOut = 0.0;
    Goalx = goalx;
    Goaly = goaly;
    
    p = new RobotNaviFun(id_, task_);
    misc = new Miscelaneo(id_);
    
    corteza_motora_secundaria  = make_shared<CmSec>(id_, tipo_, task_, dropOut, Goalx, Goaly);
    corteza_premotora = make_shared<cp>(id_,p,params,&bandera,task_);

    if(id_==1){
        misc->SpawnEntity("cerebral_carpet","cerebral_carpet",
        "/home/antonio/Robotic-Swarms-main/Robotic-Swarms-main/cognitive_architecture/models/cerebral_carpet/cerebral_carpet.sdf", Goalx, Goaly, 0.015);
    }
    

    MatesFitnessClient = std::make_shared<rclcpp::Node>("Get_mates_fitness_client_"+to_string(id_));
    cout << "Robot " << id << " en linea"<< endl;
}

Robot::~Robot() {}

void Robot::ejecutar() {
    rclcpp::spin(corteza_motora_secundaria);    
}

void Robot::SleepLearning(int elec) {
    switch (elec)
    {
    case 0:
        server = make_shared<srvEvaluateDriver>(0, 0, misc);
        break;
    case 1:
        server = make_shared<srvMultipleGoals>(0, 0, misc);
        break;
    case 2:
        server = make_shared<srvTeamMovement>(0,0, misc);
        break;
    default:
        cerr << "no hay servidor especificado" << endl;
        return;
        break;
    }
    
    thread serverThread([this] {
        rclcpp::spin(server);
    });

    thread cpThread([this] {
        corteza_premotora->ejecutaGenetico();
    });
    
    cpThread.join();
    serverThread.join();
}

void Robot::mirroring() {
    int id_toCopy = 0;
    double best_Fitness = -1.0;
    thread cpThread([this, &id_toCopy, &best_Fitness] {
        for(int i=1; i <= numMates_; i++){
            if(i != id_){
                service = MatesFitnessClient->create_client<arlo_interfaces::srv::GetMatesFitness>("robot"+to_string(i)+"0/service_get_fitness");
                auto request = std::make_shared<arlo_interfaces::srv::GetMatesFitness::Request>();
                auto result_future = service->async_send_request(request);
                if (rclcpp::spin_until_future_complete(MatesFitnessClient, result_future) == rclcpp::FutureReturnCode::SUCCESS) {
                    auto result = result_future.get();
                    if(result->fitness > best_Fitness){
                        best_Fitness = result->fitness;
                        id_toCopy= result -> id;
                    }
                } 
                else cout << "Fallo al llamar al servicio para obtener pesos para imitación." << endl;
            }
            
        }
        cerr << id_toCopy << endl;
        corteza_premotora->Mirroring(id_toCopy);
    });
    cpThread.join();
}

