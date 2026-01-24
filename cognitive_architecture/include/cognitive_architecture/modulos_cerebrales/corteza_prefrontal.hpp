#include "correza_prefrontal.h"

using std::placeholders::_1;

CortezaPrefrontal::CortezaPrefrontal(int i, char tipo)
    : Node("corteza_prefrontal_" + std::to_string(i) + tipo),
      identificador(i), movimiento_permitido(true)
{
    // Publicador para enviar decisiones a la corteza premotora
    publisher_decision_ = this->create_publisher<std_msgs::msg::String>(
        "robot" + std::to_string(i) + tipo + "/corteza_premotora_evolutivo", 10);

    // Publicador para enviar la señal de supresión voluntaria del movimiento
    publisher_control_ = this->create_publisher<std_msgs::msg::Bool>(
        "robot" + std::to_string(i) + tipo + "/control_movimiento", 10);

    // Suscriptor para recibir el estado del robot
    subscription_estado_ = this->create_subscription<arlo_interfaces::msg::EstadoArlo>(
        "robot" + std::to_string(i) + tipo + "/temporal_lobe_", 10,
        std::bind(&CortezaPrefrontal::estado_callback, this, _1));

    // Timer para evaluar periódicamente si se debe suprimir el movimiento
    timer_ = this->create_wall_timer(
        std::chrono::seconds(1), // Evalúa la supresión cada segundo (ajusta según necesidad)
        std::bind(&CortezaPrefrontal::evaluarSupresion, this));
}

void CortezaPrefrontal::estado_callback(const arlo_interfaces::msg::EstadoArlo &msg)
{
    if (!movimiento_permitido)
    {
        RCLCPP_INFO(this->get_logger(), "Movimiento suprimido, no se enviarán comandos.");
        return; // Si el movimiento no está permitido, no envía decisiones
    }

    // Procesar el mensaje recibido y verificar los sensores
    bool detener_robot = (msg.sensor1.ranges[0] < 0.5 && msg.sensor2.ranges[0] < 0.5 && msg.sensor3.ranges[0] < 0.5) || (msg.sensor4.ranges[0] < 0.5);

    std_msgs::msg::String decision_msg;

    if (detener_robot)
    {
        decision_msg.data = "Detener robot - Objeto detectado en sensores";
    }
    else
    {
        // Generar movimiento aleatorio
        int movimiento = rand() % 4; // Genera un número aleatorio entre 0 y 3
        switch (movimiento)
        {
        case 0:
            decision_msg.data = "Mover hacia adelante";
            break;
        case 1:
            decision_msg.data = "Mover hacia atrás";
            break;
        case 2:
            decision_msg.data = "Girar a la izquierda";
            break;
        case 3:
            decision_msg.data = "Girar a la derecha";
            break;
        }
    }

    // Publicar la decisión a la corteza premotora
    publisher_decision_->publish(decision_msg);
    RCLCPP_INFO(this->get_logger(), "Decisión enviada a la corteza premotora: %s", decision_msg.data.c_str());
}

void CortezaPrefrontal::evaluarSupresion()
{
    // Aquí defines la lógica para decidir si se debe suprimir el movimiento
    bool condicion_supresion = false; // Define tu lógica específica aquí

    // Publicar la señal de supresión voluntaria
    std_msgs::msg::Bool control_msg;
    control_msg.data = !condicion_supresion; // true = movimiento permitido, false = movimiento suprimido
    publisher_control_->publish(control_msg);

    RCLCPP_INFO(this->get_logger(), "Señal de supresión enviada: %s",
                control_msg.data ? "Movimiento Permitido" : "Movimiento Suprimido");

    // Actualiza el estado interno
    movimiento_permitido = control_msg.data;
}

// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto node = std::make_shared<CortezaPrefrontal>(1, 'A');  // Ajusta los parámetros según sea necesario
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }
