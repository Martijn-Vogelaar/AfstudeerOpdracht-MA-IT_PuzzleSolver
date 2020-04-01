#ifndef MOVE_ROBOT_CLIENT_HPP
#define MOVE_ROBOT_CLIENT_HPP

#include <actionlib/client/simple_action_client.h>
#include <abb_controller/MoveEndEffectorAction.h>
#include <abb_controller/MoveEndEffectorStraightAction.h>
#include <abb_controller/ControlGripperAction.h>
#include <geometry_msgs/Pose.h>

#define ACTION_NORMAL "MoveEndEffectorAction"

#define ACTION_STRAIGHT "MoveEndEffectorStraightAction"

#define ACTION_CONTROL_GRIPPER "ControlGripperAction"

class MoveRobotClient
{
private:
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorAction> actionClientNormal;
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorStraightAction> actionClientStraight;
    actionlib::SimpleActionClient<abb_controller::ControlGripperAction> actionClientControlGripper;

public:
    void MoveRobotStraight(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    void MoveRobotNormal(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    void ControlGripper(uint8_t aRobotID, bool aOpen);

    MoveRobotClient();

    ~MoveRobotClient();
};

#endif //MOVE_ROBOT_CLIENT_HPP