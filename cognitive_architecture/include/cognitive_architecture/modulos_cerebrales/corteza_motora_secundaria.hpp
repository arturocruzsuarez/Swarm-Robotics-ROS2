#include "corteza_motora_secundaria.h"

// Este nodo contiene la red neuronal que se encarga de decidir los movimientos del robot
// CmSec es Corteza Motora Secundaria

CmSec::CmSec(int i, char tipo_char, int task, double dropOut, double xGoal, double yGoal) : 
                Node("robot" + to_string(i)), // Nombre de nodo único: /robot1, /robot2, etc.
                identificador(i), 
                task(task),
                redNeuronal(task_map[task][0], task_map[task][1], dropOut, rangos_salidas), 
                tipo(tipo_char - 48), // Conversión de ASCII a entero (ej: '0' -> 0)
                Goalx(xGoal), 
                Goaly(yGoal)
{
   flag_success = false;
   id = i;
   
   // Definimos un nombre base para evitar errores de concatenación con caracteres ASCII
   string base_name = "robot" + to_string(i);

   // --- SERVICIOS ---
   service_getWeights = this->create_service<arlo_interfaces::srv::GetImportantWeights>(
                base_name + "/service_importantWeights", 
                bind(&CmSec::service_importantWeights, this, placeholders::_1, placeholders::_2));

   // Eliminamos el riesgo del "10" fantasma usando solo el ID numérico
   string srv_fitness_name = base_name + "/service_get_fitness";
   
   service_sendFitness = this->create_service<arlo_interfaces::srv::GetMatesFitness>(
                srv_fitness_name, 
                bind(&CmSec::service_send_fitness, this, placeholders::_1, placeholders::_2));

   // --- PUBLICADORES ---
   publisher_NN = this->create_publisher<std_msgs::msg::Float64MultiArray>(
                base_name + "/corteza_motora_secundariaNN", 10);

   publisher_evo_ = this->create_publisher<arlo_interfaces::msg::PesosStruct>(
                base_name + "/corteza_motora_secundaria_pesos", 10);

   publisher_ = this->create_publisher<sensor_msgs::msg::LaserScan>(
                base_name + "/corteza_motora_secundaria", 10);

   // --- SUSCRIPTORES ---
   subscriber_evo = this->create_subscription<std_msgs::msg::String>(
                base_name + "/corteza_premotora_pesos", 10, 
                bind(&CmSec::setParameters_evo, this, placeholders::_1));

   // Tópico dinámico para el lóbulo temporal
   string topic_lobe = base_name + "/temporal_lobe_";
   subscription_ = this->create_subscription<arlo_interfaces::msg::EstadoArlo>(
                topic_lobe, 10, 
                bind(&CmSec::ejecutaNN, this, placeholders::_1));

   changeGoalSub = this->create_subscription<std_msgs::msg::Float64MultiArray>(
                base_name + "/changeGoal", 10, 
                bind(&CmSec::setGoalCoordenates, this, placeholders::_1));

   // --- GESTIÓN DE ARCHIVOS DE PESOS ---
   char archivo[100];
   // Si tipo es 1 (entrenamiento) usa el predeterminado, si no, usa el específico del robot
   if (tipo == 1) {
       sprintf(archivo, "./archivo_pesos_predeterminado_%d.txt", task);
   } else {
       sprintf(archivo, "./archivo_pesos_%d_%d.txt", identificador, task);
   }

   if (!fileExists(archivo)) {
      cerr << "Aviso: No existe archivo entrenado. Generando pesos iniciales en: " << archivo << endl;
      genera_pesos(archivo);
   }

   weightsFile = archivo;
   redNeuronal.setParameters(archivo, dropOut);
   fitness = redNeuronal.fitness;
   
   RCLCPP_INFO(this->get_logger(), "Cerebro del Robot %d inicializado exitosamente.", id);
}

CmSec::~CmSec(){}

void CmSec::ejecutaNN(const arlo_interfaces::msg::EstadoArlo &msg)
{
   if (flag_success == false)
   {
      std_msgs::msg::Float64MultiArray vector_reaction;
      entradas.clear(); // Limpiamos para evitar acumulación de datos

      for (size_t i = 0; i < msg.sensor1.ranges.size(); i++)
      {
         entradas.push_back(msg.sensor1.ranges[i]);
         entradas.push_back(msg.sensor2.ranges[i]);
         entradas.push_back(msg.sensor3.ranges[i]);
         entradas.push_back(msg.sensor4.ranges[i]);
      }

      dist_to_go_x = Goalx - (msg.odom.pose.pose.position.x);
      dist_to_go_y = Goaly - (msg.odom.pose.pose.position.y);

      entradas.push_back(dist_to_go_x);
      entradas.push_back(dist_to_go_y);

      if (task == 2) { 
         entradas.push_back(msg.dist_to_mates);
      }

      vector<double> reaction;
      redNeuronal.driveArlo(entradas, reaction);

      // Condición de llegada a meta (umbral de 1 metro)
      if (abs(dist_to_go_x) <= 1.0 && abs(dist_to_go_y) <= 1.0 && tipo == 0)
      {
         reaction = {0.0, 0.0};
         flag_success = true;
         RCLCPP_INFO(this->get_logger(), "¡Robot %d llegó a la meta!", id);
      }

      vector_reaction.data = reaction;
      publisher_NN->publish(vector_reaction);

      for (auto mensaje : mensajes_recibidos) {
         publisher_->publish(mensaje.sensor1);
      }

      mensajes_recibidos.clear();
   }
}

void CmSec::setParameters_evo(const std_msgs::msg::String &msg) 
{
   redNeuronal.setParameters(msg.data.c_str(), 0.20);
   flag_success = false;
}

bool CmSec::fileExists(string path)
{
   struct stat info;
   return (stat(path.c_str(), &info) == 0 && !(info.st_mode & S_IFDIR));
}

void CmSec::genera_pesos(const char *archivo_name)
{
   ofstream archivo(archivo_name);
   random_device rd;
   mt19937 gen(rd());
   uniform_int_distribution<> distribucion(-500, 500);

   archivo << to_string(task_map[task][0]) + " " + to_string(task_map[task][1]) + " 0 0\n";
   for (int i = 0; i < task_map[task][0]; i++)
   {
      archivo << distribucion(gen) << " " << distribucion(gen) << " ";
   }
   archivo.close();
}

bool CmSec::service_importantWeights(const std::shared_ptr<arlo_interfaces::srv::GetImportantWeights::Request> request,
                                     std::shared_ptr<arlo_interfaces::srv::GetImportantWeights::Response> response)
{
   response->weightsfile = weightsFile;
   return true;
}

bool CmSec::service_send_fitness(const std::shared_ptr<arlo_interfaces::srv::GetMatesFitness::Request> request,
                                  std::shared_ptr<arlo_interfaces::srv::GetMatesFitness::Response> response)
{
   response->fitness = fitness;
   response->id = id;
   return true;
}

void CmSec::setGoalCoordenates(const std_msgs::msg::Float64MultiArray &msg)
{
   if (msg.data.size() >= 2) {
       Goalx = msg.data[0];
       Goaly = msg.data[1];
       RCLCPP_INFO(this->get_logger(), "Nueva meta recibida: [%.2f, %.2f]", Goalx, Goaly);
   }
}
