# Corteza_mootora_secundaria.cpp
Este código contiene el constructor para los nodos de corteza_motora_secundara, al igual que sus métodos. Este tipo de nodo se encarga de recibir la información estructurada de los sensores del robot y de su posición, todos provenientes de su respectivo nodo lobulo_temporal.
Toda la información proveniente del lobulo temporal será entrada para la red neuronal, y sus salidas serán los movimientos que realizará el robot. Dicho esto, cabe mencionar que la red neuronal se ejecutará cada vez que se reciba información del lobulo temporal.


# Corteza_premotora.cpp
ESte código contiene constructor y métodos para los nodos de tipo corteza_premotora. Estos nodos se encargan de arrancar el proceso de sueño y consigo un algoritmo evolutivo genético para el aprendizaje de la red neuronal.  
