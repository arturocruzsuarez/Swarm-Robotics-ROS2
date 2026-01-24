#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Int64
from nav_msgs.msg import Odometry
import random as rd
from std_msgs.msg import Float32MultiArray
from arlo_interfaces.msg import EstadoArlo
from arlo_interfaces.msg import MatesOdom
from rclpy.executors import SingleThreadedExecutor
from math import sqrt, pow
from message_filters import ApproximateTimeSynchronizer, Subscriber

class temporal_lobe(Node):
    
    def __init__(self,i, tipo, numMates, task):
        super().__init__("temporal_lobe_"+str(i)+tipo)

        self.i = i
        self.tipo = tipo
        self.numMates = numMates
        self.task= task
        self.estado = EstadoArlo()
        self.estadoO = MatesOdom()
        self.dist_to_mates = 0.0
        self.x = 10000000
        self.y = 10000000

        if self.tipo == "1":
            self.numMates = numMates+1   #aqui, en caso los nodos sean dummy, entonces se agrega un mate más, refiriendonos al bot soñando
            self.i= self.i+1
            
        self.flag_recibido = [False] * (4+self.numMates)
        self.mensajes_recibidos_list= [0] * (4+self.numMates) #son 4 sensores + n Compañeros

        self.diccionario_sensores = {'link_sensor_center': 1, 'link_sensor_back': 2, 'link_sensor_right': 3, 'link_sensor_left': 4}

        self.publisher =  self.create_publisher(EstadoArlo,"robot"+str(i)+tipo+"/temporal_lobe_",1)
        self.suscriptor1 = self.create_subscription(LaserScan,"robot"+str(i)+tipo+"/ultrasonico1/out", self.procesa1, 1)
        self.suscriptor2 = self.create_subscription(LaserScan,"robot"+str(i)+tipo+"/ultrasonico2/out", self.procesa2, 1)
        self.suscriptor3 = self.create_subscription(LaserScan,"robot"+str(i)+tipo+"/ultrasonico3/out", self.procesa3, 1)
        self.suscriptor4 = self.create_subscription(LaserScan,"robot"+str(i)+tipo+"/ultrasonico4/out", self.procesa4, 1)
        self.suscriptorOdom = self.create_subscription(Odometry,"robot"+str(i)+tipo+"/odom", self.checaOdom, 1)
        self.suscriptorMates = self.create_subscription(Int64,"robot10/redefineMates", self.redefineNumMates, 10)

        self.susMates = self.create_subscription(MatesOdom,"MatesOdom", self.procesaMatesOdom, 1)
        self.pubMates =  self.create_publisher(MatesOdom,"MatesOdom",1)

        #self.FirstOdom = self.create_service(MatesOdom,"FirstOdom", self.FirstOdomCallback)

    def procesaMatesOdom(self, odoms:MatesOdom):
        
        split = list(odoms.name)
        
        self.mensajes_recibidos_list[int(split[0])+3] = odoms.odom
        self.flag_recibido[int(split[0])+3]=True

        if(all(self.flag_recibido)):
            self.procesaAll()
    

    def checaOdom(self, odom:Odometry):
        #estado = MatesOdom()
        self.estadoO.odom = odom
        self.estadoO.name = str(self.i)+str(self.tipo)
        self.pubMates.publish(self.estadoO)
        # if(self.x == 10000000):
        #     self.x = odom.pose.pose.position.x
        #     self.y = odom.pose.pose.position.y


    def procesa1(self, rango:LaserScan):  #link_sensor_center
        self.mensajes_recibidos_list[0]=LaserScan()
        self.mensajes_recibidos_list[0]= rango
        self.flag_recibido[0]=True
        if(all(self.flag_recibido)):
            self.procesaAll()


    def procesa2(self, rango:LaserScan):  #link_sensor_center
        self.mensajes_recibidos_list[1]=LaserScan()
        self.mensajes_recibidos_list[1]=rango
        self.flag_recibido[1]=True
        if(all(self.flag_recibido)):
            self.procesaAll()

    def procesa3(self, rango:LaserScan):  #link_sensor_center
        self.mensajes_recibidos_list[2]=LaserScan()
        self.mensajes_recibidos_list[2]=rango
        self.flag_recibido[2]=True
        if(all(self.flag_recibido)):
            self.procesaAll()
                

    def procesa4(self, rango:LaserScan):  #link_sensor_center
        self.mensajes_recibidos_list[3]=LaserScan()
        self.mensajes_recibidos_list[3]=rango
        self.flag_recibido[3]=True
        if(all(self.flag_recibido)):
            self.procesaAll()

    def redefineNumMates(self, nuevosMates:Int64):
        self.numMates = self.numMates + nuevosMates.data

        self.flag_recibido = [False] * (4+self.numMates)
        self.mensajes_recibidos_list= [0] * (4+self.numMates)

    
    def procesaAll(self):
        
        self.estado.sensor1 = self.mensajes_recibidos_list[0]
        self.estado.sensor2 = self.mensajes_recibidos_list[1]
        self.estado.sensor3 = self.mensajes_recibidos_list[2]
        self.estado.sensor4 = self.mensajes_recibidos_list[3]
        self.estado.odom= self.mensajes_recibidos_list[(int(self.i))+3]   # con self.i, obtenemos la posicion de la odometría que le corresponde a bot self
        
        self.dist_to_mates = 0.0
        if (self.task == 2 and self.numMates>1):

            for i, msg in enumerate(self.mensajes_recibidos_list[4:]):
                if i != self.i-1:
                    self.dist_to_mates += sqrt(pow((self.estado.odom.pose.pose.position.x)-(msg.pose.pose.position.x),2)+
                                      pow((self.estado.odom.pose.pose.position.y)-(msg.pose.pose.position.y), 2))
        
            self.dist_to_mates /= (self.numMates - 1)

        self.estado.dist_to_mates = self.dist_to_mates
        self.publisher.publish(self.estado)
        self.flag_recibido = [False] *(4+self.numMates)
        
