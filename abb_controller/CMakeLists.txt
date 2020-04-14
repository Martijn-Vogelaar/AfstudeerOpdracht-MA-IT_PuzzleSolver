cmake_minimum_required(VERSION 3.1.3)
project(abb_controller)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(catkin REQUIRED
  COMPONENTS
    gazebo_ros
    interactive_markers
    moveit_core
    moveit_visual_tools
    moveit_ros_planning
    moveit_ros_planning_interface
    moveit_ros_perception
    geometry_msgs
    message_runtime
    message_generation
    std_msgs
    pluginlib
    geometric_shapes
    pcl_ros
    pcl_conversions
    rosbag
    tf2_ros
    tf2_eigen
    tf2_geometry_msgs
    roscpp 
    actionlib 
    actionlib_msgs
    gazebo_ros_link_attacher
)

find_package(gazebo REQUIRED)


find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED system filesystem date_time)

add_message_files(
  FILES
  StopRobot.msg
)

add_action_files(
  DIRECTORY action
  FILES
  RotateGripper.action
  ControlGripper.action
  MoveEndEffector.action
  MoveEndEffectorStraight.action
  MoveEndEffectorStraightNoRotation.action
)

generate_messages(
  DEPENDENCIES
  geometry_msgs
  actionlib_msgs
  std_msgs
)

catkin_package(
  LIBRARIES
  INCLUDE_DIRS
  CATKIN_DEPENDS
    geometry_msgs
    moveit_core
    moveit_visual_tools
    moveit_ros_planning_interface
    message_runtime
    interactive_markers
    tf2_geometry_msgs
    gazebo_ros
  DEPENDS
    EIGEN3
    gazebo
)

###########
## Build ##
###########

include_directories(
  ${THIS_PACKAGE_INCLUDE_DIRS} 
  ${catkin_INCLUDE_DIRS} 
  ${Boost_INCLUDE_DIR} 
  ${EIGEN3_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
  )

include_directories(
  include
  SYSTEM
  ${catkin_INCLUDE_DIRS}
)

add_executable(abb_controller 
                src/main.cpp 
                src/MoveEndEffectorServer.cpp 
                src/MoveEndEffectorStraightServer.cpp
                src/MoveEndEffectorStraightNoRotationServer.cpp
                src/ControlGripperServer.cpp
                src/RotateGripperServer.cpp
                src/StopRobotServer.cpp
)

target_link_libraries(abb_controller ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${GAZEBO_LIBRARIES} )

install(TARGETS abb_controller RUNTIME DESTINATION bin DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch RUNTIME DESTINATION bin DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

add_dependencies(
  abb_controller
  ${abb_controller_EXPORTED_TARGETS}
)