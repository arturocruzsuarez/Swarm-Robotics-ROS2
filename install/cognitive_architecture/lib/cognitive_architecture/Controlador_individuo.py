#!/usr/bin/env python3

import rclpy
import sys
from threading import Thread
import cognitive_architecture.robot as robot

def main(args=None):
    rclpy.init(args=args) # Inicia comunicaciones de ROS 2

    if args is None:
        args = sys.argv[1:] 
    
    # --- CAMBIO VITAL: Ahora recibimos el ID específico del robot ---
    # Terminal 5 pasará un '2', Terminal 6 pasará un '3'
    id_robot = int(args[1])
    
    # Definimos el número total de compañeros para el cálculo de cohesión
    # Puedes hacerlo dinámico o dejarlo en 3 para esta actividad
    total_mates = 3 

    task = int(args[2])
    modo = args[0]

    print(f"--- Iniciando controlador para ROBOT {id_robot} (Tarea: {task}) ---")

    # Creamos un ÚNICO robot por proceso/terminal
    # Esto evita que los sensores se encimen o causen "ceguera"
    bot = robot.Robot(id_robot, modo, total_mates, task)
      
    # Iniciamos los lóbulos cerebrales (percepción y red neuronal)
    hilo = Thread(target=bot.ejecutaLobulos)
    hilo.start()
    hilo.join()

    rclpy.shutdown() # Termina comunicaciones de ROS 2

if __name__ == '__main__':
    main()
