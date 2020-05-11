cmake_minimum_required(VERSION 2.8.3)
project(pickuppoint)

find_package(catkin REQUIRED)

catkin_package()

install(DIRECTORY urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})


  find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    rosbag
    tf2
    tf2_ros
    tf2_eigen
    tf2_geometry_msgs
)


catkin_package(
  LIBRARIES
  INCLUDE_DIRS
  CATKIN_DEPENDS
    tf2_geometry_msgs
)

include_directories(${THIS_PACKAGE_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})


install(DIRECTORY launch RUNTIME DESTINATION bin DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(PickuppointBroadcaster src/PickuppointBroadcaster.cpp)
target_link_libraries(PickuppointBroadcaster  ${catkin_LIBRARIES} )