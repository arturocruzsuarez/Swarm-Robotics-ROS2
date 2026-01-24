cmake_minimum_required(VERSION 3.8)
project(cognitive_architecture)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
#find_package(rosidl_default_generators REQUIRED)
find_package(rclpy REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(fmt REQUIRED)
#find_package(sys REQUIRED)
find_package(arlo_interfaces REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rosgraph_msgs REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(gazebo_msgs REQUIRED)

#rosidl_generate_interfaces(${PROJECT_NAME}
#  "msg/MatrixVector.msg"
#)

#ament_export_dependencies(rosidl_default_runtime)
#include cpp "include" directory
include_directories(include)

#create cpp executable and link with dependencies
add_executable(cpp_exe src/controlador_cpp.cpp)
add_executable(meta_exe src/controlador_meta.cpp)

ament_target_dependencies(cpp_exe rclcpp std_msgs sensor_msgs std_srvs arlo_interfaces fmt rosgraph_msgs nav_msgs rclcpp_components gazebo_msgs)
target_link_libraries(cpp_exe
  fmt::fmt
)

ament_target_dependencies(meta_exe rclcpp std_msgs sensor_msgs std_srvs arlo_interfaces fmt rosgraph_msgs nav_msgs rclcpp_components gazebo_msgs)
target_link_libraries(meta_exe
  fmt::fmt
)

#install cpp executables in the ros2_iron/install/cognitive_architecture/lib/cognitive_architecture/ folder
install(TARGETS
  cpp_exe
  meta_exe
  DESTINATION lib/${PROJECT_NAME}
)

#install python modules
ament_python_install_package(${PROJECT_NAME})

#install python executables in the ros2_iron/install/cognitive_architecture/lib/cognitive_architecture/ folder
install(PROGRAMS
  scripts/Controlador_individuo.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  models
  worlds
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
