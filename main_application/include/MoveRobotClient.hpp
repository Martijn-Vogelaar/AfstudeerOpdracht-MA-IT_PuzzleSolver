#ifndef MOVE_ROBOT_CLIENT_HPP
#define MOVE_ROBOT_CLIENT_HPP

#include <actionlib/client/simple_action_client.h>
#include <abb_controller/MoveEndEffectorAction.h>
#include <abb_controller/MoveEndEffectorStraightAction.h>
#include <abb_controller/ControlGripperAction.h>
#include <abb_controller/RotateGripperAction.h>
#include <geometry_msgs/Pose.h>

#define ACTION_NORMAL "MoveEndEffectorAction"

#define ACTION_STRAIGHT "MoveEndEffectorStraightAction"

#define ACTION_CONTROL_GRIPPER "ControlGripperAction"

#define ACTION_ROTATE_GRIPPER "RotateGripperAction"


class MoveRobotClient
{
private:
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorAction> actionClientNormal;
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorStraightAction> actionClientStraight;
    actionlib::SimpleActionClient<abb_controller::ControlGripperAction> actionClientControlGripper;
    actionlib::SimpleActionClient<abb_controller::RotateGripperAction> actionClientRotateGripper;

public:
    void MoveRobotStraight(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    void MoveRobotNormal(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    void ControlGripper(uint8_t aRobotID, bool aOpen);

    void RotateGripper(uint8_t aRobotID, double aRotation);

    MoveRobotClient();

    ~MoveRobotClient();
};

#endif //MOVE_ROBOT_CLIENT_HPP