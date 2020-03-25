#ifndef MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP
#define MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP

#include "MoveEndEffectorServer.hpp"

class MoveEndEffectorStraightServer : public MoveEndEffectorServer
{
protected:
    bool executeMovement(geometry_msgs::Pose goalPose);

public:
    MoveEndEffectorStraightServer(std::string name);

    ~MoveEndEffectorStraightServer();
};

#endif //MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP