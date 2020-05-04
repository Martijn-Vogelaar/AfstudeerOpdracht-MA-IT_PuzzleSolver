#include "MoveEndEffectorServer.hpp"

MoveEndEffectorServer::MoveEndEffectorServer(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&MoveEndEffectorServer::goalCallback, this, _1), false), move_group(PLANNING_GROUP),
                                                                  actionName(aName)
{
    actionServer.start();
}

MoveEndEffectorServer::~MoveEndEffectorServer()
{
}

void MoveEndEffectorServer::goalCallback(const abb_simulator_controller::MoveEndEffectorGoalConstPtr &goal)
{
    geometry_msgs::Pose goalPose;
    goalPose.position = goal->position;
    goalPose.orientation = goal->orientation;
    actionResult.success = executeMovement(goalPose);

    geometry_msgs::Pose currentPose = move_group.getCurrentPose().pose;
    actionResult.robotID = goal->robotID;
    actionResult.position = currentPose.position;
    actionResult.orientation = currentPose.orientation;
    actionServer.setSucceeded(actionResult);
}

bool MoveEndEffectorServer::executeMovement(geometry_msgs::Pose goalPose)
{
    move_group.setPoseTarget(goalPose);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;

    bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

    if (success)
    {
        move_group.move();

        // TODO
        // Implement feedback during movement
    }
    return success;
}
