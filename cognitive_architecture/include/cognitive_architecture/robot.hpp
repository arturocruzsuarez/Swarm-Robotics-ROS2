#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "robot.h"
#include "rclcpp/rclcpp.hpp"
#include <string>
#include <memory>
#include <thread>
#include <vector>

using namespace std;

// Constructor: Gestiona la creación del cerebro y el cuerpo físico en Gazebo
Robot::Robot(int id, char tipo, int task, int numMates, double goalx, double goaly) {
    id_ = id;
    tipo_ = tipo;
    task_ = task;
    numMates_ = numMates;
    dropOut = 0.0;
    Goalx = goalx;
    Goaly = goaly;
    bandera = false;
    
    string base_name = "robot" + to_string(id_);
    
    // 1. Inicialización de componentes internos (Cerebro)
    p = new RobotNaviFun(id_, task_);
    misc = new Miscelaneo(id_);
    
    corteza_motora_secundaria = make_shared<CmSec>(id_, tipo_, task_, dropOut, Goalx, Goaly);
    corteza_premotora = make_shared<cp>(id_, p, params, &bandera, task_);

    // 2. LÓGICA DE SPAWN FÍSICO (Para que aparezcan los 3 en Gazebo)
    // Ruta al modelo Arlo detectada en tus logs locales
    string arlo_model = "/home/antonio/Robotic-Swarms-main/Robotic-Swarms-main/cognitive_architecture/models/arlo/model.sdf";
    
    // Calculamos una posición X diferente para cada robot (separados por 2 metros)
    // Robot 1 -> x=0, Robot 2 -> x=2, Robot 3 -> x=4
    double pos_x_reparto = (id_ - 1) * 2.0; 

    // Comando para que aparezca el cuerpo del robot en la arena
    misc->SpawnEntity(base_name, base_name, arlo_model, pos_x_reparto, 0.0, 0.1);

    // 3. Generación de la Alfombra Cerebral (Solo el Líder)
    if(id_ == 1){
        RCLCPP_INFO(rclcpp::get_logger("robot_main"), "Robot Líder: Generando alfombra cerebral...");
        misc->SpawnEntity("cerebral_carpet", "cerebral_carpet", 
            "/home/antonio/Robotic-Swarms-main/Robotic-Swarms-main/cognitive_architecture/models/cerebral_carpet/cerebral_carpet.sdf", 
            Goalx, Goaly, 0.015);
    }

    MatesFitnessClient = std::make_shared<rclcpp::Node>(base_name + "_fitness_client");
    cout << ">>> Robot " << id_ << " sincronizado y en línea." << endl;
}

// Destructor: Limpieza de punteros para evitar fugas de memoria
Robot::~Robot() {
    if (p) delete p;
    if (misc) delete misc;
}

void Robot::ejecutar() {
    // Mantiene viva la escucha de la red neuronal
    rclcpp::spin(corteza_motora_secundaria);    
}

void Robot::SleepLearning(int elec) {
    switch (elec) {
        case 0: server = make_shared<srvEvaluateDriver>(0, 0, misc); break;
        case 1: server = make_shared<srvMultipleGoals>(0, 0, misc); break;
        case 2: server = make_shared<srvTeamMovement>(0, 0, misc); break;
        default:
            cerr << "Error: Servidor no especificado." << endl;
            return;
    }
    
    RCLCPP_INFO(rclcpp::get_logger("robot_main"), "Robot %d: Iniciando SleepLearning modo %d", id_, elec);

    thread serverThread([this] { rclcpp::spin(server); });
    thread cpThread([this] { corteza_premotora->ejecutaGenetico(); });
    
    cpThread.join();
    serverThread.join();
}

void Robot::mirroring() {
    int id_toCopy = 0;
    double best_Fitness = -1.0;

    // Hilo para el escaneo de fitness del enjambre
    thread cpThread([this, &id_toCopy, &best_Fitness] {
        RCLCPP_INFO(MatesFitnessClient->get_logger(), "Robot %d: Escaneando enjambre...", id_);

        for(int i = 1; i <= numMates_; i++){
            if(i != id_){
                string target_service = "robot" + to_string(i) + "/service_get_fitness";
                service = MatesFitnessClient->create_client<arlo_interfaces::srv::GetMatesFitness>(target_service);
                
                if (!service->wait_for_service(std::chrono::milliseconds(500))) continue;

                auto request = std::make_shared<arlo_interfaces::srv::GetMatesFitness::Request>();
                auto result_future = service->async_send_request(request);

                if (rclcpp::spin_until_future_complete(MatesFitnessClient, result_future) == rclcpp::FutureReturnCode::SUCCESS) {
                    auto result = result_future.get();
                    if(result->fitness > best_Fitness){
                        best_Fitness = result->fitness;
                        id_toCopy = result->id;
                    }
                } 
            }
        }

        if(id_toCopy != 0) {
            RCLCPP_INFO(MatesFitnessClient->get_logger(), "Robot %d: Imitando al líder (Robot %d)", id_, id_toCopy);
            corteza_premotora->Mirroring(id_toCopy);
        } else {
            RCLCPP_WARN(MatesFitnessClient->get_logger(), "Robot %d: No hay mejor compañero disponible.", id_);
        }
    });

    cpThread.join();
}

#endif
