#include "talamo.h"

using std::placeholders::_1;

Talamo::Talamo(int i, char tipo)
    : Node("talamo_" + std::to_string(i) + tipo),
      identificador(i)
{
    // Publicador para enviar información procesada
    // publicador_info_procesada_ = this->create_publisher<std_msgs::msg::String>(
    //"robot" + std::to_string(i) + tipo + "/info_procesada", 10);

    // Suscriptor para recibir el estado del robot
    suscriptor_estado_ = this->create_subscription<arlo_interfaces::msg::EstadoArlo>(
        "robot" + std::to_string(i) + tipo + "/lobulo_temporal", 10,
        std::bind(&Talamo::estado_callback, this, _1));
}

void Talamo::estado_callback(const arlo_interfaces::msg::EstadoArlo &msg)
{
    // Procesar el mensaje recibido del estado del robot
    // std::string info_procesada = "Procesamiento del estado: ";

    // Concatenar datos del mensaje
    info_procesada += "Rango Sensor1: " + std::to_string(msg.sensor1.ranges[0]);
    info_procesada += ", Rango Sensor2: " + std::to_string(msg.sensor2.ranges[0]);

    // Crear y publicar el mensaje procesado
    auto mensaje_procesado = std_msgs::msg::String();
    mensaje_procesado.data = info_procesada;

    publicador_info_procesada_->publish(mensaje_procesado);
    RCLCPP_INFO(this->get_logger(), "Información procesada enviada: %s", mensaje_procesado.data.c_str());
}

// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto nodo = std::make_shared<Talamo>(1, 'A');
//     rclcpp::spin(nodo);
//     rclcpp::shutdown();
//     return 0;
// }
