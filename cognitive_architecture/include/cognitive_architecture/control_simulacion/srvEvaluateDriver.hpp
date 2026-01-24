#include "SimulationState.hpp"
#include "srvEvaluateDriver.h"
#include <unistd.h>
#include "rclcpp_components/node_factory.hpp"

srvEvaluateDriver::srvEvaluateDriver(double x, double y, Miscelaneo * misc_) : Node("servidor_simulacion_basico")// hay que agregar el id del robot que le corresponda
{
    rclcpp::QoS qos_profile(1);
    // Cambiar la política de confiabilidad a 'Best Effort'
    qos_profile.reliability(rmw_qos_reliability_policy_t::RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);

    service_ = this->create_service<arlo_interfaces::srv::EvaluateDriver>("evaluate_driver",
                                                                          bind(&srvEvaluateDriver::evaluateDriver, this, placeholders::_1, placeholders::_2));

    nodoClock = std::make_shared<rclcpp::Node>("suscriptor_clock");

    clockSus = nodoClock->create_subscription<rosgraph_msgs::msg::Clock>("/clock",
                                                                         qos_profile, bind(&srvEvaluateDriver::checkSimulationTime, this, placeholders::_1));

    nodoOdom = std::make_shared<rclcpp::Node>("suscriptor_Odom");

    OdomSus = nodoOdom->create_subscription<arlo_interfaces::msg::EstadoArlo>("robot10/temporal_lobe_",
                                                                              qos_profile, bind(&srvEvaluateDriver::checkModelPosition, this, placeholders::_1));

    executor = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();

    publisher_pesos_eval = this->create_publisher<std_msgs::msg::String>("robot10/corteza_premotora_pesos", 10);

    ignoreSetter = this->create_publisher<std_msgs::msg::Int64>("robot10/ignoreFlag", 10);

    // ignoreGetter = this->create_subscription<std_msgs::msg::Int64>("/robot10/ignoreFlag",
    //             qos_profile, bind(&srvEvaluateDriver::IgnoreSetter, this, placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Servidor básico listo para recibir solicitudes.");


    prev_x = 0;
    prev_y = 0;
    stuck = false;
    stuckCounter = 0;
    num_check = 0;
    x_start = -6.6;
    y_start = -13.6;
    misc=misc_;
    current_goal_xy.first=x; 
    current_goal_xy.second=y;
}

srvEvaluateDriver::~srvEvaluateDriver()
{
}

bool srvEvaluateDriver::evaluateDriver(const shared_ptr<arlo_interfaces::srv::EvaluateDriver::Request> request,
                                       const shared_ptr<arlo_interfaces::srv::EvaluateDriver::Response> response)
{
    // arloState.resetState();
    auto flag = std_msgs::msg::Int64();
    flag.data = 1;
    ignoreSetter->publish(flag);

    string pesos = request->weightsfile;
    auto mensaje = std_msgs::msg::String();
    mensaje.data = pesos;
    publisher_pesos_eval->publish(mensaje);

    misc->restartSimulation();

    while ((arloState.position[0] > x_start) || (arloState.position[1] > y_start))
    {
        executor->spin_node_once(nodoOdom);
        RCLCPP_INFO(this->get_logger(), "Esperando a que los datos estén bien");
        cerr << arloState.position[0] << arloState.position[1] << endl;
    }

    flag.data = 0;
    ignoreSetter->publish(flag);

    startSimulation(request->maxtime);

    response->time = arloState.finishTime;
    response->dist2go = arloState.distanceToGo;
    response->damage = arloState.robotDamage;
    response->energy = arloState.distanceTravelled;
    response->dist2mates = arloState.dist_to_mates;

    return true;
}

