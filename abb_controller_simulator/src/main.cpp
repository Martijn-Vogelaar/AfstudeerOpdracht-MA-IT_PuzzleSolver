#include <ros/ros.h>
#include "MoveEndEffectorServer.hpp"
#include "MoveEndEffectorStraightServer.hpp"
#include "MoveEndEffectorStraightNoRotationServer.hpp"
#include "ControlGripperServer.hpp"
#include "RotateGripperServer.hpp"
#include "StopRobotServer.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "abb_simulator_controller");
  ros::AsyncSpinner spinner(1);
  spinner.start();

  MoveEndEffectorServer moveNormalServer("MoveEndEffectorAction");
  MoveEndEffectorStraightServer moveStraightServer("MoveEndEffectorStraightAction");
  MoveEndEffectorStraightNoRotationServer moveStraightNoRotationServer("MoveEndEffectorStraightNoRotationAction");
  ControlGripperServer controlGripperServer("ControlGripperAction");
  RotateGripperServer rotateGripperServer("RotateGripperAction");
  StopRobotServer stopRobotServer;

  while (ros::ok)
  {
  }

  return 0;
}