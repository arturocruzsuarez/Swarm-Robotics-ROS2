#ifndef SISTEMA_LIMBICO_H
#define SISTEMA_LIMBICO_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
// #include "std_msgs/msg/bool.hpp"
#include "arlo_interfaces/msg/estado_arlo.hpp"

class SistemaLimbico : public rclcpp::Node
{
public:
    SistemaLimbico(int i, char tipo);
private:
    void enviarImpulsoMotor();

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_impulso_motor_;
    rclcpp::TimerBase::SharedPtr timer_;
    int identificador;
};

#endif // SISTEMA_LIMBICO_H

// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto nodo = std::make_shared<SistemaLimbico>(1, 'A'); 
//     rclcpp::spin(nodo);
//     rclcpp::shutdown();
//     return 0;
// }
