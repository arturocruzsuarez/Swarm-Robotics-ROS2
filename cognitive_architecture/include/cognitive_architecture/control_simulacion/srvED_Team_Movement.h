#ifndef SRV_ED_TEAM_MOVEMENT_
#define SRV_ED_TEAM_MOVEMENT_


#include "srvEvaluateDriver.h"
#include "std_msgs/msg/float64_multi_array.hpp"

class srvTeamMovement: public srvEvaluateDriver
{
public:

    srvTeamMovement(double x, double y, Miscelaneo * misc_);
    virtual ~srvTeamMovement();
    
    bool evaluateDriver(const std::shared_ptr<arlo_interfaces::srv::EvaluateDriver::Request> request,
                        const std::shared_ptr<arlo_interfaces::srv::EvaluateDriver::Response> response);

    SimulationState startSimulation(int maxtime);
    void checkModelPosition(const arlo_interfaces::msg::EstadoArlo &msg);

    void dist_to_mates(double current_dist_to_mates);
    //void checkSimulationTime(const rosgraph_msgs::msg::Clock &msg);



private:

    int timerWIndow=1;
    random_device rd;  // Semilla aleatoria
    mt19937 gen; // Generador Mersenne Twister
    uniform_int_distribution<> uniform_dist;
    double dis2mates;


    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr UpdateGoal;
};

#endif