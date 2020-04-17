#ifndef MOVE_END_EFFECTOR_STRAIGHT_NO_ROTATION_SERVER_HPP
#define MOVE_END_EFFECTOR_STRAIGHT_NO_ROTATION_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller/MoveEndEffectorStraightNoRotationAction.h>

#include <moveit/move_group_interface/move_group_interface.h>

#define PLANNING_GROUP "manipulator"


/**
 * @class MoveEndEffectorStraightNoRotationServer
 * 
 * @brief The class MoveEndEffectorStraightNoRotationServer is a class which can be used to catch action requests from the MoveEndEffectorStraightNoRotation action.
 *        The class handles the incoming requests and provides feedback during the handling of the requests. Eventually
 *        a result will be presented to the node which send the request.
 * 
 */ 

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
    /**
     * @brief Construct a new Move End Effector Straight No Rotation Server object
     * 
     * @param name Name which will be used to present this node to ROS
     */
    MoveEndEffectorStraightNoRotationServer(std::string name);


    /**
     * @brief Destroy the Move End Effector Straight No Rotation Server object
     * 
     */
    ~MoveEndEffectorStraightNoRotationServer();

    /**
     * @brief Callback function which is called when any node uses the MoveEndEffectorStraightNoRotation action.
     * 
     * @param goal Message with the request of the action.
     */
    void goalCallback(const abb_controller::MoveEndEffectorStraightNoRotationGoalConstPtr &goal);
};


#endif //MOVE_END_EFFECTOR_STRAIGHT_NO_ROTATION_SERVER_HPP