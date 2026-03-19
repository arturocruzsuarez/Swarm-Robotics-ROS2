#include "corteza_premotora.h"

using std::placeholders::_1;

// CP: Corteza Premotora - Se encarga de la optimización y el protocolo de imitación.

cp::cp(int i, RobotNaviFun *p, ParamsGA params, bool *bandera, int task) : 
                    Node("robot" + std::to_string(i) + "_premotora"), // Identidad limpia
                    identificador(i), 
                    genetico(p, params, i, task), 
                    flag(bandera), 
                    task(task)
{
    // Nombre base para todos los tópicos del robot
    string base_name = "robot" + std::to_string(i);
    
    inputDir = "./archivo_pesos_" + std::to_string(identificador) + ".txt";

    // Cliente para resetear el mundo en Gazebo
    reset_simulation_client_ = this->create_client<std_srvs::srv::Empty>("/reset_world");

    // Publicador de pesos (Ahora apunta al tópico correcto sin el "0" extra)
    publisher_ = this->create_publisher<std_msgs::msg::String>(base_name + "/corteza_premotora_pesos", 10);

    if (task == 2)
    { 
        publisherMates = this->create_publisher<std_msgs::msg::Int64>(base_name + "/redefineMates", 10);
        auto actualizaMates = std_msgs::msg::Int64();
        actualizaMates.data = 1;
        publisherMates->publish(actualizaMates);
    }

    RCLCPP_INFO(this->get_logger(), "Corteza Premotora del Robot %d inicializada.", identificador);
}

cp::~cp() {}

void cp::resetGazebo() const
{
    auto request = std::make_shared<std_srvs::srv::Empty::Request>();
    auto response = reset_simulation_client_->async_send_request(request);
}

void cp::ejecutaGenetico()
{
    genetico.optimizar();
    auto mensajePesos = std_msgs::msg::String();
    char buffer[100];
    std::sprintf(buffer, "./archivo_pesos_%d_%d.txt", identificador, task);
    mensajePesos.data = std::string(buffer);

    publisher_->publish(mensajePesos);
    *flag = false;
}

void cp::Mirroring(int i)
{
    // target_robot será "robot1", "robot2", etc.
    string target_robot = "robot" + to_string(i);
    RCLCPP_INFO(this->get_logger(), "Buscando pesos del %s para imitación...", target_robot.c_str());

    // Buscamos el servicio en el robot objetivo (target_robot)
    client_getWeights = this->create_client<arlo_interfaces::srv::GetImportantWeights>(target_robot + "/service_importantWeights");
    
    if (!client_getWeights->wait_for_service(chrono::seconds(2))) {
        RCLCPP_ERROR(this->get_logger(), "El %s no respondió. ¿Está encendido?", target_robot.c_str());
        return;
    }

    auto request = std::make_shared<arlo_interfaces::srv::GetImportantWeights::Request>();
    auto response = client_getWeights->async_send_request(request);
    
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), response) == rclcpp::FutureReturnCode::SUCCESS) {
        auto result = response.get();
        auto mensajePesos = std_msgs::msg::String(); 
        mensajePesos.data = result->weightsfile;
        
        // Informamos a nuestra propia Corteza Motora de los nuevos pesos
        publisher_->publish(mensajePesos);
        RCLCPP_INFO(this->get_logger(), "¡Imitación completada! Usando pesos de %s", target_robot.c_str());

    } else {
        RCLCPP_ERROR(this->get_logger(), "Error en la comunicación de imitación.");
    }
}
