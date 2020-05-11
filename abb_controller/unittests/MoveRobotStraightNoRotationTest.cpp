#include "gtest/gtest.h"
#include <actionlib/client/simple_action_client.h>
#include <abb_controller_messages/MoveEndEffectorStraightNoRotationAction.h>

#define ACTION_STRAIGHT "MoveEndEffectorStraightNoRotationAction"


TEST(MoveRobotStraightNoRotation, MoveStraightNoRotation)
{
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorStraightNoRotationAction> actionClientStraight(ACTION_STRAIGHT);
    actionClientStraightNoRotation.waitForServer();

   abb_controller_messages::MoveEndEffectorStraightNoRotationGoal goal;
    goal.robotID = 1;
    goal.position.x = 0.424;
    goal.position.y = 0.1;
    goal.position.z = 0.65;
    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;

    actionClientStraightNoRotation.sendGoal(goal);
    actionClientStraightNoRotation.waitForResult();

    abb_controller_messages::MoveEndEffectorStraightNoRotationResultConstPtr result = actionClientStraightNoRotation.getResult();

    EXPECT_TRUE(result->success);
}

TEST(MoveRobotStraightNoRotation, MoveStraightNoRotation2)
{
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorStraightNoRotationAction> actionClientStraightNoRotation(ACTION_STRAIGHT);
    actionClientStraight.waitForServer();

   abb_controller_messages::MoveEndEffectorStraightNoRotationGoal goal;
    goal.robotID = 1;
    goal.position.x = 0.424;
    goal.position.y = 0.0;
    goal.position.z = 0.65;
    goal.orientation.x = 0;
    goal.orientation.y = 0;
    goal.orientation.z = 0;
    goal.orientation.w = 1;

    actionClientStraightNoRotation.sendGoal(goal);
    actionClientStraightNoRotation.waitForResult();

    abb_controller_messages::MoveEndEffectorStraightNoRotationResultConstPtr result = actionClientStraightNoRotation.getResult();

    EXPECT_TRUE(result->success);
}