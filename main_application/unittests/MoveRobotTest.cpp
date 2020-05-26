#include "gtest/gtest.h"
#include "Poses.hpp"
#include "MoveRobotClient.hpp"

TEST(Puzzle, moveRobotToHome)
{
    MoveRobotClient moveRobotClient;
    bool result = moveRobotClient.MoveRobotNormal(0, ROBOT_HOME_POSE2);
    EXPECT_TRUE(result);
}

TEST(Puzzle, moveRobotStraight)
{
    MoveRobotClient moveRobotClient;
    geometry_msgs::Pose goal = ROBOT_HOME_POSE2;
    goal.position.y = goal.position.y + 0.05;
    goal.position.z = goal.position.z + 0.05;

    bool result = moveRobotClient.MoveRobotStraight(0, goal);
    EXPECT_TRUE(result);
}

TEST(Puzzle, rotateGripper)
{
    MoveRobotClient moveRobotClient;
    bool result = moveRobotClient.RotateGripper(0, 1, 1, false, true);
    EXPECT_TRUE(result);
}

TEST(Puzzle, moveRobotStraightNoRotation)
{
    MoveRobotClient moveRobotClient;
    bool result = moveRobotClient.MoveRobotStraightNoRotation(0, ROBOT_HOME_POSE2.position);
    EXPECT_TRUE(result);
}

TEST(Puzzle, rotateGripperAsynchronous)
{
    MoveRobotClient moveRobotClient;
    bool result = moveRobotClient.RotateGripper(0, -2,0.2, true, true);
    EXPECT_TRUE(result);
}

TEST(Puzzle, controlGripper)
{
    MoveRobotClient moveRobotClient;
    bool result1 = moveRobotClient.ControlGripper(0, true, 0);
    ros::Duration(1).sleep();
    bool result2 = moveRobotClient.ControlGripper(0, false, 0);
    EXPECT_TRUE(result1);
    EXPECT_TRUE(result2);
}