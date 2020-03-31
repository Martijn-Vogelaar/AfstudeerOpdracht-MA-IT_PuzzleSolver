#ifndef MOVE_ROBOT_CLIENT_HPP
#define MOVE_ROBOT_CLIENT_HPP

#include <actionlib/client/simple_action_client.h>
#include <abb_controller/MoveEndEffectorAction.h>
#include <abb_controller/MoveEndEffectorStraightAction.h>
#include <geometry_msgs/Pose.h>

#define ACTION_NORMAL "MoveEndEffectorAction"

#define ACTION_STRAIGHT "MoveEndEffectorStraightAction"

class MoveRobotClient
{
private:
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorAction> actionClientNormal;
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorStraightAction> actionClientStraight;

public:
    void MoveRobotStraight(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    void MoveRobotNormal(uint8_t aRobotID, geometry_msgs::Pose aGoal);

    MoveRobotClient();

    ~MoveRobotClient();
};

#endif //MOVE_ROBOT_CLIENT_HPP