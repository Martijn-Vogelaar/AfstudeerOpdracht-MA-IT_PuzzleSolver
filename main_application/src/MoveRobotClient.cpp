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

    abb_controller::MoveEndEffectorStraightResultConstPtr result = actionClientStraight.getResult();
    if (result->success)
    {
        ROS_ERROR("Success");
    }
}

void MoveRobotClient::MoveRobotStraightNoRotation(uint8_t aRobotID, geometry_msgs::Point aGoal)
{
    abb_controller::MoveEndEffectorStraightNoRotationGoal goal;
    goal.robotID = aRobotID;
    goal.position.x = aGoal.x;
    goal.position.y = aGoal.y;
    goal.position.z = aGoal.z;

    actionClientStraightNoRotation.sendGoal(goal);
    actionClientStraightNoRotation.waitForResult();

    abb_controller::MoveEndEffectorStraightNoRotationResultConstPtr result = actionClientStraightNoRotation.getResult();
    if (result->success)
    {
        ROS_ERROR("Success");
    }
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
    if (result->success)
    {
        ROS_ERROR("Success");
    }
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
    if (result->success)
    {
        ROS_ERROR("Success");
    }
}

void MoveRobotClient::RotateGripper(uint8_t aRobotID, double aRotation, bool async)
{
    abb_controller::RotateGripperGoal goal;
    goal.robotID = aRobotID;
    goal.rotation = aRotation;
    goal.async = async;
    actionClientRotateGripper.sendGoal(goal);

    actionClientRotateGripper.waitForResult();

    abb_controller::RotateGripperResultConstPtr result = actionClientRotateGripper.getResult();
    if (result->success)
    {
        ROS_ERROR("Success");
    }
}
