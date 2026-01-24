#ifndef SRV_ED_MULTIPLE_GOALS_
#define SRV_ED_MULTIPLE_GOALS_


#include "srvEvaluateDriver.h"
#include "std_msgs/msg/float64_multi_array.hpp"

class srvMultipleGoals: public srvEvaluateDriver
{
public:

    srvMultipleGoals(double x, double y, Miscelaneo * misc_);
    virtual ~srvMultipleGoals();
    
    bool evaluateDriver(const std::shared_ptr<arlo_interfaces::srv::EvaluateDriver::Request> request,
                        const std::shared_ptr<arlo_interfaces::srv::EvaluateDriver::Response> response);

    SimulationState startSimulation(int maxtime);
    void checkSimulationTime(const rosgraph_msgs::msg::Clock &msg);


private:

    const vector<pair<double, double>> GoalsCoordenates ={{0.0,0.0},{-5,5},{7,7},{9,0},{5,3},{3,7},{3,6}};
    int goals_2_reach=GoalsCoordenates.size();
    int timerWIndow=1;
    random_device rd;  // Semilla aleatoria
    mt19937 gen; // Generador Mersenne Twister
    uniform_int_distribution<> uniform_dist;


    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr UpdateGoal;
};

#endif