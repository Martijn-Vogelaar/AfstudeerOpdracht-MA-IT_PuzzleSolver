#include "StopRobotServer.hpp"


StopRobotServer::StopRobotServer() : move_group(PLANNING_GROUP)
{
    stopRobotSubscriber = nodeHandler.subscribe(STOP_ROBOT_TOPIC, QUEUE_SIZE, &StopRobotServer::stopRobotCallback, this);
}

StopRobotServer::~StopRobotServer() {}

void StopRobotServer::stopRobotCallback(const abb_simulator_controller::StopRobotConstPtr &msg)
{
        ROS_ERROR("Stop message received!");
        if(msg->stop){
            move_group.stop();
        }
}
