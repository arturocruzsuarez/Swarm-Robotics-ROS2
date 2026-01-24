# ProyectoTerminal_AlgoritmosNeuronasEspejoParaAprendizajeDeEnjambresRoboticos

![Demostración](output.gif)


## Acerca de la implementacion

Este proyecto utiliza ROS2 para implementar los elementos de la arquitectura cognitiva, así como sus comunicaciones.

Para este poryecto, se han creado 2 paquetes de ros2: arlo_interfaces y cognitive_architecture.

## Paquete "cognitive_architecture"

Este es el paquete principal del proyecto. Es un paquete que contiene scripts de python y códigos fuente en c++. 
El paquete está dividido en los siguientes Directorios:

- cognitive_architecture
  -  cognitive_architecture
  -  include
  -  launch
  -  models
  -  scripts
  -  src
  -  test
  -  worlds
  -  CMakeLists.txt
  -  package.xml
    
Consulte /cognitive_architecture/README.md

## Paquete "arlo_interfaces"
En este paquete se encuentran los mensajes y servicios personalizados.
El paquete está dividido en los siguientes Directorios:

-  arlo_interfaces
  -  msg
  -  srv
  -  CMakeLists.txt
  -  package.xml

Consulte /arlo_interfaces/README.md


