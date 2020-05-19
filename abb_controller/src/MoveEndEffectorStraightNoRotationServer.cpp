#include "MoveEndEffectorStraightNoRotationServer.hpp"

MoveEndEffectorStraightNoRotationServer::MoveEndEffectorStraightNoRotationServer(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&MoveEndEffectorStraightNoRotationServer::goalCallback, this, _1), false), move_group(PLANNING_GROUP),
                                                                                                      actionName(aName)
{
    actionServer.start();
    move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
}

MoveEndEffectorStraightNoRotationServer::~MoveEndEffectorStraightNoRotationServer()
{
}

void MoveEndEffectorStraightNoRotationServer::goalCallback(const abb_controller_messages::MoveEndEffectorStraightNoRotationGoalConstPtr &goal)
{
    geometry_msgs::Pose goalPose;
    goalPose.position = goal->position;
    goalPose.orientation = move_group.getCurrentPose().pose.orientation;

    actionResult.success = executeMovement(goalPose);

    actionResult.robotID = goal->robotID;
    actionResult.position = move_group.getCurrentPose().pose.position;
    actionServer.setSucceeded(actionResult);
}

bool MoveEndEffectorStraightNoRotationServer::executeMovement(geometry_msgs::Pose goalPose)
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
        ROS_ERROR("We failed and caught it!1");
    }
    return success;
}
