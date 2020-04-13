#include "MoveRobotClient.hpp"

MoveRobotClient::MoveRobotClient() : actionClientNormal(ACTION_NORMAL), actionClientStraight(ACTION_STRAIGHT), actionClientControlGripper(ACTION_CONTROL_GRIPPER), actionClientRotateGripper(ACTION_ROTATE_GRIPPER)
{
    actionClientNormal.waitForServer();
    actionClientStraight.waitForServer();
    actionClientControlGripper.waitForServer();
    actionClientRotateGripper.waitForServer();
}

MoveRobotClient::~MoveRobotClient()
{
}

void MoveRobotClient::MoveRobotStraight(uint8_t aRobotID, geometry_msgs::Pose aGoal)
{
    abb_controller::MoveEndEffectorStraightGoal goal;
    goal.robotID = aRobotID;
    goal.position.x = aGoal.position.x;
    goal.position.y = aGoal.position.y;
    goal.position.z = aGoal.position.z;
    goal.orientation.x = aGoal.orientation.x;
    goal.orientation.y = aGoal.orientation.y;
    goal.orientation.z = aGoal.orientation.z;
    goal.orientation.w = aGoal.orientation.w;

    actionClientStraight.sendGoal(goal);
    actionClientStraight.waitForResult();

    abb_controller::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();
}

void MoveRobotClient::MoveRobotNormal(uint8_t aRobotID, geometry_msgs::Pose aGoal)
{
    abb_controller::MoveEndEffectorGoal goal;
    goal.robotID = aRobotID;
    goal.position.x = aGoal.position.x;
    goal.position.y = aGoal.position.y;
    goal.position.z = aGoal.position.z;
    goal.orientation.x = aGoal.orientation.x;
    goal.orientation.y = aGoal.orientation.y;
    goal.orientation.z = aGoal.orientation.z;
    goal.orientation.w = aGoal.orientation.w;

    actionClientNormal.sendGoal(goal);

    actionClientNormal.waitForResult();

    abb_controller::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();
}

void MoveRobotClient::ControlGripper(uint8_t aRobotID, bool aOpen, uint8_t aPuzzleID)
{
    abb_controller::ControlGripperGoal goal;
    goal.robotID = aRobotID;
    goal.open = aOpen;
    goal.puzzleID = aPuzzleID;
    actionClientControlGripper.sendGoal(goal);

    actionClientControlGripper.waitForResult();

    abb_controller::ControlGripperResultConstPtr result = actionClientControlGripper.getResult();
}

void MoveRobotClient::RotateGripper(uint8_t aRobotID, double aRotation)
{
    abb_controller::RotateGripperGoal goal;
    goal.robotID = aRobotID;
    goal.rotation = aRotation;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();
}
