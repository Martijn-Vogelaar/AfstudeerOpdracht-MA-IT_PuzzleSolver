#include <ros/ros.h>
#include "MoveEndEffectorServer.hpp"
#include "MoveEndEffectorStraightServer.hpp"
#include "MoveEndEffectorStraightNoRotationServer.hpp"
#include "ControlGripperServerSimulator.hpp"
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
  ControlGripperServerSimulator controlGripperServer("ControlGripperActionSim");
  RotateGripperServer rotateGripperServer("RotateGripperAction");
  StopRobotServer stopRobotServer;

  while (ros::ok)
  {
  }

  return 0;
}