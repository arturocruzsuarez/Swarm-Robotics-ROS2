#include "corteza_premotora.h"

using std::placeholders::_1;
// #include "cognitive_architecture/SimulationController.h"

// este nodo contiene el algoritmo evolutivo para los pesos de la red neuronal de la cms

cp::cp(int i, RobotNaviFun *p, ParamsGA params, bool *bandera, int task) : 
                    Node("Corteza_premotora_" + std::to_string(i) + "0"),
                    identificador(i), genetico(p, params, i, task), flag(bandera), task(task)
{
    inputDir = "./archivo_pesos_" + std::to_string(identificador) + ".txt";

    reset_simulation_client_ = this->create_client<std_srvs::srv::Empty>("/reset_world");

    publisher_ = this->create_publisher<std_msgs::msg::String>("robot" + std::to_string(i) + "0/corteza_premotora_pesos", 10);

    if (task == 2)
    { // si la task a evaluar ocupa actualizar el numero de mates
        publisherMates = this->create_publisher<std_msgs::msg::Int64>("robot" + std::to_string(i) + "0/redefineMates", 10);
        auto actualizaMates = std_msgs::msg::Int64();
        actualizaMates.data = 1;
        publisherMates->publish(actualizaMates);
    }
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

    // mensajePesos.data = "archivo_pesos_%d.txt", identificador;
    char buffer[50];
    std::sprintf(buffer, "./archivo_pesos_%d_%d.txt", identificador, task);
    mensajePesos.data = std::string(buffer);

    publisher_->publish(mensajePesos);
    *flag = false;
}

void cp::Mirroring(int i)
{
    cerr << i << endl;
    client_getWeights = this->create_client<arlo_interfaces::srv::GetImportantWeights>("robot"+to_string(i)+"0/service_importantWeights");
    
    while (!client_getWeights->wait_for_service(chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            cout << "Servicio para Mirroing no disponible. Saliendo." << endl;
            return;
        }
        cout << "Servicio para Mirroing no disponible. Intentando nuevamente..." << endl;
    }

    auto request = std::make_shared<arlo_interfaces::srv::GetImportantWeights::Request>();
    auto response = client_getWeights->async_send_request(request);
    
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), response) == rclcpp::FutureReturnCode::SUCCESS) {
        auto result = response.get();
        // cerr << "Pesos obtenidos " << result->weightsfile << endl;

        auto mensajePesos = std_msgs::msg::String(); 
        mensajePesos.data = result->weightsfile;
        publisher_->publish(mensajePesos);

    } else {
        cout << "Fallo al llamar al servicio para obtener pesos para imitación." << endl;
    }
    
    cerr << "Terminó el cp::mirroring" << endl; 
}


// void cp::Mirroring(int i)
// {
//     std::cerr << "Iniciando el proceso de Mirroring con el robot: " << i << std::endl;

//     // Crear cliente solo una vez, fuera de cualquier ciclo
//     client_getWeights = this->create_client<arlo_interfaces::srv::GetImportantWeights>("robot"+std::to_string(i)+"0/service_importantWeights");

//     while (!client_getWeights->wait_for_service(std::chrono::seconds(1))) {
//         if (!rclcpp::ok()) {
//             std::cout << "Servicio para Mirroring no disponible. Saliendo." << std::endl;
//             return;
//         }
//         std::cout << "Esperando el servicio para Mirroring..." << std::endl;
//     }

//     auto request = std::make_shared<arlo_interfaces::srv::GetImportantWeights::Request>();
//     auto response = client_getWeights->async_send_request(request);

//     if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), response) == rclcpp::FutureReturnCode::SUCCESS) {
//         auto result = response.get();
//         std::cerr << "Pesos obtenidos: " << result->weightsfile << std::endl;

//         // Leer pesos actuales desde archivo
//         std::ifstream inputFile(inputDir);
//         std::vector<double> currentWeights;
//         double weight;
//         if (!inputFile.is_open()) {
//             std::cerr << "No se pudo abrir el archivo de pesos " << inputDir << std::endl;
//             return;
//         }
//         while (inputFile >> weight) {
//             currentWeights.push_back(weight);
//         }
//         inputFile.close();

//         // Leer pesos obtenidos del robot más cercano
//         std::ifstream newWeightsFile(result->weightsfile);
//         std::vector<double> newWeights;
//         if (!newWeightsFile.is_open()) {
//             std::cerr << "No se pudo abrir el archivo de pesos del robot más cercano." << std::endl;
//             return;
//         }
//         while (newWeightsFile >> weight) {
//             newWeights.push_back(weight);
//         }
//         newWeightsFile.close();

//         // Combinación de pesos (promedio simple en este caso)
//         std::vector<double> combinedWeights;
//         for (size_t j = 0; j < currentWeights.size() && j < newWeights.size(); ++j) {
//             combinedWeights.push_back((currentWeights[j] + newWeights[j]) / 2.0);
//         }

//         // Guardar los pesos combinados en el archivo
//         std::ofstream outputFile(inputDir);
//         if (!outputFile.is_open()) {
//             std::cerr << "No se pudo abrir el archivo para escribir los pesos combinados." << std::endl;
//             return;
//         }
//         for (const double& w : combinedWeights) {
//             outputFile << w << " ";
//         }
//         outputFile.close();

//         // Publicar el mensaje con los nuevos pesos combinados
//         std_msgs::msg::String mensajePesos;
//         mensajePesos.data = inputDir;
//         publisher_->publish(mensajePesos);

//     } else {
//         std::cout << "Fallo al llamar al servicio para obtener pesos para imitación." << std::endl;
//     }

//     std::cerr << "Terminó el proceso de mirroring." << std::endl; 
// }