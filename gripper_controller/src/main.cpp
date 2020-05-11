#include <ros/ros.h>
#include "ControlGripperServer.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "gripper_controller");
  ros::AsyncSpinner spinner(1);
  spinner.start();
  ROS_ERROR("Initialized");
 
  ControlGripperServer controlGripperServer("ControlGripperAction", "192.168.125.1");

  ros::waitForShutdown();
  ROS_ERROR("POWEROFF");
  spinner.stop();
  return 0;
}