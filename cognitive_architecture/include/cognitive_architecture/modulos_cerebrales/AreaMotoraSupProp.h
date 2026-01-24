#ifndef AREA_MOTORA_SUP_PROP_H
#define AREA_MOTORA_SUP_PROP_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
// #include "arlo_interfaces/msg/estado_arlo.hpp"

class AreaMotoraSupProp: public rclcpp::Node
{
public:
    AreaMotoraSupProp(int i, char tipo);

private:
    void enviarImpulsoMotor();

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_impulso_motor_;
    rclcpp::TimerBase::SharedPtr timer_;
    int identificador;
};
#endif // AREA_MOTORA_SUP_PROP_H
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto nodo = std::make_shared<AreaMotoraSupProp>(1, 'A');
//     rclcpp::spin(nodo);
//     rclcpp::shutdown();
//     return 0;
// }
