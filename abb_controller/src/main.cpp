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
  ROS_ERROR(" HERE");
    MoveEndEffectorServer moveNormalServer("MoveEndEffectorAction");
      ROS_ERROR(" HERE2");

  MoveEndEffectorStraightServer moveStraightServer("MoveEndEffectorStraightAction");
        ROS_ERROR(" HER3");
MoveEndEffectorStraightNoRotationServer moveStraightNoRotationServer("MoveEndEffectorStraightNoRotationAction");
        ROS_ERROR(" HERE4");
RotateGripperServer rotateGripperServer("RotateGripperAction");
  StopRobotServer stopRobotServer;

  ros::waitForShutdown();
  ROS_ERROR("POWEROFF");
  spinner.stop();

  return 0;
}