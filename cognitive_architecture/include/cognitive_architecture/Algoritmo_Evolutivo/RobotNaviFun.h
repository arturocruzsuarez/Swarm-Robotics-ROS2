#ifndef ROBOTNAVIFUN_H
#define ROBOTNAVIFUN_H

#include "ProblemaOptim.h"
#include <rclcpp/rclcpp.hpp>
#include "arlo_interfaces/srv/evaluate_driver.hpp"
/*
Definición de la clase que modela la evaluación de un vector de pesos para
el controlador del robot.
La clase de debe derivar de la clase base ProblemaOptim.
*/

using namespace std;
static   map<int, vector<int>> task_map_ = {
        {1, {98,2}},   // 1.- Desplazamiento individula
        {2, {99,2}}    // 2.- Desplazamiento en grupo
    };

class RobotNaviFun : public ProblemaOptim {
public:
   RobotNaviFun(int id, int task, int maxSimTime = 50, double touchThreshold = 1);
   virtual ~RobotNaviFun();

   void evaluateFun(vector<double> const &x, double &fun, vector<double> &cons) const;

private:
   int numInputsNN;  // Number of inputs of the neural network.
   int numOutputsNN; // Number of outputs of the neural network.
   int numHidden;    // Number of hidden nodes of the neural network.
   int Task;
   int Id;         
   int maxSimTime;
   double touchThreshold;
   string popFilePattern;  // Archivo de pesos para comunicación con el simulador.

   rclcpp::Node::SharedPtr client;
   rclcpp::Client<arlo_interfaces::srv::EvaluateDriver>::SharedPtr service;

   void writeWeightsFile(vector<double> const &weights, int id=1) const;
};


#endif
