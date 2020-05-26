#include "gtest/gtest.h"
#include "TF2Handler.hpp"
#include "Poses.hpp"
#include <geometry_msgs/Pose.h>

TEST(TF2Test, transformToPuzzle)
{
    TF2Handler tf2Handler;
    geometry_msgs::Pose goal;
    goal.position.x = 0;
    goal.position.y = 0;
    goal.position.z = 0;

    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;
    geometry_msgs::Pose pose = tf2Handler.calculatePosition(PUZZLE, "world", goal);

    geometry_msgs::Pose expectedPose;
    expectedPose.position.x = 1;
    expectedPose.position.y = 0;
    expectedPose.position.z = 1;

    expectedPose.orientation.x = 0;
    expectedPose.orientation.y = 0;
    expectedPose.orientation.z = 0.47942553860420295;
    expectedPose.orientation.w = 0.87758256189037276;

    EXPECT_DOUBLE_EQ(expectedPose.position.x, pose.position.x);
    EXPECT_DOUBLE_EQ(expectedPose.position.y, pose.position.y);
    EXPECT_DOUBLE_EQ(expectedPose.position.z, pose.position.z);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.x, pose.orientation.x);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.y, pose.orientation.y);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.z, pose.orientation.z);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.w, pose.orientation.w);
}

TEST(TF2Test, transformToPickuppoint)
{
    TF2Handler tf2Handler;
    geometry_msgs::Pose goal;
    goal.position.x = 0;
    goal.position.y = 0;
    goal.position.z = 0;

    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;
    geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, "world", goal);

    geometry_msgs::Pose expectedPose;
    expectedPose.position.x = 1;
    expectedPose.position.y = 0;
    expectedPose.position.z = 0;

    expectedPose.orientation.x = 0;
    expectedPose.orientation.y = 0;
    expectedPose.orientation.z = 0.47942553860420295;
    expectedPose.orientation.w = 0.87758256189037276;
    EXPECT_DOUBLE_EQ(expectedPose.position.x, pose.position.x);
    EXPECT_DOUBLE_EQ(expectedPose.position.y, pose.position.y);
    EXPECT_DOUBLE_EQ(expectedPose.position.z, pose.position.z);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.x, pose.orientation.x);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.y, pose.orientation.y);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.z, pose.orientation.z);
    EXPECT_DOUBLE_EQ(expectedPose.orientation.w, pose.orientation.w);
}