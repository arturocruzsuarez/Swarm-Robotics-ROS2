import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, OpaqueFunction, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # 1. Configuración de variables de entorno y rutas
    # Forzamos el Dominio 0 para visibilidad total entre procesos y terminales
    domain_id = '0'
    set_gazebo_port = SetEnvironmentVariable('GAZEBO_MASTER_URI', 'http://localhost:11345')
    set_ros_domain = SetEnvironmentVariable('ROS_DOMAIN_ID', domain_id)
    
    package_name = 'cognitive_architecture'
    pkg_share = FindPackageShare(package=package_name).find(package_name)
    
    world_file_path = 'arena_cerebral.world'
    world_path = os.path.join(pkg_share, 'worlds', world_file_path)

    # 2. Argumentos de lanzamiento
    declare_use_sim_time_cmd = DeclareLaunchArgument(
        name='use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )
    
    bot_kind_arg = DeclareLaunchArgument('bot_kind', default_value='0')
    num_bots_arg = DeclareLaunchArgument('num_bots', default_value='1')
    task_arg = DeclareLaunchArgument('task', default_value='1')

    # 3. Procesos Principales
    # Se incluye libgazebo_ros_factory para habilitar el servicio /spawn_entity
    # Se añade libgazebo_ros_init para la comunicación básica con ROS
    gazebo = ExecuteProcess(
        cmd=['gazebo', world_path, '--verbose', 
             '-s', 'libgazebo_ros_factory.so', 
             '-s', 'libgazebo_ros_init.so'],
        additional_env={
            'GAZEBO_MASTER_URI': 'http://localhost:11345',
            'ROS_DOMAIN_ID': domain_id
        },
        output='screen',
    )

    controladorPython = ExecuteProcess(
        cmd=['ros2', 'run', package_name, 'Controlador_individuo.py', 
             LaunchConfiguration('bot_kind'), 
             LaunchConfiguration('num_bots'),
             LaunchConfiguration('task')],
        additional_env={
            'GAZEBO_MASTER_URI': 'http://localhost:11345',
            'ROS_DOMAIN_ID': domain_id
        },
        output='screen'
    )

    return LaunchDescription([
        set_ros_domain,
        set_gazebo_port,
        bot_kind_arg,
        num_bots_arg,
        task_arg,
        declare_use_sim_time_cmd,
        gazebo,
        OpaqueFunction(function=create_bots),
        controladorPython
    ])

def create_bots(context, *args, **kwargs):
    num_bots = int(LaunchConfiguration('num_bots').perform(context))
    
    # Ruta absoluta al modelo SDF (Asegúrate de que esta ruta sea correcta en tu sistema)
    sdf_path = "/home/antonio/Robotic-Swarms-main/Robotic-Swarms-main/cognitive_architecture/models/arlo/model.sdf"
    
    spawn_nodes = []
    x = -7.0
    y = -14.0
    
    for i in range(1, num_bots + 1):
        # CORRECCIÓN DE NOMBRE: Eliminamos 'bot_kind' del nombre para evitar "robot10"
        # Ahora el nombre será simplemente "robot1", "robot2", etc.
        robot_name = f"robot{i}"
        
        spawn_node = Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            name=f'spawn_{robot_name}',
            arguments=[
                "-entity", robot_name,
                "-x", str(x),
                "-y", str(y),
                "-z", '0.05',
                "-Y", '0.0',
                "-file", sdf_path,
                "-robot_namespace", robot_name
            ],
            additional_env={
                'GAZEBO_MASTER_URI': 'http://localhost:11345',
                'ROS_DOMAIN_ID': '0'
            },
            output='screen'
        )
        spawn_nodes.append(spawn_node)
        x += 3.0 # Espaciado entre robots

    return spawn_nodes
