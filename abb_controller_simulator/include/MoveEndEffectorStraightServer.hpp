#ifndef MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP
#define MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller_messages/MoveEndEffectorStraightAction.h>

#include <moveit/move_group_interface/move_group_interface.h>

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
    actionlib::SimpleActionServer<abb_controller_messages::MoveEndEffectorStraightAction> actionServer;
    std::string actionName;
    abb_controller_messages::MoveEndEffectorStraightFeedback actionFeedback;
    abb_controller_messages::MoveEndEffectorStraightResult actionResult;
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
    void goalCallback(const abb_controller_messages::MoveEndEffectorStraightGoalConstPtr &goal);
};


#endif //MOVE_END_EFFECTOR_STRAIGHT_SERVER_HPP