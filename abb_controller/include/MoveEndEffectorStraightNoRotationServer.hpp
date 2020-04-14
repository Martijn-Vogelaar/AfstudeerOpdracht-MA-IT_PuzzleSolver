#ifndef MOVE_END_EFFECTOR_STRAIGHT_NO_ROTATION_SERVER_HPP
#define MOVE_END_EFFECTOR_STRAIGHT_NO_ROTATION_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller/MoveEndEffectorStraightNoRotationAction.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <tf/transform_datatypes.h>
#define PLANNING_GROUP "manipulator"

class MoveEndEffectorStraightNoRotationServer
{
protected:
    moveit::planning_interface::MoveGroupInterface move_group;
    ros::NodeHandle nodeHandler;
    actionlib::SimpleActionServer<abb_controller::MoveEndEffectorStraightNoRotationAction> actionServer;
    std::string actionName;
    abb_controller::MoveEndEffectorStraightNoRotationFeedback actionFeedback;
    abb_controller::MoveEndEffectorStraightNoRotationResult actionResult;
    bool executeMovement(geometry_msgs::Pose goalPose);

public:
    MoveEndEffectorStraightNoRotationServer(std::string name);

    ~MoveEndEffectorStraightNoRotationServer();

    void goalCallback(const abb_controller::MoveEndEffectorStraightNoRotationGoalConstPtr &goal);
};


#endif //MOVE_END_EFFECTOR_STRAIGHT_NO_ROTATION_SERVER_HPP