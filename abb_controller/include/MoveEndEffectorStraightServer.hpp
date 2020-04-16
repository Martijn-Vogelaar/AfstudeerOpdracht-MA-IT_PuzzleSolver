#ifndef MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP
#define MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller/MoveEndEffectorStraightAction.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <tf/transform_datatypes.h>
#define PLANNING_GROUP "manipulator"

/**
 * @class MoveEndEffectorStraightServer
 * 
 * @brief The class MoveEndEffectorStraightServer is a class which can be used to catch action requests from the MoveEndEffectorStraight action.
 *        The class handles the incoming requests and provides feedback during the handling of the requests. Eventually
 *        a result will be presented to the node which send the request.
 * 
 */ 

class MoveEndEffectorStraightServer
{
protected:
    moveit::planning_interface::MoveGroupInterface move_group;
    ros::NodeHandle nodeHandler;
    actionlib::SimpleActionServer<abb_controller::MoveEndEffectorStraightAction> actionServer;
    std::string actionName;
    abb_controller::MoveEndEffectorStraightFeedback actionFeedback;
    abb_controller::MoveEndEffectorStraightResult actionResult;
    bool executeMovement(geometry_msgs::Pose goalPose);

public:
    /**
     * @brief Construct a new Move End Effector Straight Server object
     * 
     * @param name Name which will be used to present this node to ROS
     */
    MoveEndEffectorStraightServer(std::string name);

    
    /**
     * @brief Destroy the Move End Effector Straight Server object
     * 
     */
    ~MoveEndEffectorStraightServer();

    /**
     * @brief Callback function which is called when any node uses the MoveEndEffector action.
     * 
     * @param goal Message with the request of the action.
     */
    void goalCallback(const abb_controller::MoveEndEffectorStraightGoalConstPtr &goal);
};


#endif //MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP