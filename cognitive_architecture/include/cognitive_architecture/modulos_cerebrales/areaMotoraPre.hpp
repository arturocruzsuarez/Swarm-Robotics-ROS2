#include "areaMotoraPre.h"

using std::placeholders::_1;


    areaMotoraPre::areaMotoraPre(int i, char tipo)
        : Node("area_motora_pre_" + std::to_string(i) + tipo), 
          identificador(i)
    {
        // Suscriptor para recibir la información de Talamo
        suscriptor_info_procesada_ = this->create_subscription<std_msgs::msg::String>(
            "robot" + std::to_string(i) + tipo + "/info_procesada", 10, 
            std::bind(&areaMotoraPre::info_callback, this, _1));

        // Suscriptor para recibir el impulso motor del sistema límbico
        suscriptor_impulso_motor_ = this->create_subscription<std_msgs::msg::String>(
            "robot" + std::to_string(i) + tipo + "/impulso_motor", 10,
            std::bind(&areaMotoraPre::impulso_callback, this, _1));
    }


    void areaMotoraPre::info_callback(const std_msgs::msg::String &msg)
    {
        // Mostrar el mensaje del Talamo
        RCLCPP_INFO(this->get_logger(), "Mensaje recibido del nodo Talamo: %s", msg.data.c_str());
    }

    void areaMotoraPre::impulso_callback(const std_msgs::msg::String &msg)
    {
        // Mostrar el mensaje del sistema límbico
        RCLCPP_INFO(this->get_logger(), "Impulso motor recibido del sistema límbico: %s", msg.data.c_str());
    }


// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto nodo = std::make_shared<areaMotoraPre>(1, 'A'); 
//     rclcpp::spin(nodo);
//     rclcpp::shutdown();
//     return 0;
// }
