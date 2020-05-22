#include "MoveRobotClient.hpp"

MoveRobotClient::MoveRobotClient() : actionClientNormal(ACTION_NORMAL), actionClientStraight(ACTION_STRAIGHT), actionClientStraightNoRotation(ACTION_STRAIGHT_NO_ROTATION), actionClientControlGripper(ACTION_CONTROL_GRIPPER), actionClientRotateGripper(ACTION_ROTATE_GRIPPER)
{
    actionClientNormal.waitForServer();
    actionClientStraight.waitForServer();
    actionClientStraightNoRotation.waitForServer();
    actionClientControlGripper.waitForServer();
    actionClientRotateGripper.waitForServer();
}

MoveRobotClient::~MoveRobotClient()
{
}

bool MoveRobotClient::MoveRobotStraight(uint8_t aRobotID, geometry_msgs::Pose aGoal)
{
    abb_controller_messages::MoveEndEffectorStraightGoal goal;
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

    abb_controller_messages::MoveEndEffectorStraightResultConstPtr result = actionClientStraight.getResult();

    return result->success;
}

bool MoveRobotClient::MoveRobotStraightNoRotation(uint8_t aRobotID, geometry_msgs::Point aGoal)
{
    abb_controller_messages::MoveEndEffectorStraightNoRotationGoal goal;
    goal.robotID = aRobotID;
    goal.position.x = aGoal.x;
    goal.position.y = aGoal.y;
    goal.position.z = aGoal.z;

    actionClientStraightNoRotation.sendGoal(goal);
    actionClientStraightNoRotation.waitForResult();

    abb_controller_messages::MoveEndEffectorStraightNoRotationResultConstPtr result = actionClientStraightNoRotation.getResult();

    return result->success;
}

bool MoveRobotClient::MoveRobotNormal(uint8_t aRobotID, geometry_msgs::Pose aGoal)
{
    abb_controller_messages::MoveEndEffectorGoal goal;
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

    abb_controller_messages::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();

    return result->success;
}

bool MoveRobotClient::ControlGripper(uint8_t aRobotID, bool aOpen, uint8_t aPuzzleID)
{
    abb_controller_messages::ControlGripperGoal goal;
    goal.robotID = aRobotID;
    goal.open = aOpen;
    goal.puzzleID = aPuzzleID;
    actionClientControlGripper.sendGoal(goal);

    actionClientControlGripper.waitForResult();

    abb_controller_messages::ControlGripperResultConstPtr result = actionClientControlGripper.getResult();

    return result->success;
}

bool MoveRobotClient::RotateGripper(uint8_t aRobotID, double aRotation, double aSpeedfactor, bool async, bool increase)
{
    abb_controller_messages::RotateGripperGoal goal;
    goal.robotID = aRobotID;
    goal.rotation = aRotation;
    goal.speedFactor = aSpeedfactor;
    goal.async = async;
    goal.increase = increase;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller_messages::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();

    return result->success;
}
