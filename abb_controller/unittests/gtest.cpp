#include <gtest/gtest.h>
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

  testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  spinner.stop();
  return result;
}