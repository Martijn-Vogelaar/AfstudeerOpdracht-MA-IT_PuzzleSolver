#include "MoveRobotClient.hpp"

MoveRobotClient::MoveRobotClient() : actionClientNormal(ACTION_NORMAL), actionClientStraight(ACTION_STRAIGHT)
{
    actionClientNormal.waitForServer();
    actionClientStraight.waitForServer();
}

MoveRobotClient::~MoveRobotClient()
{
}

void MoveRobotClient::MoveRobotStraight(uint8_t robotID, double x1, double y1, double z1, double x2, double y2, double z2, double w)
{
    abb_controller::MoveEndEffectorStraightGoal goal;
    goal.robotID = robotID;
    goal.position.x = x1;
    goal.position.y = y1;
    goal.position.z = z1;
    goal.orientation.x = x2;
    goal.orientation.y = y2;
    goal.orientation.z = z2;
    goal.orientation.w = w;

    actionClientStraight.sendGoal(goal);
    actionClientStraight.waitForResult();

    abb_controller::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();
}

void MoveRobotClient::MoveRobotNormal(uint8_t robotID, double x1, double y1, double z1, double x2, double y2, double z2, double w)
{
    abb_controller::MoveEndEffectorGoal goal;
    goal.robotID = robotID;
    goal.position.x = x1;
    goal.position.y = y1;
    goal.position.z = z1;
    goal.orientation.x = x2;
    goal.orientation.y = y2;
    goal.orientation.z = z2;
    goal.orientation.w = w;

    actionClientNormal.sendGoal(goal);

    actionClientNormal.waitForResult();

    abb_controller::MoveEndEffectorResultConstPtr result = actionClientNormal.getResult();
}
