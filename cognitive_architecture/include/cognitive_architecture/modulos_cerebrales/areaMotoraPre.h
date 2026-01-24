#ifndef AREA_MOTORA_PRE_H
#define AREA_MOTORA_PRE_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class areaMotoraPre : public rclcpp::Node
{
public:
    areaMotoraPre(int i, char tipo);

private:
    void info_callback(const std_msgs::msg::String &msg);

    void impulso_callback(const std_msgs::msg::String &msg);

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr suscriptor_info_procesada_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr suscriptor_impulso_motor_;
    int identificador;
};

#endif // AREA_MOTORA_PRE_H
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto nodo = std::make_shared<areaMotoraPre>(1, 'A'); 
//     rclcpp::spin(nodo);
//     rclcpp::shutdown();
//     return 0;
// }
