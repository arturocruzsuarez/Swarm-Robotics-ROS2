#!/usr/bin/env python3
#hola
import os
import rclpy
from rclpy import executors
from rclpy.node import Node
from std_msgs.msg import String
from gazebo_msgs.srv import SpawnEntity
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Pose
from sensor_msgs.msg import Range  #este tiene que cambiar a LaserScan
from sensor_msgs.msg import LaserScan
import random as rd
from threading import Thread
from gazebo_msgs.msg import ModelStates

from nav_msgs.msg import Odometry

from std_msgs.msg import Float64MultiArray, Int64


#entradas: s1(todos los rayitos), s2, s3, s4, x, y
#salidas: vel_lineal_x, vel_angular_z

#este modulo se encarga de enviar las instrucciones a las ruedas del robot a través del plugin del differential drive
class CortezaMotoraPrimaria(Node):

    msg=Twist()
    #constructor
    def __init__(self,i,tipo):
        super().__init__("corteza_motora_primaria_"+str(i)+tipo)
        
        self.ignoreFlag = 0
        self.mensajes_recibidos=[]
        self.diccionario_sensores = {'link_sensor_center': 1, 'link_sensor_back': 2, 'link_sensor_right': 3, 'link_sensor_left': 4}

        self.publisher =  self.create_publisher(Twist, "robot"+str(i)+tipo+"/cmd_vel",10)

        self.create_subscription(LaserScan, "robot"+str(i)+tipo+"/ultrasonico1/out", self.mover, 10)
        self.create_subscription(LaserScan, "robot"+str(i)+tipo+"/ultrasonico2/out", self.mover, 10)
        self.create_subscription(LaserScan, "robot"+str(i)+tipo+"/ultrasonico3/out", self.mover, 10)
        self.create_subscription(LaserScan, "robot"+str(i)+tipo+"/ultrasonico4/out", self.mover, 10)

        self.suscriptorNN= self.create_subscription(Float64MultiArray,"robot"+str(i)+tipo+"/corteza_motora_secundariaNN", self.moverNN, 1)

        self.subsIgnoreFlag = self.create_subscription(Int64, "robot"+str(i)+tipo+"/ignoreFlag", self.SetIgnoreFlag, 10)

    def SetIgnoreFlag(self, mensaje:Int64):
        self.ignoreFlag = mensaje.data

    def moverNN(self, mensaje:Float64MultiArray):
        movimiento=Twist()

        if self.ignoreFlag == 1:
            movimiento.linear.x=0.0
            movimiento.angular.z=0.0
        else:
            movimiento.linear.x=mensaje.data[0]
            movimiento.angular.z=mensaje.data[1]
        
        self.publisher.publish(movimiento)


    def mover(self, mensaje:LaserScan):
        # 1. Guardamos el mensaje recibido
        self.mensajes_recibidos.append(mensaje)

        # 2. Esperamos a tener datos de los 4 sensores para comparar
        if len(self.mensajes_recibidos) < 4:
            return 0
        
        # 3. Buscamos cuál de los 4 sensores detectó el objeto MÁS CERCANO
        #    Inicializamos con un valor alto (10 metros)
        distancia_mas_cercana = 10.0 
        sensor_ganador_id = -1 # Ninguno todavía

        for msg in self.mensajes_recibidos:
            # ERROR CORREGIDO AQUI: 
            # Un LaserScan tiene muchos rayos en '.ranges'. 
            # Buscamos el valor mínimo de ese abanico de rayos.
            minimo_de_este_sensor = min(msg.ranges)

            # Si este sensor vio algo más cerca que el anterior, actualizamos
            if minimo_de_este_sensor < distancia_mas_cercana:
                distancia_mas_cercana = minimo_de_este_sensor
                sensor_ganador_id = self.diccionario_sensores[msg.header.frame_id]

        # 4. Lógica de Evasión (Si algo está muy cerca)
        #    Umbral de seguridad: 0.5 metros
        if distancia_mas_cercana < 0.5:
            print(f"¡PELIGRO! Sensor {sensor_ganador_id} detectó objeto a {distancia_mas_cercana:.2f}m")
            
            if sensor_ganador_id == 1: # Frente
                self.parar() # O self.atras()
            elif sensor_ganador_id == 2: # Atrás
                self.avanza()
            elif sensor_ganador_id == 3: # Derecha
                self.izquierda()
            elif sensor_ganador_id == 4: # Izquierda
                self.derecha()
        
        # 5. Limpiamos la lista para la siguiente ronda
        self.mensajes_recibidos.clear()


    def avanza(self):

        #msg = Twist()
        self.msg.linear.x = 0.2  # velocidad lineal en el eje x
        self.msg.angular.z = 0.0  # velocidad angular en el eje z

        self.publisher.publish(self.msg)

    def derecha(self):

        #msg = Twist()
        self.msg.linear.x = 0.0  # velocidad lineal en el eje x
        self.msg.angular.z = -0.2  # velocidad angular en el eje z

        self.publisher.publish(self.msg)

    def izquierda(self):

        #msg = Twist()
        self.msg.linear.x = 0.0  # velocidad lineal en el eje x
        self.msg.angular.z = 0.2  # velocidad angular en el eje z  

        self.publisher.publish(self.msg)

    def atras(self):
        #msg = Twist()
        self.msg.linear.x = -0.2  # velocidad lineal en el eje x
        self.msg.angular.z = 0.0  # velocidad angular en el eje z

        self.publisher.publish(self.msg)

    def parar(self):
        #msg = Twist()
        self.msg.linear.x = 0.0  # velocidad lineal en el eje x
        self.msg.angular.z = 0.0  # velocidad angular en el eje z

        self.publisher.publish(self.msg)
    
    def teclado(self, e):  # la e es de evento
        if e.name == 'up':
            self.avanza() 
        elif e.name == 'down':
            self.parar()  
        elif e.name == 'right':
            self.derecha() 
        elif e.name == 'left':
            self.izquierda()


