#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float64MultiArray, Int64

# Este módulo se encarga de enviar las instrucciones a las ruedas del robot
# Implementa una jerarquía donde los reflejos tienen prioridad sobre la IA [cite: 38-40]
class CortezaMotoraPrimaria(Node):

    msg = Twist()

    def __init__(self, i, tipo):
        super().__init__("robot" + str(i) + "_primaria")
        
        self.id = i
        self.ignoreFlag = 0
        self.evadiendo = False  # Bloqueo maestro para la Red Neuronal [cite: 39]
        self.mensajes_recibidos = []
        
        self.diccionario_sensores = {
            'link_sensor_center': 1, 
            'link_sensor_back': 2, 
            'link_sensor_right': 3, 
            'link_sensor_left': 4
        }

        base_topic = "robot" + str(i)
        self.publisher = self.create_publisher(Twist, base_topic + "/cmd_vel", 10)

        # Suscripciones a los sensores ultrasónicos (Láser en Gazebo) [cite: 47-48]
        self.create_subscription(LaserScan, base_topic + "/ultrasonico1/out", self.mover, 10)
        self.create_subscription(LaserScan, base_topic + "/ultrasonico2/out", self.mover, 10)
        self.create_subscription(LaserScan, base_topic + "/ultrasonico3/out", self.mover, 10)
        self.create_subscription(LaserScan, base_topic + "/ultrasonico4/out", self.mover, 10)

        self.suscriptorNN = self.create_subscription(
            Float64MultiArray, base_topic + "/corteza_motora_secundariaNN", self.moverNN, 1)

        self.subsIgnoreFlag = self.create_subscription(
            Int64, base_topic + "/ignoreFlag", self.SetIgnoreFlag, 10)
        
        self.get_logger().info(f"Corteza Primaria del Robot {i} conectada a {base_topic}/cmd_vel con Prioridad de Evasión")

    def SetIgnoreFlag(self, mensaje: Int64):
        self.ignoreFlag = mensaje.data

    def moverNN(self, mensaje: Float64MultiArray):
        """
        Control de la Red Neuronal (Corteza Secundaria).
        Se bloquea si el ignoreFlag está activo o si hay un objeto cerca[cite: 35, 39].
        """
        if self.ignoreFlag == 1 or self.evadiendo:
            return # Prioridad a los reflejos de seguridad

        movimiento = Twist()
        movimiento.linear.x = mensaje.data[0]
        movimiento.angular.z = mensaje.data[1]
        self.publisher.publish(movimiento)

    def mover(self, mensaje: LaserScan):
        """
        Capa de Seguridad Reactiva (Reflejos).
        Detecta objetos y toma el control total del robot [cite: 38-40].
        """
        self.mensajes_recibidos.append(mensaje)
        if len(self.mensajes_recibidos) < 4:
            return 
        
        distancia_mas_cercana = 10.0 
        sensor_ganador_id = -1 

        for msg in self.mensajes_recibidos:
            minimo_de_este_sensor = min(msg.ranges)
            if minimo_de_este_sensor < distancia_mas_cercana:
                distancia_mas_cercana = minimo_de_este_sensor
                sensor_ganador_id = self.diccionario_sensores.get(msg.header.frame_id, -1)

        # Lógica de Evasión con umbral de seguridad de 0.6m [cite: 39]
        if distancia_mas_cercana < 0.6 and sensor_ganador_id != -1:
            self.evadiendo = True  # Activamos el freno de mano contra la NN
            
            if sensor_ganador_id == 1: # Objeto al frente (Cubo/Robot)
                self.parar()
                self.get_logger().warn(f"Robot {self.id}: ¡CUBO DETECTADO! Frenando...")
            elif sensor_ganador_id == 2: # Atrás
                self.avanza()
            elif sensor_ganador_id == 3: # Derecha
                self.izquierda()
            elif sensor_ganador_id == 4: # Izquierda
                self.derecha()
        else:
            # Camino despejado: devolvemos el control a la Red Neuronal [cite: 35]
            self.evadiendo = False 
        
        self.mensajes_recibidos.clear()

    # Métodos de movimiento básico (Capa Física) [cite: 11]
    def avanza(self):
        self.msg.linear.x = 0.2
        self.msg.angular.z = 0.0
        self.publisher.publish(self.msg)

    def derecha(self):
        self.msg.linear.x = 0.0
        self.msg.angular.z = -0.2
        self.publisher.publish(self.msg)

    def izquierda(self):
        self.msg.linear.x = 0.0
        self.msg.angular.z = 0.2  
        self.publisher.publish(self.msg)

    def atras(self):
        self.msg.linear.x = -0.2
        self.msg.angular.z = 0.0
        self.publisher.publish(self.msg)

    def parar(self):
        self.msg.linear.x = 0.0
        self.msg.angular.z = 0.0
        self.publisher.publish(self.msg)
