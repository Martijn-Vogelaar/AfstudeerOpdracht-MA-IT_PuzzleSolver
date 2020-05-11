#include "gtest/gtest.h"
#include <actionlib/client/simple_action_client.h>
#include <abb_controller_messages/RotateGripperAction.h>

#define ACTION_ROTATE_GRIPPER "RotateGripperAction"

TEST(GripperRotateTest, rotateToPointSynchronous)
{
    actionlib::SimpleActionClient<abb_controller_messages::RotateGripperAction> actionClientRotateGripper(ACTION_ROTATE_GRIPPER);
    actionClientRotateGripper.waitForServer();

    abb_controller_messages::RotateGripperGoal goal;
    goal.robotID = 0;
    goal.rotation = 2.5;
    goal.async = false;
    goal.increase = false;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller_messages::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();

    EXPECT_TRUE(result->success);
}

TEST(GripperRotateTest, rotateToPointASynchronous)
{
    actionlib::SimpleActionClient<abb_controller_messages::RotateGripperAction> actionClientRotateGripper(ACTION_ROTATE_GRIPPER);
    actionClientRotateGripper.waitForServer();

    abb_controller_messages::RotateGripperGoal goal;
    goal.robotID = 0;
    goal.rotation = -2.5;
    goal.async = true;
    goal.increase = false;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller_messages::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();

    EXPECT_TRUE(result->success);
    sleep(1);
}

TEST(GripperRotateTest, increaseRotationSynchronous)
{
    actionlib::SimpleActionClient<abb_controller_messages::RotateGripperAction> actionClientRotateGripper(ACTION_ROTATE_GRIPPER);
    actionClientRotateGripper.waitForServer();

    abb_controller_messages::RotateGripperGoal goal;
    goal.robotID = 0;
    goal.rotation = 0.5;
    goal.async = false;
    goal.increase = true;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller_messages::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();

    EXPECT_TRUE(result->success);
}

TEST(GripperRotateTest, increaseRotationASynchronous)
{
    actionlib::SimpleActionClient<abb_controller_messages::RotateGripperAction> actionClientRotateGripper(ACTION_ROTATE_GRIPPER);
    actionClientRotateGripper.waitForServer();

    abb_controller_messages::RotateGripperGoal goal;
    goal.robotID = 0;
    goal.rotation = -0.5;
    goal.async = true;
    goal.increase = true;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller_messages::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();

    EXPECT_TRUE(result->success);
    sleep(1);
}




TEST(GripperRotateTest, testMinimumBound)
{
    actionlib::SimpleActionClient<abb_controller_messages::RotateGripperAction> actionClientRotateGripper(ACTION_ROTATE_GRIPPER);
    actionClientRotateGripper.waitForServer();

    abb_controller_messages::RotateGripperGoal goal;
    goal.robotID = 0;
    goal.rotation = -20.5;
    goal.async = true;
    goal.increase = false;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller_messages::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();

    EXPECT_FALSE(result->success);
}

TEST(GripperRotateTest, testMaximumbound)
{
    actionlib::SimpleActionClient<abb_controller_messages::RotateGripperAction> actionClientRotateGripper(ACTION_ROTATE_GRIPPER);
    actionClientRotateGripper.waitForServer();

    abb_controller_messages::RotateGripperGoal goal;
    goal.robotID = 0;
    goal.rotation = 20.5;
    goal.async = true;
    goal.increase = false;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller_messages::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();

    EXPECT_FALSE(result->success);
}