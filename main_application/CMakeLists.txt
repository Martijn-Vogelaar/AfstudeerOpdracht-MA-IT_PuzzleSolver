cmake_minimum_required(VERSION 3.1.3)
project(main_application

)

add_compile_options(-std=c++14 -Wall -Wextra -Wconversion -O2)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(catkin REQUIRED
  COMPONENTS
    interactive_markers
    moveit_core
    moveit_visual_tools
    moveit_ros_planning
    moveit_ros_planning_interface
    moveit_ros_perception
    pluginlib
    geometric_shapes
    pcl_ros
    pcl_conversions
    rosbag
    tf2_ros
    tf2_eigen
    tf2_geometry_msgs
    roscpp
    abb_controller
    capacitive_sensor
    inductive_sensor
)

find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED system filesystem date_time thread)


catkin_package(
  LIBRARIES
  INCLUDE_DIRS
  CATKIN_DEPENDS
    moveit_core
    moveit_visual_tools
    moveit_ros_planning_interface
    interactive_markers
    tf2_geometry_msgs
    roscpp
  DEPENDS
    EIGEN3
)

catkin_package(
  INCLUDE_DIRS 
    include
    include/PlaceCorrectly
  LIBRARIES 
    lib_main
)

include_directories(
  ${THIS_PACKAGE_INCLUDE_DIRS} 
  ${catkin_INCLUDE_DIRS} 
  ${Boost_INCLUDE_DIR} 
  ${EIGEN3_INCLUDE_DIRS}
)


include_directories(
  include
  SYSTEM
  ${catkin_INCLUDE_DIRS}
)

add_library(lib_main
src/PlaceCorrectly/CheckCorrectlyRotated.cpp
src/PlaceCorrectly/CheckCorrectlyRotated.cpp
src/PlaceCorrectly/PlacePieceInPuzzle.cpp
src/PlaceCorrectly/RotatePieceOnPlace.cpp
src/PlaceCorrectly/LiftPiece.cpp
src/PlaceCorrectly/RotatePieceInAir.cpp
src/PlaceCorrectly/SubContext.cpp
src/PlaceCorrectly/SubState.cpp

src/Context.cpp
src/Poses.cpp
src/GrabPiece.cpp
src/PowerOff.cpp
src/Init.cpp
src/PutPieceInPickupPoint.cpp
src/Main.cpp
src/Ready.cpp
src/MoveRobotClient.cpp
src/RecognizePiece.cpp
src/MoveToRecognizedPiece.cpp
src/ReleasePiece.cpp
src/State.cpp
src/MoveUnknownPiece.cpp
src/TF2Handler.cpp
src/UnknownPieceInPickupPoint.cpp
src/PlacePiece.cpp
src/MoveToUnexploredSpot.cpp
src/ModelSpawner.cpp
src/Shapes.cpp
)

add_dependencies( lib_main
  ${catkin_EXPORTED_TARGETS}
)

add_executable(main_application 
  src/Main.cpp
)

target_link_libraries(main_application 
lib_main
${catkin_LIBRARIES}
)
