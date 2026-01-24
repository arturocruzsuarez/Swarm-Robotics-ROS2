#ifndef CORTEZA_PREMOTORA_H
#define CORTEZA_PREMOTORA_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int64.hpp"
#include <string>
#include <memory>
#include <thread>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <sys/stat.h>

#include "cognitive_architecture/Algoritmo_Evolutivo/GeneticoSimple.hpp"
#include "std_srvs/srv/empty.hpp"
#include "cognitive_architecture/Algoritmo_Evolutivo/RobotNaviFun.hpp"

#include "arlo_interfaces/msg/pesos_struct.hpp"
#include "arlo_interfaces/srv/get_important_weights.hpp"

using namespace std;

class cp : public rclcpp::Node{
public:
    cp(int i, RobotNaviFun *p, ParamsGA params, bool *bandera, int task);
    virtual ~cp();
    void ejecutaGenetico();
    void resetGazebo() const;
    void Mirroring(int i);
    void combineWeights(const std::string &newWeightsFile); 
    
private:
    

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; // Publicador para enviar los pesos óptimos
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisherMates;
    rclcpp::Subscription<arlo_interfaces::msg::PesosStruct>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_; // Temporizador para ejecutar la optimización periódicamente
    rclcpp::Client<std_srvs::srv::Empty>::SharedPtr reset_simulation_client_;
    rclcpp::Client<arlo_interfaces::srv::GetImportantWeights>::SharedPtr client_getWeights;
    bool *flag;
    GeneticoSimple genetico;
    int identificador;
    int task;
    std::string inputDir;
};

#endif // CORTEZA_PREMOTORA_H