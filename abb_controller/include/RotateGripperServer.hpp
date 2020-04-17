#ifndef ROTATE_GRIPPER_SERVER_HPP
#define ROTATE_GRIPPER_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller/RotateGripperAction.h>

#include <moveit/move_group_interface/move_group_interface.h>

#define PLANNING_GROUP "manipulator"

#define GRIPPER_JOINT_INDEX 5

#define MAX_JOINT_BOUND 6.98132

#define MIN_JOIN_BOUND -6.98132

/**
 * @class RotateGripperServer
 * 
 * @brief The class RotateGripperServer is a class which can be used to catch action requests from the RotateGripper action.
 *        The class handles the incoming requests and provides feedback during the handling of the requests. Eventually
 *        a result will be presented to the node which send the request.
 * 
 */ 

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
    /**
     * @brief Construct a new Rotate Gripper Server object
     * 
     * @param name Name which will be used to present this node to ROS
     */
    RotateGripperServer(std::string name);

    /**
     * @brief Destroy the Rotate Gripper Server object
     * 
     */
    ~RotateGripperServer();

    /**
     * @brief Callback function which is called when any node uses the RotateGripper action.
     * 
     * @param goal Message with the request of the action.
     */
    void goalCallback(const abb_controller::RotateGripperGoalConstPtr &goal);
};

#endif //ROTATE_GRIPPER_SERVER_HPP