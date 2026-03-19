#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Int64
from nav_msgs.msg import Odometry
from arlo_interfaces.msg import EstadoArlo, MatesOdom
from math import sqrt, pow

# El Lóbulo Temporal procesa la información sensorial y la odometría del enjambre
class temporal_lobe(Node):
    
    def __init__(self, i, tipo, numMates, task):
        # CAMBIO CLAVE: Nombre de nodo limpio /robot1_temporal_lobe
        super().__init__("robot" + str(i) + "_temporal_lobe")

        self.i = i
        self.tipo = tipo
        self.numMates = numMates
        self.task = task
        self.estado = EstadoArlo()
        self.estadoO = MatesOdom()
        self.dist_to_mates = 0.0

        # Mantenemos tu lógica para el modo entrenamiento/sueño
        if self.tipo == "1":
            self.numMates = numMates + 1
            self.i = self.i + 1
            
        self.flag_recibido = [False] * (4 + self.numMates)
        self.mensajes_recibidos_list = [0] * (4 + self.numMates)

        self.diccionario_sensores = {
            'link_sensor_center': 1, 
            'link_sensor_back': 2, 
            'link_sensor_right': 3, 
            'link_sensor_left': 4
        }

        # Nombre base para tópicos (robot1, robot2...)
        base_topic = "robot" + str(i)

        # Publicador y Suscriptores actualizados
        self.publisher = self.create_publisher(EstadoArlo, base_topic + "/temporal_lobe_", 1)
        
        self.suscriptor1 = self.create_subscription(LaserScan, base_topic + "/ultrasonico1/out", self.procesa1, 1)
        self.suscriptor2 = self.create_subscription(LaserScan, base_topic + "/ultrasonico2/out", self.procesa2, 1)
        self.suscriptor3 = self.create_subscription(LaserScan, base_topic + "/ultrasonico3/out", self.procesa3, 1)
        self.suscriptor4 = self.create_subscription(LaserScan, base_topic + "/ultrasonico4/out", self.procesa4, 1)
        self.suscriptorOdom = self.create_subscription(Odometry, base_topic + "/odom", self.checaOdom, 1)
        
        # ELIMINADO EL "robot10" HARDCODED: Ahora escucha a su propia premotora
        self.suscriptorMates = self.create_subscription(Int64, base_topic + "/redefineMates", self.redefineNumMates, 10)

        self.susMates = self.create_subscription(MatesOdom, "MatesOdom", self.procesaMatesOdom, 1)
        self.pubMates = self.create_publisher(MatesOdom, "MatesOdom", 1)

        self.get_logger().info(f"Lóbulo Temporal del Robot {i} escuchando en {base_topic}")

    def procesaMatesOdom(self, odoms: MatesOdom):
        # Usamos el primer dígito del nombre como ID para el índice
        split = list(odoms.name)
        self.mensajes_recibidos_list[int(split[0]) + 3] = odoms.odom
        self.flag_recibido[int(split[0]) + 3] = True

        if all(self.flag_recibido):
            self.procesaAll()

    def checaOdom(self, odom: Odometry):
        self.estadoO.odom = odom
        # Enviamos solo el ID numérico para evitar el "10"
        self.estadoO.name = str(self.i)
        self.pubMates.publish(self.estadoO)

    def procesa1(self, rango: LaserScan):
        self.mensajes_recibidos_list[0] = rango
        self.flag_recibido[0] = True
        if all(self.flag_recibido): self.procesaAll()

    def procesa2(self, rango: LaserScan):
        self.mensajes_recibidos_list[1] = rango
        self.flag_recibido[1] = True
        if all(self.flag_recibido): self.procesaAll()

    def procesa3(self, rango: LaserScan):
        self.mensajes_recibidos_list[2] = rango
        self.flag_recibido[2] = True
        if all(self.flag_recibido): self.procesaAll()

    def procesa4(self, rango: LaserScan):
        self.mensajes_recibidos_list[3] = rango
        self.flag_recibido[3] = True
        if all(self.flag_recibido): self.procesaAll()

    def redefineNumMates(self, nuevosMates: Int64):
        self.numMates = self.numMates + nuevosMates.data
        self.flag_recibido = [False] * (4 + self.numMates)
        self.mensajes_recibidos_list = [0] * (4 + self.numMates)

    def procesaAll(self):
        self.estado.sensor1 = self.mensajes_recibidos_list[0]
        self.estado.sensor2 = self.mensajes_recibidos_list[1]
        self.estado.sensor3 = self.mensajes_recibidos_list[2]
        self.estado.sensor4 = self.mensajes_recibidos_list[3]
        
        # Corregimos el acceso a la odometría propia
        self.estado.odom = self.mensajes_recibidos_list[int(self.i) + 3]
        
        self.dist_to_mates = 0.0
        if self.task == 2 and self.numMates > 1:
            for i, msg in enumerate(self.mensajes_recibidos_list[4:]):
                if (i + 1) != self.i: # Evitamos calcular distancia hacia nosotros mismos
                    self.dist_to_mates += sqrt(pow((self.estado.odom.pose.pose.position.x) - (msg.pose.pose.position.x), 2) +
                                             pow((self.estado.odom.pose.pose.position.y) - (msg.pose.pose.position.y), 2))
            self.dist_to_mates /= (self.numMates - 1)

        self.estado.dist_to_mates = self.dist_to_mates
        self.publisher.publish(self.estado)
        self.flag_recibido = [False] * (4 + self.numMates)
