#ifndef STOP_ROBOT_HPP
#define STOP_ROBOT_HPP

// Local
#include "abb_simulator_controller/StopRobot.h"

#include <moveit/move_group_interface/move_group_interface.h>


#define PLANNING_GROUP "manipulator"

#define STOP_ROBOT_TOPIC "StopRobot"

#define QUEUE_SIZE 1000

/**
   * @class StopRobotServer
   *
   * @brief StopRobotServer is the class which handles requests to stop a robot.
   *
   */
class StopRobotServer
{
public:
    /**
     * @brief Construct a new Stop Robot object
     * 
     */
    StopRobotServer();
    /**
     * @brief Destroy the Stop Robot object
     * 
     */
    ~StopRobotServer();

private:
    ros::Subscriber stopRobotSubscriber;
    ros::NodeHandle nodeHandler;
    moveit::planning_interface::MoveGroupInterface move_group;

    /**
     * @brief Callback function which is called when any node uses sends an StopRobot message.
     * 
     * @param msg is the message send by the node.
     */
    void stopRobotCallback(const abb_simulator_controller::StopRobotConstPtr &msg);
};
#endif // STOP_ROBOT_HPP