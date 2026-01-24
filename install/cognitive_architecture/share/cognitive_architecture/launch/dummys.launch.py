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



def create_bots(context, *args, **kwargs):
    # Obtener valores de las configuraciones
    num_bots = int(LaunchConfiguration('num_bots').perform(context))
    bot_kind = 1

    bots = {}
    for i in range(1, num_bots + 1):
        clave = f"llave_{i}"
        bots[clave] = f"robot{i}{bot_kind}"
    
    spawn_nodes = []

    x=-3
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
                "-file", "/home/rodrigo/ros2_iron/src/cognitive_architecture/models/arlo/model.sdf",
                "-robot_namespace", robot
                #"--ros-args", "--remap", "ultrasonico1:=pedro"
            ]
        )
        spawn_nodes.append(spawn_node)
        x=x+3

    return spawn_nodes
  
def generate_launch_description():
 
 
    model_arg = DeclareLaunchArgument(name='models', description='Absolute path to robot sdf file') #cargar modelo
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')  #declara localizacion del paquete gazebo
    use_sim_time = LaunchConfiguration('use_sim_time') #argumento que dice a ros que se utiliza el tiempo de la simulacion
    package_name = 'cognitive_architecture'   #nombre del paquete
    pkg_share = FindPackageShare(package=package_name).find(package_name)  
    pkg_gazebo_ros = FindPackageShare(package='gazebo_ros').find('gazebo_ros')  #se encuentra la localizacion de los paquetes 

    # Get URDF via xacro

    sdf_file_name = 'model.sdf'
    sdf = os.path.join(
        get_package_share_directory('cognitive_architecture'),
        'models/arlo',
        sdf_file_name
        )
    with open(sdf, 'r') as infp:
        robot_desc = infp.read()

    num_bots_arg = DeclareLaunchArgument('num_bots', default_value='1')


    return LaunchDescription([
    num_bots_arg,
    OpaqueFunction(function=create_bots)

])

#https://www.youtube.com/watch?v=x-s0jUZJ4rQ&list=PL3AvrhrDIyfHIPE1RS63ve4JltbWpO5uF&index=2