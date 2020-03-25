#include "MoveEndEffectorStraightServer.hpp"

MoveEndEffectorStraightServer::MoveEndEffectorStraightServer(std::string name) : MoveEndEffectorServer(name){

}

MoveEndEffectorStraightServer::~MoveEndEffectorStraightServer(){

}

bool MoveEndEffectorStraightServer::executeMovement(geometry_msgs::Pose goalPose)
{
    bool success = false;
    std::vector<geometry_msgs::Pose> waypoints;

    waypoints.push_back(goalPose);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;

    moveit_msgs::RobotTrajectory trajectory;
    const double jump_threshold = 0.0;
    const double eef_step = 0.01;
    double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
    success = fraction > -1.0;
    if (success)
    {
        my_plan.trajectory_ = trajectory;
        move_group.execute(my_plan);
    }
    return success;
}
