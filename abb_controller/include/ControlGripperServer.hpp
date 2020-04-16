#ifndef CONTROL_GRIPPER_SERVER_HPP
#define CONTROL_GRIPPER_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller/ControlGripperAction.h>
#include <gazebo_ros_link_attacher/Attach.h>


/**
 * @class ControlGripperServer
 * 
 * @brief The class ControlGripperServer is a class which can be used to catch action requests from the ControlGripper action.
 *        The class handles the incoming requests and provides feedback during the handling of the requests. Eventually
 *        a result will be presented to the node which send the request.
 * 
 */
class ControlGripperServer
{
protected:
    ros::NodeHandle nodeHandler;
    ros::Publisher pub1, pub2, pub3;

    std::string actionName;
    actionlib::SimpleActionServer<abb_controller::ControlGripperAction> actionServer;

    ros::ServiceClient attachClient;
    ros::ServiceClient detachClient;

    abb_controller::ControlGripperFeedback actionFeedback;
    abb_controller::ControlGripperResult actionResult;

public:
    /**
     * @brief Construct a new Control Gripper Server object
     * 
     * @param name Name which will be used to present this node to ROS
     */
    ControlGripperServer(std::string name);

    /**
     * @brief Destroy the Control Gripper Server object
     * 
     */
    ~ControlGripperServer();

    /**
     * @brief Callback function which is called when any node uses the ControlGripper action.
     * 
     * @param goal Message with the request of the action.
     */
    void goalCallback(const abb_controller::ControlGripperGoalConstPtr &goal);
};

#endif //CONTROL_GRIPPER_SERVER_HPP