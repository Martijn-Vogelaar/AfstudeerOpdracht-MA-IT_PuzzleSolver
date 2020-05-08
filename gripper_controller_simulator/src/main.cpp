#include <ros/ros.h>
#include "ControlGripperServerSimulator.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "gripper_controller_simulator");
  ros::AsyncSpinner spinner(1);
  spinner.start();
  ROS_ERROR("Initialized");
 
  ControlGripperServerSimulator controlGripperServer("ControlGripperAction");

  ros::waitForShutdown();
  ROS_ERROR("POWEROFF");
  spinner.stop();
  return 0;
}