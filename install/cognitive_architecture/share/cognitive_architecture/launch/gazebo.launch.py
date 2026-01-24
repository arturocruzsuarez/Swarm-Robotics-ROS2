import os
import time
from ament_index_python.packages import get_package_share_directory
 
from launch_ros.parameter_descriptions import ParameterValue
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess, OpaqueFunction
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.actions import SetEnvironmentVariable





def generate_launch_description(args = None):
 
    set_gazebo_port = SetEnvironmentVariable('GAZEBO_MASTER_URI', f'http://localhost:11345')
 
    model_arg = DeclareLaunchArgument(name='models', description='Absolute path to robot sdf file') #cargar modelo
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')  #declara localizacion del paquete gazebo
    use_sim_time = LaunchConfiguration('use_sim_time') #argumento que dice a ros que se utiliza el tiempo de la simulacion
    package_name = 'cognitive_architecture'   #nombre del paquete
    pkg_share = FindPackageShare(package=package_name).find(package_name)  
    pkg_gazebo_ros = FindPackageShare(package='gazebo_ros').find('gazebo_ros')  #se encuentra la localizacion de los paquetes 

    world_file_path = 'arena_cerebral.world'
    world = LaunchConfiguration('world')
    world_path = os.path.join(pkg_share, 'worlds',  world_file_path)

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        name='use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
        )

    # Get URDF via xacro

    sdf_file_name = 'model.sdf'
    sdf = os.path.join(
        get_package_share_directory('cognitive_architecture'),
        'models/arlo',
        sdf_file_name
        )
    with open(sdf, 'r') as infp:
        robot_desc = infp.read()


    declare_world_cmd = DeclareLaunchArgument(
        name='world',
        default_value=world_path,
        description='Full path to the world model file to load'
        )
 
    bot_kind_arg = DeclareLaunchArgument('bot_kind', default_value='0')
    num_bots_arg = DeclareLaunchArgument('num_bots', default_value='1')
    task = DeclareLaunchArgument('task', default_value='1')


    ldw = LaunchDescription()
    ldw.add_action(declare_world_cmd)

    gazebo = ExecuteProcess(
        cmd=['gazebo', world_path,'--verbose', '-s', 'libgazebo_ros_factory.so', 
        '-s', 'libgazebo_ros_init.so'], 
        additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11345', 'ROS_DOMAIN_ID':'1'},
            output='screen',
        )
    # gazebo = ExecuteProcess(
    #         cmd=[
    #             'gzserver',
    #             '--verbose',
    #             world_path,
    #             '-s', 'libgazebo_ros_factory.so'  
    #         ],
    #         additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11345'},
    #         output='screen'
    # )

    # gzclient = ExecuteProcess(
    #         cmd=[
    #             'gzclient',
    #         ],
    #         additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11345'},
    #         output='screen'
    #     )
    

    controladorPython  = ExecuteProcess(
        cmd=['ros2', 'run', 'cognitive_architecture', 'Controlador_individuo.py',LaunchConfiguration('bot_kind'), LaunchConfiguration('num_bots'),
              LaunchConfiguration('task')],  
              additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11345', 'ROS_DOMAIN_ID':'1'},
              output='screen'
    )

    controladorcpp = ExecuteProcess(
        cmd=['ros2', 'run', 'cognitive_architecture', 'cpp_exe', LaunchConfiguration('bot_kind'), LaunchConfiguration('num_bots'),
             LaunchConfiguration('task')], output='screen'
    )

    return LaunchDescription([
    bot_kind_arg,
    num_bots_arg,
    task,
    declare_use_sim_time_cmd,
    gazebo,
    #gzclient,
    OpaqueFunction(function=create_bots),
    #controladorcpp,
    controladorPython,
     set_gazebo_port 

])

#https://www.youtube.com/watch?v=x-s0jUZJ4rQ&list=PL3AvrhrDIyfHIPE1RS63ve4JltbWpO5uF&index=2

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
                #"--ros-args", "--remap", "ultrasonico1:=pedro"
            ],
            additional_env={'GAZEBO_MASTER_URI': 'http://localhost:11345', 'ROS_DOMAIN_ID':'1'},
            output='screen'
        )
        spawn_nodes.append(spawn_node)
        x=x+3

    return spawn_nodes
    #ld = LaunchDescription(spawn_nodes)
