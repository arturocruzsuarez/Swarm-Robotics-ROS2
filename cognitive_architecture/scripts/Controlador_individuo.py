#!/usr/bin/env python3

import rclpy
import sys
from threading import Thread
import cognitive_architecture.robot as robot

def main(args=None):
    rclpy.init(args=args) #inicia comunicaciones de ros2

    if args is None:
        args = sys.argv[1:] 
    
    num_bots=int(args[1])

    task = int(args[2])

    robots = []
    for i in range(1,num_bots+1):
        bot = robot.Robot(i,args[0],num_bots,task)
        robots.append(bot)
      
    hilos = []
    for aux in  robots:
        hilo = Thread(target=aux.ejecutaLobulos)
        hilos.append(hilo)
        hilo.start()

    for hilo in hilos:
        hilo.join()

    rclpy.shutdown() #termina comunicaciones de ros2


if __name__ == '__main__':
    main()