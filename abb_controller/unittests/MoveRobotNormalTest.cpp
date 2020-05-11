#include "gtest/gtest.h"
#include <actionlib/client/simple_action_client.h>
#include <abb_controller_messages/MoveEndEffectorAction.h>

#define ACTION_NORMAL "MoveEndEffectorAction"


TEST(MoveRobotNormal, MoveNormal)
{
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorAction> actionClientNormal(ACTION_NORMAL);
    actionClientNormal.waitForServer();

    abb_controller_messages::MoveEndEffectorGoal goal;
    goal.robotID = 1;
    goal.position.x = 0.424;
    goal.position.y = 0;
    goal.position.z = 0.65;
    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;

    actionClientNormal.sendGoal(goal);

    actionClientNormal.waitForResult();

    abb_controller_messages::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();

    EXPECT_TRUE(result->success);
}

TEST(MoveRobotNormal, MoveNormal2)
{
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorAction> actionClientNormal(ACTION_NORMAL);
    actionClientNormal.waitForServer();

    abb_controller_messages::MoveEndEffectorGoal goal;
    goal.robotID = 1;
    goal.position.x = 0.424;
    goal.position.y = 0;
    goal.position.z = 0.62;
    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;

    actionClientNormal.sendGoal(goal);

    actionClientNormal.waitForResult();

    abb_controller_messages::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();

    EXPECT_TRUE(result->success);
}

TEST(MoveRobotNormal, MoveNormal3)
{
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorAction> actionClientNormal(ACTION_NORMAL);
    actionClientNormal.waitForServer();

    abb_controller_messages::MoveEndEffectorGoal goal;
    goal.robotID = 1;
    goal.position.x = 0.424;
    goal.position.y = 0;
    goal.position.z = 0.65;
    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;

    actionClientNormal.sendGoal(goal);

    actionClientNormal.waitForResult();

    abb_controller_messages::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();

    EXPECT_TRUE(result->success);
}