SimulationState srvEvaluateDriver::startSimulation(int maxtime)
{

    puts("Starting the simulation of a new driver...");
    puts("---------------------------");

    arloState.resetState();
    double fx = 0;
    maxSimTime = maxtime;
    num_check = 0;

    stuckCounter = 0;

        while (rclcpp::ok() && !arloState.hasTimeRunOut && !arloState.finishLineCrossed)
        {
            executor->spin_node_once(nodoClock);
            executor->spin_node_once(nodoOdom);
        }

        cout << "hasTimeRunOut= " << arloState.hasTimeRunOut << "\n";
        cout << "finishLineCrossed= " << arloState.finishLineCrossed << "\n";

        if (arloState.hasTimeRunOut == true)
        {
            arloState.finishTime = 2 * maxSimTime;
            // arloState.distanceToGo = goalDistance - arloState.currentPosition;
            cout << "currentPosition= " << arloState.currentPosition << "\n";
            if (arloState.stuck == true)
            {
                cout << " ---->>> ATASCADO  <<<-----" << endl;
                cout << " \t Counter = " << stuckCounter << endl;
            }

            fx = maxSimTime + arloState.distanceToGo + arloState.dist_to_mates;
        }
        else
        { // The robot reached the goal.
            arloState.finishTime = arloState.currentTime;

            // if(arloState.finishTime < 5){
            //     cerr << "este tiempo está mal. va de nuevo" << endl;
            //     startSimulation(maxSimTime);
            //     return arloState;
            // }

            arloState.distanceToGo = 0.0;
            arloState.robotEnergy = 100;
            cout << "finishTime = " << arloState.finishTime << "\n" << endl;
            fx = arloState.finishTime + arloState.dist_to_mates;
        }

    cout << "x = " << arloState.position[0] << ", y = " << arloState.position[1] << endl;
    cout << "d2Go = " << arloState.distanceToGo << endl;
    cout << "gas = " << arloState.distanceTravelled << endl;
    cout << "dist_to_mates = " << arloState.dist_to_mates << endl;
    cout << "fx = " << fx << endl;

    cout << "Bye." << endl;

    return arloState;
}

double srvEvaluateDriver::dist2Go(double x, double y)
{
    double distToGo = 0.0;
    //.  Si es la diana CEREBRAL
    double xTarget = current_goal_xy.first;
    double yTarget = current_goal_xy.second;
    distToGo = distance(xTarget, yTarget, x, y);

    return distToGo;
}

double srvEvaluateDriver::distance(double x1, double y1, double x2, double y2)
{
    double sum = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrt(sum);
}


void srvEvaluateDriver::checkModelPosition(const arlo_interfaces::msg::EstadoArlo &msg)
{
    // ROS_INFO("Seq: [%d]", msg->header.seq);
    // ROS_INFO("Position-> x: [%f]", msg->pose.pose.position.x);
    // ROS_INFO("Vel-> Linear: [%f], Angular: [%f]",
    //		msg->twist.twist.linear.x,
    //		msg->twist.twist.angular.z);

    // arloState.currentPosition = msg->pose.pose.position.x;
    // if (arloState.currentPosition >= goalDistance)   // Esta es la distancia del pasillo en Gazebo.
    // 	arloState.finishLineCrossed = true;

    double distanceBefore = arloState.distanceTravelled;
    arloState.distanceTravelled += distance(prev_x, prev_y, msg.odom.pose.pose.position.x, msg.odom.pose.pose.position.y);

    if (abs(distanceBefore - arloState.distanceTravelled) < 0.01)
    {
        stuckCounter++;
        // cout << "Stuck counter: " << stuckCounter << "\n";
        if (stuckCounter > 20)
        {
            arloState.stuck = true;
            arloState.hasTimeRunOut = true;
        }
    }
    else
        stuckCounter = 0;

    prev_x = msg.odom.pose.pose.position.x;
    prev_y = msg.odom.pose.pose.position.y;

    arloState.currentPosition = msg.odom.pose.pose.position.x;
    arloState.position[0] = msg.odom.pose.pose.position.x;
    arloState.position[1] = msg.odom.pose.pose.position.y;
    // cerr << "x: " << arloState.position[0] << " y: " << arloState.position[1] << endl;
    // double d2go = dist2Go(msg.odom.pose.pose.position.x, msg.odom.pose.pose.position.y);
    arloState.distanceToGo = dist2Go(msg.odom.pose.pose.position.x, msg.odom.pose.pose.position.y);

    //if (Task == 1)
    arloState.dist_to_mates = 0.0;
    //else dist_to_mates(msg.dist_to_mates);

    if (arloState.distanceToGo <= 1.0) arloState.finishLineCrossed = true;
}

void srvEvaluateDriver::checkSimulationTime(const rosgraph_msgs::msg::Clock &msg)
{
    arloState.currentTime = msg.clock.sec;

    if (arloState.currentTime >= maxSimTime) arloState.hasTimeRunOut = true;
}

// void srvEvaluateDriver::IgnoreSetter(const std_msgs::msg::Int64::SharedPtr msg){
//     ignoreFlag = msg->data;
// }

// int srvEvaluateDriver::getNumSensors() {
// 	return NUM_RAYS * NUM_SONARS;
// }

// int srvEvaluateDriver::getNumActuators() {
// 	return NUM_ACTUATORS;
// }
// rclcpp::Service<arlo_interfaces::srv::EvaluateDriver>::SharedPtr service_;
