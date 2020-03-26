#include "ControlGripperServer.hpp"
#include <std_msgs/Float64.h>
ControlGripperServer::ControlGripperServer(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&ControlGripperServer::goalCallback, this, _1), false),
                                                                actionName(aName)
{
    pub1 = nodeHandler.advertise<std_msgs::Float64>("/joint7_controller/command", 1000);
    pub2 = nodeHandler.advertise<std_msgs::Float64>("/joint8_controller/command", 1000);
    pub3 = nodeHandler.advertise<std_msgs::Float64>("/joint9_controller/command", 1000);

    actionServer.start();
}

ControlGripperServer::~ControlGripperServer()
{
}

void ControlGripperServer::goalCallback(const abb_controller::ControlGripperGoalConstPtr &goal)
{
    uint8_t robotID = goal->robotID;
    bool open = goal->open;

    std_msgs::Float64 message;
    if (open)
    {
        message.data = 100;
    }
    else
    {
        message.data = -100;
    }

    pub1.publish(message);
    pub2.publish(message);
    pub3.publish(message);

    actionResult.robotID = goal->robotID;
    actionResult.open = !open;
    actionResult.success = true;
    actionServer.setSucceeded(actionResult);
}
