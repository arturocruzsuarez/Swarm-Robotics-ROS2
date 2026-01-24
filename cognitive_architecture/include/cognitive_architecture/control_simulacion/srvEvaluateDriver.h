
#ifndef SRC_SIMULATIONCONTROLLER_H_
#define SRC_SIMULATIONCONTROLLER_H_


#include <rclcpp/rclcpp.hpp>
#include <utility>
#include <vector>
#include <random>
#include "SimulationState.h"
#include "arlo_interfaces/srv/evaluate_driver.hpp"
#include "rosgraph_msgs/msg/clock.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int64.hpp"
#include "arlo_interfaces/msg/estado_arlo.hpp"
#include "cognitive_architecture/miscelaneo.h"


using namespace std;

class srvEvaluateDriver: public rclcpp::Node {
public:

    srvEvaluateDriver(double x, double y, Miscelaneo * misc_);
	virtual ~srvEvaluateDriver();
    SimulationState startSimulation(int maxtime);
    virtual bool evaluateDriver(const std::shared_ptr<arlo_interfaces::srv::EvaluateDriver::Request> request,
                        const std::shared_ptr<arlo_interfaces::srv::EvaluateDriver::Response> response);

    virtual void checkSimulationTime(const rosgraph_msgs::msg::Clock &msg);
    
    void checkModelPosition(const arlo_interfaces::msg::EstadoArlo &msg);
    

protected:
    double dist2Go(double x, double y);
    //void dist_to_mates(double x);
    double distance(double x1, double y1, double x2, double y2);
    //void ejecutaSystem(const std::string& comando); 
    //void IgnoreSetter()

    SimulationState arloState;
    double maxSimTime;  /* Maximum time allowed for the robot to get the goal */
    double goalDistance;
    double prev_x, prev_y;
    long double num_check; //numero de chequeos de odom;
    long int stuckCounter;
    bool stuck;
    int ignoreFlag;
    double x_start, y_start;
    pair<double, double> current_goal_xy;
    // const vector<pair<double, double>> GoalsCoordenates ={{0.0,0.0},{-5,5},{7,7},{9,0},{5,3},{3,7},{3,6}};
    // int goalsUnreached=GoalsCoordenates.size();
    // random_device rd;  // Semilla aleatoria
    // mt19937 gen; // Generador Mersenne Twister
    // uniform_int_distribution<> uniform_dist;

    Miscelaneo *misc;


    rclcpp::Service<arlo_interfaces::srv::EvaluateDriver>::SharedPtr service_;
    rclcpp::Node::SharedPtr  nodoClock;
    rclcpp::Subscription<rosgraph_msgs::msg::Clock>::SharedPtr clockSus;
    rclcpp::Node::SharedPtr nodoOdom;
    rclcpp::Subscription<arlo_interfaces::msg::EstadoArlo>::SharedPtr OdomSus;
    rclcpp::executors::SingleThreadedExecutor::SharedPtr executor;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_pesos_eval;
    // rclcpp::Node::SharedPtr clientg; 
    // rclcpp::Client<std_srvs::srv::Empty>::SharedPtr reset_simulation_client_;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr ignoreSetter;
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr ignoreGetter;

};

#endif