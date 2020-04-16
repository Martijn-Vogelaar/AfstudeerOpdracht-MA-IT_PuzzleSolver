#ifndef STOP_ROBOT_HPP
#define STOP_ROBOT_HPP

// Local
#include "abb_controller/StopRobot.h"
#include "ros/ros.h"


#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <tf/transform_datatypes.h>

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
    void stopRobotCallback(const abb_controller::StopRobotConstPtr &msg);
};
#endif // STOP_ROBOT_HPP