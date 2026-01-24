#ifndef TALAMO_H
#define TALAMO_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "arlo_interfaces/msg/estado_arlo.hpp"


class Talamo : public rclcpp::Node{
public:
    Talamo(int i, char tipo);
    virtual ~Talamo();

private:
    void estado_callback(const arlo_interfaces::msg::EstadoArlo &msg);

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publicador_info_procesada_;
    rclcpp::Subscription<arlo_interfaces::msg::EstadoArlo>::SharedPtr suscriptor_estado_;
    int identificador;
};

#endif // TALAMO_H
