#ifndef MISCELANEO_H
#define MISCELANEO_H

#include <iostream>
#include <string>
#include <fstream>
#include "rclcpp/rclcpp.hpp"
#include "gazebo_msgs/srv/spawn_entity.hpp"
#include "gazebo_msgs/srv/delete_entity.hpp"
#include <std_srvs/srv/empty.hpp>


using namespace std;

class Miscelaneo {

public:
    Miscelaneo(int id);
    ~Miscelaneo();

    void SpawnEntity(string name, string NameSpace, string filem, double x, double y, double z);
    void SetEntityState(double x, double y, double z, string EntityName, string file_path);    
    void restartSimulation();

private:
    int id_;
    rclcpp::Node::SharedPtr EntityManagerNode;
    rclcpp::Client<gazebo_msgs::srv::SpawnEntity>::SharedPtr EntitySpawnClient;
    rclcpp::Client<gazebo_msgs::srv::DeleteEntity>::SharedPtr EntitySetClient;

    rclcpp::Node::SharedPtr clientGz; 
    rclcpp::Client<std_srvs::srv::Empty>::SharedPtr reset_simulation_client_;

};

#endif 