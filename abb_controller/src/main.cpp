#include <ros/ros.h>
#include "MoveEndEffectorServer.hpp"
#include "MoveEndEffectorStraightServer.hpp"
#include "ControlGripperServer.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "MoveEndEffectorAction");
  ros::AsyncSpinner spinner(1);

  spinner.start();
  MoveEndEffectorServer server("MoveEndEffectorAction");
  MoveEndEffectorStraightServer server2("MoveEndEffectorStraightAction");
  ControlGripperServer server3("ControlGripperAction");
  while (ros::ok)
  {
  }

  return 0;
}