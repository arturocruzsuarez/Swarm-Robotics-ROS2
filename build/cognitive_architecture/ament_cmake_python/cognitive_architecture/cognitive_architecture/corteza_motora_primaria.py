#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float64MultiArray, Int64

# Este módulo se encarga de enviar las instrucciones a las ruedas del robot
class CortezaMotoraPrimaria(Node):

    msg = Twist()

    def __init__(self, i, tipo):
        # CAMBIO CLAVE: Quitamos '+tipo' para que el nodo se llame /robot1_primaria
        super().__init__("robot" + str(i) + "_primaria")
        
        self.ignoreFlag = 0
        self.mensajes_recibidos = []
        self.diccionario_sensores = {
            'link_sensor_center': 1, 
            'link_sensor_back': 2, 
            'link_sensor_right': 3, 
            'link_sensor_left': 4
        }

        # CAMBIO CLAVE: Quitamos '+tipo' de todos los tópicos
        base_topic = "robot" + str(i)

        self.publisher = self.create_publisher(Twist, base_topic + "/cmd_vel", 10)

        # Suscripciones a los sensores actualizadas al nombre limpio
        self.create_subscription(LaserScan, base_topic + "/ultrasonico1/out", self.mover, 10)
        self.create_subscription(LaserScan, base_topic + "/ultrasonico2/out", self.mover, 10)
        self.create_subscription(LaserScan, base_topic + "/ultrasonico3/out", self.mover, 10)
        self.create_subscription(LaserScan, base_topic + "/ultrasonico4/out", self.mover, 10)

        self.suscriptorNN = self.create_subscription(
            Float64MultiArray, base_topic + "/corteza_motora_secundariaNN", self.moverNN, 1)

        self.subsIgnoreFlag = self.create_subscription(
            Int64, base_topic + "/ignoreFlag", self.SetIgnoreFlag, 10)
        
        self.get_logger().info(f"Corteza Primaria del Robot {i} conectada a {base_topic}/cmd_vel")

    def SetIgnoreFlag(self, mensaje: Int64):
        self.ignoreFlag = mensaje.data

    def moverNN(self, mensaje: Float64MultiArray):
        movimiento = Twist()
        if self.ignoreFlag == 1:
            movimiento.linear.x = 0.0
            movimiento.angular.z = 0.0
        else:
            movimiento.linear.x = mensaje.data[0]
            movimiento.angular.z = mensaje.data[1]
        
        self.publisher.publish(movimiento)

    def mover(self, mensaje: LaserScan):
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

        if distancia_mas_cercana < 0.5 and sensor_ganador_id != -1:
            if sensor_ganador_id == 1: # Frente
                self.parar()
            elif sensor_ganador_id == 2: # Atrás
                self.avanza()
            elif sensor_ganador_id == 3: # Derecha
                self.izquierda()
            elif sensor_ganador_id == 4: # Izquierda
                self.derecha()
        
        self.mensajes_recibidos.clear()

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
