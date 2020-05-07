#include <ros/ros.h>
#include "ControlGripperServer.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "abb_controller");
  ros::AsyncSpinner spinner(1);
  spinner.start();
  ROS_ERROR("Initialized");
 
  ControlGripperServer controlGripperServer("ControlGripperAction2");

  while (ros::ok)
  {
  }

  return 0;
}