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

void RotateGripperServer::goalCallback(const abb_controller_messages::RotateGripperGoalConstPtr &goal)
{
    std::vector<double> joints;
    joints = move_group.getCurrentJointValues();
    move_group.setMaxVelocityScalingFactor(goal->speedFactor);
    double originalJoint = joints.at(GRIPPER_JOINT_INDEX);
    if (goal->increase)
    {
        joints.at(GRIPPER_JOINT_INDEX) += goal->rotation;
    }
    else
    {
        joints.at(GRIPPER_JOINT_INDEX) = goal->rotation;
    }
    actionResult.success = false;
    if (joints.at(GRIPPER_JOINT_INDEX) > MAX_JOINT_BOUND)
    {
        ROS_WARN("Reached maximum bounds! Not moving!");
        joints.at(GRIPPER_JOINT_INDEX) = originalJoint;
    }
    else if (joints.at(GRIPPER_JOINT_INDEX) < MIN_JOIN_BOUND)
    {
        ROS_WARN("Reached minimumbounds! Not moving!");
        joints.at(GRIPPER_JOINT_INDEX) = originalJoint;
    }
    else
    {
        move_group.setJointValueTarget(joints);
        if (goal->async)
        {
            move_group.asyncMove();
            actionResult.success = true;
        }
        else
        {
            move_group.move();
            actionResult.success = true;
        }
    }
    actionResult.robotID = goal->robotID;
    actionResult.rotation = joints.at(GRIPPER_JOINT_INDEX);
    actionServer.setSucceeded(actionResult);
}
