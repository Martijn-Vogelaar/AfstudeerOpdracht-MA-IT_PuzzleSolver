#include "gtest/gtest.h"
#include <actionlib/client/simple_action_client.h>
#include <abb_controller_messages/MoveEndEffectorStraightAction.h>

#define ACTION_STRAIGHT "MoveEndEffectorStraightAction"


TEST(MoveRobotStraight, MoveStraight)
{
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorStraightAction> actionClientStraight(ACTION_STRAIGHT);
    actionClientStraight.waitForServer();

   abb_controller_messages::MoveEndEffectorStraightGoal goal;
    goal.robotID = 1;
    goal.position.x = 0.424;
    goal.position.y = 0.1;
    goal.position.z = 0.65;
    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;

    actionClientStraight.sendGoal(goal);
    actionClientStraight.waitForResult();

    abb_controller_messages::MoveEndEffectorStraightResultConstPtr result = actionClientStraight.getResult();

    EXPECT_TRUE(result->success);
}

TEST(MoveRobotStraight, MoveStraight2)
{
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorStraightAction> actionClientStraight(ACTION_STRAIGHT);
    actionClientStraight.waitForServer();

   abb_controller_messages::MoveEndEffectorStraightGoal goal;
    goal.robotID = 1;
    goal.position.x = 0.424;
    goal.position.y = 0.0;
    goal.position.z = 0.65;
    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;

    actionClientStraight.sendGoal(goal);
    actionClientStraight.waitForResult();

    abb_controller_messages::MoveEndEffectorStraightResultConstPtr result = actionClientStraight.getResult();

    EXPECT_TRUE(result->success);
}