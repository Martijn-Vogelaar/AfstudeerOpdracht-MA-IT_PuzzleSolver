#ifndef CONTROL_GRIPPER_SERVER_HPP
#define CONTROL_GRIPPER_SERVER_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller/ControlGripperAction.h>

class ControlGripperServer
{
protected:
    ros::NodeHandle nodeHandler;
    actionlib::SimpleActionServer<abb_controller::ControlGripperAction> actionServer;
    ros::Publisher pub1, pub2, pub3;

    std::string actionName;
    abb_controller::ControlGripperFeedback actionFeedback;
    abb_controller::ControlGripperResult actionResult;

public:
    ControlGripperServer(std::string name);

    ~ControlGripperServer();

    void goalCallback(const abb_controller::ControlGripperGoalConstPtr &goal);
};

#endif //CONTROL_GRIPPER_SERVER_HPP