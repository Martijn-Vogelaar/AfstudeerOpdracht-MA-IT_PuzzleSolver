cmake_minimum_required(VERSION 3.1.3)
project(main_application

)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wconversion -Wextra -std=c++14)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

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
    abb_simulator_controller
    capacitive_sensor_simulator
    inductive_sensor_simulator
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
    include/StateMachine
    include/StateMachine/PlaceCorrectly
  LIBRARIES 
    lib_main
)

include_directories(
  ${THIS_PACKAGE_INCLUDE_DIRS} 
  ${catkin_INCLUDE_DIRS} 
  ${Boost_INCLUDE_DIR} 
  ${EIGEN3_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR}
)


include_directories(
  include
  include/StateMachine
  include/StateMachine/PlaceCorrectly
  SYSTEM
  ${catkin_INCLUDE_DIRS}
)

add_executable(main_application 
                src/StateMachine/PlaceCorrectly/CheckCorrectlyRotated.cpp
                src/StateMachine/PlaceCorrectly/CheckCorrectlyRotated.cpp
                src/StateMachine/PlaceCorrectly/PlacePieceInPuzzle.cpp
                src/StateMachine/PlaceCorrectly/RotatePieceOnPlace.cpp
                src/StateMachine/PlaceCorrectly/LiftPiece.cpp
                src/StateMachine/PlaceCorrectly/RotatePieceInAir.cpp
                src/StateMachine/PlaceCorrectly/SubContext.cpp
                src/StateMachine/PlaceCorrectly/SubState.cpp

                src/StateMachine/Context.cpp
                src/StateMachine/GrabPiece.cpp
                src/StateMachine/PowerOff.cpp
                src/StateMachine/Init.cpp
                src/StateMachine/PutPieceInPickupPoint.cpp
                src/StateMachine/Ready.cpp
                src/StateMachine/RecognizePiece.cpp
                src/StateMachine/MoveToRecognizedPiece.cpp
                src/StateMachine/ReleasePiece.cpp
                src/StateMachine/State.cpp
                src/StateMachine/MoveUnknownPiece.cpp
                src/StateMachine/UnknownPieceInPickupPoint.cpp
                src/StateMachine/PlacePiece.cpp
                src/StateMachine/MoveToUnexploredSpot.cpp
                src/StateMachine/RemovePieceFromPuzzle.cpp

                src/Main.cpp
                src/ModelSpawner.cpp
                src/MoveRobotClient.cpp
                src/TF2Handler.cpp
                src/Shapes.cpp
                src/Puzzle.cpp
                src/PuzzlePieceSpot.cpp
                src/Poses.cpp

)

target_link_libraries(main_application 
${catkin_LIBRARIES}
${Boost_LIBRARIES} 
${GAZEBO_LIBRARIES} 
)
