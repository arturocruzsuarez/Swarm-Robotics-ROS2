#ifndef CORTEZA_MOTORA_SEC_H
#define CORTEZA_MOTORA_SEC_H


#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include <string>
#include <memory>
#include <thread>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include "cognitive_architecture/Red_Neuronal/NeuroControllerDriver.hpp"
#include <cstdlib> // Necesario para system()
#include <cstdio>
//#include "arlo_interfaces/msg/pesos_struct.hpp"
#include "arlo_interfaces/msg/estado_arlo.hpp"
#include "arlo_interfaces/srv/get_mates_fitness.hpp"
#include <cstring>
#include <sys/stat.h>
#include <map>

using std::placeholders::_1;
using namespace std;

static map<int, vector<int>> task_map = {
    {1, {98, 2}}, // 1.- Desplazamiento individula
    {2, {99, 2}}  // 2.- Desplazamiento en grupo
};


class CmSec : public rclcpp::Node{
public:
    CmSec(int i, char tipo, int task, double dropOut, double xGoal, double yGoal);
    virtual ~CmSec();
    void ejecutaNN(const arlo_interfaces::msg::EstadoArlo &msg);
    void setParameters_evo(const std_msgs::msg::String &msg);
    bool fileExists(string path);
    void genera_pesos(const char *archivo_name);
    bool service_importantWeights(const std::shared_ptr<arlo_interfaces::srv::GetImportantWeights::Request> request,
                                  std::shared_ptr<arlo_interfaces::srv::GetImportantWeights::Response> response);
    
    bool service_send_fitness(const std::shared_ptr<arlo_interfaces::srv::GetMatesFitness::Request> request,
                                  std::shared_ptr<arlo_interfaces::srv::GetMatesFitness::Response> response);

    void setGoalCoordenates(const std_msgs::msg::Float64MultiArray &msg);

private:
   rclcpp::Subscription<arlo_interfaces::msg::EstadoArlo>::SharedPtr subscription_; // aqui se declara al suscriptor
   rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr publisher_NN;
   rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr publisher_;
   rclcpp::Publisher<arlo_interfaces::msg::PesosStruct>::SharedPtr publisher_evo_;
   rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_evo;
   rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr changeGoalSub;
   rclcpp::Service<arlo_interfaces::srv::GetImportantWeights>::SharedPtr service_getWeights;
   rclcpp::Service<arlo_interfaces::srv::GetMatesFitness>::SharedPtr service_sendFitness;

   vector<arlo_interfaces::msg::EstadoArlo> mensajes_recibidos;
   int task;
   int id;
   int tipo;
   double fitness;
   vector<double> entradas;
   int identificador;
   NeuroControllerDriver redNeuronal;
   vector<pair<double, double>> rangos_salidas;
   int banderaGenetico;
   
   double dist_to_go_x;
   double dist_to_go_y;
   double Goalx, Goaly;

   bool flag_success;
   string weightsFile;

};

#endif