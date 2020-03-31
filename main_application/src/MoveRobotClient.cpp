#include "MoveRobotClient.hpp"

MoveRobotClient::MoveRobotClient() : actionClientNormal(ACTION_NORMAL), actionClientStraight(ACTION_STRAIGHT)
{
    actionClientNormal.waitForServer();
    actionClientStraight.waitForServer();
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
