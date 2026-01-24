from launch import LaunchDescription
from launch.actions import ExecuteProcess, DeclareLaunchArgument, OpaqueFunction
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import LaunchConfiguration
from launch.actions import SetEnvironmentVariable

import os


def generate_launch_description(args = None):
    set_gazebo_port = SetEnvironmentVariable('GAZEBO_MASTER_URI', f'http://localhost:11346')
    package_name = 'cognitive_architecture'   #nombre del paquete
    pkg_share = FindPackageShare(package=package_name).find(package_name)  

    world_file_path = 'arena_cerebral.world'
    world_path = os.path.join(pkg_share, 'worlds',  world_file_path)
    

    declare_world_cmd = DeclareLaunchArgument(
        name='world',
        default_value=world_path,
        description='Full path to the world model file to load'
    )

    bot_kind_arg = DeclareLaunchArgument('bot_kind', default_value='0')
    num_bots_arg = DeclareLaunchArgument('num_bots', default_value='1')
    task = DeclareLaunchArgument('task', default_value='1')

    # meta = ExecuteProcess(
    #         cmd=[
    #             'gzserver',
    #             '--verbose',
    #             world_path,
    #             '-s', 'libgazebo_ros_factory.so',
    #             '-s', 'libgazebo_ros_init.so',
    #             '--minimal_comms'  
    #         ],
    #         additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11346'},
    #         output='screen'
    # )
    # client = ExecuteProcess(
    #         cmd=[
    #             'gzclient',
    #             '--minimal_comms' 
    #         ],
    #         additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11346'},
    #         output='screen'
    #     )
    
    gazebo = ExecuteProcess(
        cmd=['gazebo', world_path,'--verbose', '-s', 'libgazebo_ros_factory.so', 
        '-s', 'libgazebo_ros_init.so'], 
        additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11346', 'ROS_DOMAIN_ID':'2'},
            output='screen',
        )
    
    controladorPython  = ExecuteProcess(
        cmd=['ros2', 'run', 'cognitive_architecture', 'Controlador_individuo.py','0', '1',
              LaunchConfiguration('task')],  
              additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11346', 'ROS_DOMAIN_ID':'2'},
                output='screen',
    )

    ld = LaunchDescription()
    ld.add_action(declare_world_cmd)
    ld.add_action(bot_kind_arg)
    ld.add_action(num_bots_arg)
    ld.add_action(task)
    ld.add_action(set_gazebo_port)
    ld.add_action(controladorPython)
    ld.add_action(gazebo)

    # Añadir nodos de spawn con OpaqueFunction
    ld.add_action(OpaqueFunction(function=create_bots))

   
    return LaunchDescription([
        ld
])

def create_bots(context, *args, **kwargs):
    # Obtener valores de las configuraciones
    num_bots = int(LaunchConfiguration('num_bots').perform(context))
    bot_kind = LaunchConfiguration('bot_kind').perform(context)   #0= real, 1 = dummy

    bots = {}
    for i in range(1, num_bots + 1):
        clave = f"llave_{i}"
        bots[clave] = f"robot{i}{bot_kind}"
    
    spawn_nodes = []

    x=-7
    y=-14
    
    for robot in bots.values():
        spawn_node = Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            namespace=robot,
            arguments=[
                "-entity", robot,
                "-x", str(x),
                "-y", str(y),
                "-z", '0.05',
                "-Y", '0.0',
                "-file", "/home/antonio/Robotic-Swarms-main/Robotic-Swarms-main/cognitive_architecture/models/arlo/model.sdf",
                "-robot_namespace", robot
            ],
            additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11346', 'ROS_DOMAIN_ID':'2'},
            output='screen'
        )
        spawn_nodes.append(spawn_node)
        x=x+3

    return spawn_nodes
