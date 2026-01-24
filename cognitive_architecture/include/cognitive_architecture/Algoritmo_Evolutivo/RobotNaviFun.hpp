#include "RobotNaviFun.h"
#include <rclcpp/rclcpp.hpp>
#include "arlo_interfaces/srv/evaluate_driver.hpp"   //este es un servicio
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/color.h>
//#include "srvEvaluateDriver.hpp"

#define NUM_SENSORES 96
#define NUM_SALIDAS 2

RobotNaviFun::RobotNaviFun(int id,int task,int maxSTime, double tThreshold)
    : ProblemaOptim("RobotNavi", (NUM_SENSORES+2) * NUM_SALIDAS, 0)
{
    maxSimTime = maxSTime;
    touchThreshold = tThreshold;

    //// Estos son parámetros para el controlador. NO deben cambiarlos
    numInputsNN = NUM_SENSORES+2;    // La entrada del controlador son 96 sensores + X y Y del robot.
    numOutputsNN = NUM_SALIDAS;    // La salida del controlador son los actuadores de velocidad y giro.
    numHidden = 0;

    Task = task;
    Id = id;
    //// No cambiar ///.

    // nVariables es un atributo de la clase base
    // El valor que ponemos acá sirve para que el GA sepa que cada individuo
    // tendrá 192 variables.
    nVariables = numInputsNN * numOutputsNN;

    // Acá definimos el intervalo para los valores de cada uno de los pesos del controlador.
    vector<pair<double, double>> ranges(nVariables, make_pair(-700, 700));
    varRanges = ranges;

    // Archivo con los pesos de cada solución. Sirve para comunicarse con el servidor
    // que evaluará los robots.
    // SE DEBE PONER UNA RUTA DONDE LO PUEDA ENCONTRAR EL SERVIDOR.
    popFilePattern = "pesos_eval_{:02d}.txt";

    client = std::make_shared<rclcpp::Node>("evaluate_driver_client_"+to_string(id));
    service = client->create_client<arlo_interfaces::srv::EvaluateDriver>("evaluate_driver");
}

RobotNaviFun::~RobotNaviFun() {}

/* Este método evalúa la función objetivo, obtiendo el valor real de
* la función y la aptitud del individuo dado.
* Entrada: x, un arreglo que tiene los PESOS que usará el controlador.
* Salida: fun, el tiempo de recorrido que regrese el simulador del robot.
*/
void RobotNaviFun::evaluateFun(vector<double> const &x, double &fun, vector<double> &restr) const
{
    // Crear un objeto de cliente para el servicio

    writeWeightsFile(x);

    while (!service->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            std::cout << "Servicio no disponible. Saliendo." << std::endl;
            return;
        }
        std::cout << "Servicio no disponible. Intentando nuevamente..." << std::endl;
    }

    // Crear una solicitud para el servicio
    auto request = std::make_shared<arlo_interfaces::srv::EvaluateDriver::Request>();
    request->maxtime = 30; // Tiempo máximo para que el robot llegue a la meta.
    request->weightsfile = fmt::format(popFilePattern, Id); // Usar el id actual
    //std::cerr << "hice la solicitud del servicio" << std::endl;
    
    // Llamar al servicio y manejar la respuesta
    auto result_future = service->async_send_request(request);
    if (rclcpp::spin_until_future_complete(client, result_future) == rclcpp::FutureReturnCode::SUCCESS) {
        auto result = result_future.get();
        fun = result->time + result->dist2mates;   //sí acabó

        if (result->dist2go > 0)  fun = request->maxtime*2 + result->dist2go + result->dist2mates;  // Si el robot no llega a la meta, ajustar el tiempo de recorrido
    
    } else {
        std::cout << "Fallo al llamar al servicio evaluate_driver para evaluar el controlador del robot." << std::endl;
    }

}


void RobotNaviFun::writeWeightsFile(vector<double> const &weights, int id) const{
        
    string weightsFileName = fmt::format(popFilePattern, id);
    std::cerr << weightsFileName << std::endl;
    std::ofstream archivo(weightsFileName);

    archivo <<  std::to_string(task_map_[Task][0])+" "+std::to_string(task_map_[Task][1])+" 0 0\n";

    for (int i = 0; i < (task_map_[Task][0])*(task_map_[Task][1]); i+=2)
    {
        archivo << weights[i] << " " << weights[i+1] << " ";
    }
    archivo.close();
}

// void RobotNaviFun::writeWeightsFile(vector<double> const &weights, int id) const
// {
//     string weightsFileName = fmt::format(popFilePattern, id);

//     ofstream popStream;
//     popStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

//     try
//     {
//         // Esto abre el archivo para escritura, popStream es el flujo hacia el archivo.
//         popStream.open(weightsFileName, std::ofstream::out);
//         popStream << fixed << setw(5 + 8) << setprecision(8);
//         cerr << "hola 1: " << "\n";
//         // Escribir el número de entradas, salidas y neuronas ocultas en el archivo
//         popStream << numInputsNN << "\n"
//                   << numOutputsNN << "\n"
//                   << numHidden << "\n";
        
//         cerr << "hola 2: " << "\n";
//         // Escribir los pesos en el archivo
//         for (int i = 0; i < weights.size(); ++i)
//         {
//             popStream << weights[i] << "\t";

//             // Insertar un salto de línea después de cada fila de pesos
//             if ((i + 1) % numInputsNN == 0)
//                 popStream << "\n";

//             cerr << "hola for " << i << "\n";
//         }
//         cerr << "hola 4: " <<  "\n";
//     }
//     catch (ofstream::failure &e)
//     {
//         cerr << "No se pudo crear el perro archivo: " << weightsFileName << "\n";
//         exit(0);
//     }
// }