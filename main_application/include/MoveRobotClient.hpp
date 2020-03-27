#ifndef MOVE_ROBOT_CLIENT_HPP
#define MOVE_ROBOT_CLIENT_HPP

#include <actionlib/client/simple_action_client.h>
#include <abb_controller/MoveEndEffectorAction.h>
#include <abb_controller/MoveEndEffectorStraightAction.h>

#define ACTION_NORMAL "MoveEndEffectorAction"

#define ACTION_STRAIGHT "MoveEndEffectorStraightAction"

class MoveRobotClient
{
private:
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorAction> actionClientNormal;
    actionlib::SimpleActionClient<abb_controller::MoveEndEffectorStraightAction> actionClientStraight;

public:
    void MoveRobotStraight(uint8_t robotID, double x1, double y1, double z1, double x2, double y2, double z2, double w);

    void MoveRobotNormal(uint8_t robotID, double x1, double y1, double z1, double x2, double y2, double z2, double w);

    MoveRobotClient();

    ~MoveRobotClient();
};

#endif //MOVE_ROBOT_CLIENT_HPP