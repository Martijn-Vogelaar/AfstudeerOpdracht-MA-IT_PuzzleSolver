#ifndef ROTATE_GRIPPER_SERVER_HPP
#define ROTATE_GRIPPER_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller/RotateGripperAction.h>
#include <gazebo_ros_link_attacher/Attach.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <tf/transform_datatypes.h>

#define PLANNING_GROUP "manipulator"

#define GRIPPER_JOINT_INDEX 5

#define MAX_JOINT_BOUND 6.98132

#define MIN_JOIN_BOUND -6.98132

class RotateGripperServer
{
protected:
    ros::NodeHandle nodeHandler;
    moveit::planning_interface::MoveGroupInterface move_group;

    std::string actionName;
    actionlib::SimpleActionServer<abb_controller::RotateGripperAction> actionServer;


    abb_controller::RotateGripperFeedback actionFeedback;
    abb_controller::RotateGripperResult actionResult;

public:
    RotateGripperServer(std::string name);

    ~RotateGripperServer();

    void goalCallback(const abb_controller::RotateGripperGoalConstPtr &goal);
};

#endif //ROTATE_GRIPPER_SERVER_HPP