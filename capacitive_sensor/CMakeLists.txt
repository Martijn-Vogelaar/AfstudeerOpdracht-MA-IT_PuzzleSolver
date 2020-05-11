cmake_minimum_required(VERSION 3.7.2)
project(capacitive_sensor)
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
        gazebo_msgs
        gazebo_plugins
        gazebo_ros
        message_runtime
        message_generation
        roscpp
        sensor_msgs
        std_msgs
        )
        
find_package(Boost REQUIRED COMPONENTS
  system
  filesystem
  unit_test_framework
  regex
  signals
)

find_package(gazebo REQUIRED)


add_message_files(
  FILES
  capacitive_sensor_measurements.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)


link_directories(${GAZEBO_LIBRARY_DIRS})

include_directories(
        include
        SYSTEM # everything after system is seen as system include (no compiler warnings)
        ${GAZEBO_INCLUDE_DIRS}
        ${catkin_INCLUDE_DIRS})
		
catkin_package(
    DEPENDS
    message_runtime
    roscpp
    gazebo_ros
    )

add_executable(${PROJECT_NAME}_plugin src/main.cpp src/CapacitiveSensor.cpp)

add_dependencies(${PROJECT_NAME}_plugin ${catkin_EXPORTED_TARGETS} capacitive_sensor_generate_messages_cpp)

		
target_link_libraries(${PROJECT_NAME}_plugin
        ${GAZEBO_LIBRARIES}
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
        )



include(CTest)
enable_testing()

catkin_add_gtest(${PROJECT_NAME}_unit_tests unittests/gtest.cpp unittests/capacitiveSensorTest.cpp src/CapacitiveSensor)
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