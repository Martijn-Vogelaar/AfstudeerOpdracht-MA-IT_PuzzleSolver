#include <ros/ros.h>
#include "ControlGripperServer.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "abb_controller");
  ros::AsyncSpinner spinner(1);
  spinner.start();
  ROS_ERROR("Initialized");
 
  ControlGripperServer controlGripperServer("ControlGripperAction");

  ros::waitForShutdown();
  ROS_ERROR("POWEROFF");
  spinner.stop();
  return 0;
}