#include "RotateGripperServer.hpp"
#include <std_msgs/Float64.h>

RotateGripperServer::RotateGripperServer(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&RotateGripperServer::goalCallback, this, _1), false), move_group(PLANNING_GROUP),
                                                              actionName(aName)
{
    actionServer.start();
}

RotateGripperServer::~RotateGripperServer()
{
}

void RotateGripperServer::goalCallback(const abb_controller::RotateGripperGoalConstPtr &goal)
{
    double rotation = goal->rotation;
    std::vector<double> joints;
    joints = move_group.getCurrentJointValues();
    joints.at(5) = rotation;
    move_group.setJointValueTarget(joints);
    move_group.move();
    actionResult.robotID = goal->robotID;
    actionResult.rotation = rotation;
    actionResult.success = true;
    actionServer.setSucceeded(actionResult);
}
