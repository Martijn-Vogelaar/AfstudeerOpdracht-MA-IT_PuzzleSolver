#include "gtest/gtest.h"
#define protected public
#include "ControlGripperServer.hpp"
#include <abb_controller_messages/ControlGripperAction.h>

TEST(ControlGripper, openGripper)
{
    ControlGripperServer gripperServer("gripperServer");
    abb_controller_messages::ControlGripperGoal msg;
    msg.robotID = 0;
    msg.open = true;
    msg.puzzleID = 0;
    abb_controller_messages::ControlGripperGoalConstPtr goal(new abb_controller_messages::ControlGripperGoal(msg));
    gripperServer.goalCallback(goal);
    EXPECT_TRUE(gripperServer.actionResult.success);
    EXPECT_EQ(msg.open, gripperServer.actionResult.open);
}

TEST(ControlGripper, closeGripper)
{
    ControlGripperServer gripperServer("gripperServer");
    abb_controller_messages::ControlGripperGoal msg;
    msg.robotID = 0;
    msg.open = false;
    msg.puzzleID = 0;
    abb_controller_messages::ControlGripperGoalConstPtr goal(new abb_controller_messages::ControlGripperGoal(msg));
    gripperServer.goalCallback(goal);
    EXPECT_TRUE(gripperServer.actionResult.success);
    EXPECT_EQ(msg.open, gripperServer.actionResult.open);
}