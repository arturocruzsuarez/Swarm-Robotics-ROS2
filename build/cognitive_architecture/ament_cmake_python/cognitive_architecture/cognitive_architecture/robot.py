import rclpy
from cognitive_architecture.lobulo_temporal import temporal_lobe
from cognitive_architecture.corteza_motora_primaria import CortezaMotoraPrimaria


class Robot():
    def __init__(self, id, tipo, num_bots, task):
        self.lobuloTemporal = temporal_lobe(id, tipo, num_bots, task)
        self.cortezaMotoraPrimaria = CortezaMotoraPrimaria(id, tipo)
        self.executor = rclpy.executors.MultiThreadedExecutor()
        self.executor.add_node(self.lobuloTemporal)
        self.executor.add_node(self.cortezaMotoraPrimaria)

    def ejecutaLobulos(self):
        self.executor.spin()