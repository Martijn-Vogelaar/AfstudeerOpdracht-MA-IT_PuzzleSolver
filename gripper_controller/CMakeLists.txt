cmake_minimum_required(VERSION 3.1.3)
project(gripper_controller)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(catkin REQUIRED
  COMPONENTS
    gazebo_ros
    interactive_markers
    moveit_core
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
    abb_controller_messages
)

find_package(gazebo REQUIRED)


find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED system filesystem date_time)




catkin_package(
  LIBRARIES
  INCLUDE_DIRS
  CATKIN_DEPENDS
    geometry_msgs
    moveit_core
    moveit_ros_planning_interface
    message_runtime
    interactive_markers
    tf2_geometry_msgs
    gazebo_ros
  DEPENDS
    EIGEN3
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

add_executable(gripper_controller 
                src/main.cpp 
                src/ControlGripperServer.cpp
)

target_link_libraries(gripper_controller ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${GAZEBO_LIBRARIES} )

install(TARGETS gripper_controller RUNTIME DESTINATION bin DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch RUNTIME DESTINATION bin DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

add_dependencies(
  gripper_controller
  ${catkin_EXPORTED_TARGETS}
)





#####Unittesting#####


include(CTest)
enable_testing()

catkin_add_gtest(${PROJECT_NAME}_unit_tests unittests/gtest.cpp unittests/controlGripperTest.cpp src/ControlGripperServer)
target_link_libraries(${PROJECT_NAME}_unit_tests  ${catkin_LIBRARIES})


if(CODE_COVERAGE)
  #We want to measure the codecoverage with a Debug build
  set(CMAKE_BUILD_TYPE Debug)


  include(../cmake/CodeCoverage.cmake)
    
  #Files which will be excluded for the codecoverage
  set(COVERAGE_LCOV_EXCLUDES
    '*/gtest/*'
    '/*/c++/*'
    '*/*.py'
    '*/unittests/*'
    '*/*main.cpp'
    '*/*Main.cpp'
    '*/ros/*'
    '*/boost/*'
    '*/devel/*'
  )

  APPEND_COVERAGE_COMPILER_FLAGS()


  SETUP_TARGET_FOR_COVERAGE_LCOV(
          NAME ${PROJECT_NAME}_coverage
          EXECUTABLE ctest -j ${n_cores}
          DEPENDENCIES
          ${PROJECT_NAME}_unit_tests
             )   
endif()