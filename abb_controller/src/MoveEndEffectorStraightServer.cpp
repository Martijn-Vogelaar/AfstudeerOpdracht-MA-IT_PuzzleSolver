#include "MoveEndEffectorStraightServer.hpp"

MoveEndEffectorStraightServer::MoveEndEffectorStraightServer(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&MoveEndEffectorStraightServer::goalCallback, this, _1), false), move_group(PLANNING_GROUP),
                                                                                  actionName(aName)
{
    actionServer.start();
    move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
}

MoveEndEffectorStraightServer::~MoveEndEffectorStraightServer()
{
}

void MoveEndEffectorStraightServer::goalCallback(const abb_controller_messages::MoveEndEffectorStraightGoalConstPtr &goal)
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

bool MoveEndEffectorStraightServer::executeMovement(geometry_msgs::Pose goalPose)
{

    bool success = false;
    std::vector<geometry_msgs::Pose> waypoints;
    waypoints.push_back(goalPose);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit_msgs::RobotTrajectory trajectory;
    const double jump_threshold = 0.0;
    const double eef_step = 0.001;

    double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
    success = fraction > -1.0;
    moveit::planning_interface::MoveItErrorCode status;

    if (success)
    {

        my_plan.trajectory_ = trajectory;

        status = move_group.execute(my_plan);

    }
    if (status != moveit_msgs::MoveItErrorCodes::SUCCESS)
    {
        success = false;
        ROS_ERROR("We failed and caught it!");
    }
    return success;
}
