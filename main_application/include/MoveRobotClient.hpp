#ifndef MOVE_ROBOT_CLIENT_HPP
#define MOVE_ROBOT_CLIENT_HPP

#include <actionlib/client/simple_action_client.h>
#include <abb_controller/MoveEndEffectorAction.h>
#include <abb_controller/MoveEndEffectorStraightAction.h>
#include <abb_controller/ControlGripperAction.h>
#include <abb_controller/RotateGripperAction.h>
#include <abb_controller/MoveEndEffectorStraightNoRotationAction.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>


#define ACTION_NORMAL "MoveEndEffectorAction"

#define ACTION_STRAIGHT "MoveEndEffectorStraightAction"

#define ACTION_STRAIGHT_NO_ROTATION "MoveEndEffectorStraightNoRotationAction"

#define ACTION_CONTROL_GRIPPER "ControlGripperAction"

#define ACTION_ROTATE_GRIPPER "RotateGripperAction"

class MoveRobotClient
{
private:
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorAction> actionClientNormal;
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorStraightAction> actionClientStraight;
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorStraightNoRotationAction> actionClientStraightNoRotation;
    actionlib::SimpleActionClient<abb_controller::ControlGripperAction> actionClientControlGripper;
    actionlib::SimpleActionClient<abb_controller::RotateGripperAction> actionClientRotateGripper;

public:
    void MoveRobotStraight(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    void MoveRobotStraightNoRotation(uint8_t aRobotID, geometry_msgs::Point aGoal);

    void MoveRobotNormal(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    void ControlGripper(uint8_t aRobotID, bool aOpen, uint8_t aPuzzleID);

    void RotateGripper(uint8_t aRobotID, double aRotation, bool async);

    MoveRobotClient();

    ~MoveRobotClient();
};

#endif //MOVE_ROBOT_CLIENT_HPP