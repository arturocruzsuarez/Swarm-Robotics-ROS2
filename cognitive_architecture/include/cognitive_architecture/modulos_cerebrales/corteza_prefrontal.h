#ifndef CORTEZA_PREFRONTAL_H
#define CORTEZA_PREFRONTAL_H    

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "arlo_interfaces/msg/estado_arlo.hpp"
#include <cstdlib>  

using std::placeholders::_1;

class CortezaPrefrontal : public rclcpp::Node
{
public:
    CortezaPrefrontal(int i, char tipo);
private:
    void estado_callback(const arlo_interfaces::msg::EstadoArlo &msg);

    void evaluarSupresion();

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_decision_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_control_;
    rclcpp::Subscription<arlo_interfaces::msg::EstadoArlo>::SharedPtr subscription_estado_;
    rclcpp::TimerBase::SharedPtr timer_;
    int identificador;
    bool movimiento_permitido;
};
#endif // CORTEZA_PREFRONTAL_H
