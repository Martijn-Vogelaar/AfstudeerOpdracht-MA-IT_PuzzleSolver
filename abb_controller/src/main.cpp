#include <ros/ros.h>
#include "MoveEndEffectorServer.hpp"
#include "MoveEndEffectorStraightServer.hpp"
#include "MoveEndEffectorStraightNoRotationServer.hpp"
#include "RotateGripperServer.hpp"
#include "StopRobotServer.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "abb_controller");
  ros::AsyncSpinner spinner(1);
  spinner.start();
  MoveEndEffectorServer moveNormalServer("MoveEndEffectorAction");

  MoveEndEffectorStraightServer moveStraightServer("MoveEndEffectorStraightAction");
  MoveEndEffectorStraightNoRotationServer moveStraightNoRotationServer("MoveEndEffectorStraightNoRotationAction");
  RotateGripperServer rotateGripperServer("RotateGripperAction");
  StopRobotServer stopRobotServer;

  ros::waitForShutdown();
  ROS_ERROR("POWEROFF");
  spinner.stop();

  return 0;
}