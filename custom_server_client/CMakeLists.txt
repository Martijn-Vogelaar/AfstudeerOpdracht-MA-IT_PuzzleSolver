cmake_minimum_required(VERSION 3.7.2)
project(custom_server_client)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options( -Wall -Wconversion -Wextra -std=c++14)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()


find_package(catkin REQUIRED COMPONENTS
        message_runtime
        message_generation
        roscpp
        sensor_msgs
        std_msgs
        actionlib 
        actionlib_msgs
        )
        
find_package(Boost REQUIRED COMPONENTS
  system
  filesystem
  unit_test_framework
  regex
  signals
)

find_package(gazebo REQUIRED)


add_action_files(
  DIRECTORY action
  FILES
  TcpIp.action
)

generate_messages(
  DEPENDENCIES
  std_msgs
  actionlib_msgs
)



include_directories(
        include
        SYSTEM # everything after system is seen as system include (no compiler warnings)
        ${catkin_INCLUDE_DIRS})
		
catkin_package(
    DEPENDS
    message_runtime
    roscpp
    )

add_executable(${PROJECT_NAME}_plugin src/main.cpp src/CustomServerClient.cpp)

add_dependencies(${PROJECT_NAME}_plugin ${catkin_EXPORTED_TARGETS} capacitive_sensor_generate_messages_cpp)

		
target_link_libraries(${PROJECT_NAME}_plugin
        ${catkin_LIBRARIES}
        )