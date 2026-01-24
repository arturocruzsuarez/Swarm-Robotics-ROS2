#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "cognitive_architecture/modulos_cerebrales/corteza_premotora.hpp"
#include "cognitive_architecture/modulos_cerebrales/corteza_motora_secundaria.hpp"
#include "cognitive_architecture/control_simulacion/srvEvaluateDriver.hpp"
#include "cognitive_architecture/control_simulacion/srvED_Multiple_Goals.hpp"
#include "cognitive_architecture/control_simulacion/srvED_Team_Movement.hpp"
#include "arlo_interfaces/srv/get_mates_fitness.hpp"
#include "cognitive_architecture/miscelaneo.hpp"
#include "rclcpp/rclcpp.hpp"
#include <thread>

using namespace std;

class Robot {

public:
    Robot(int i, char tipo, int task, int numMates, double goalx, double goaly);
    ~Robot();

    void ejecutar();
    void SleepLearning(int elec);

    void mirroring();

private:

    //rclcpp::Node::SharedPtr corteza_premotora;
    shared_ptr<cp> corteza_premotora;
    rclcpp::Node::SharedPtr corteza_motora_secundaria;
    rclcpp::Node::SharedPtr server;

    rclcpp::Node::SharedPtr MatesFitnessClient;
    rclcpp::Client<arlo_interfaces::srv::GetMatesFitness>::SharedPtr service;

    int id_;
    char tipo_;
    int task_;
    int numMates_;
    double Goalx, Goaly;
    RobotNaviFun* p;
    Miscelaneo *misc;
    ParamsGA params;
    bool bandera=true;
    double dropOut; 
};

#endif // ROBOT_H