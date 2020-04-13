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
    // move_group.setMaxVelocityScalingFactor(0.2);
    std::vector<double> joints;
    joints = move_group.getCurrentJointValues();
    joints.at(GRIPPER_JOINT_INDEX) += goal->rotation;
    ROS_ERROR(std::string(std::to_string(joints.at(GRIPPER_JOINT_INDEX))).c_str());
    if (joints.at(GRIPPER_JOINT_INDEX) > MAX_JOINT_BOUND)
    {
        ROS_WARN("Reached maximum bounds! Moving to the maximum of 6.98132");
        joints.at(GRIPPER_JOINT_INDEX) = MAX_JOINT_BOUND;
    }
    else if (joints.at(GRIPPER_JOINT_INDEX) < MIN_JOIN_BOUND)
    {
        ROS_WARN("Reached minimumbounds! Moving to the minimum of -6.98132");
        joints.at(GRIPPER_JOINT_INDEX) = MIN_JOIN_BOUND;
    }
    move_group.setJointValueTarget(joints);
    move_group.asyncMove();
    actionResult.robotID = goal->robotID;
    actionResult.rotation = joints.at(GRIPPER_JOINT_INDEX);
    actionResult.success = true;
    actionServer.setSucceeded(actionResult);
}
