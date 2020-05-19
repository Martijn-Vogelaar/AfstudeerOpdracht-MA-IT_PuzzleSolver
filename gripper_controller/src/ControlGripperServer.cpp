#include "ControlGripperServer.hpp"

#define MESSAGE_TYPE 0 

ControlGripperServer::ControlGripperServer(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&ControlGripperServer::goalCallback, this, _1), false),
                                                                                        actionName(aName), tcpIpActionClient(TCP_IP_ACTION)
{
    tcpIpActionClient.waitForServer();
    actionServer.start();
}

ControlGripperServer::~ControlGripperServer()
{
}

void ControlGripperServer::goalCallback(const abb_controller_messages::ControlGripperGoalConstPtr &goal)
{
    custom_server_client::TcpIpGoal message;
    message.request.push_back(MESSAGE_TYPE);
    message.request.push_back((int8_t)goal->open);
    tcpIpActionClient.sendGoal(message);
    tcpIpActionClient.waitForResult();
    custom_server_client::TcpIpResultConstPtr result = tcpIpActionClient.getResult();
    actionResult.robotID = goal->robotID;
    if (result->response[0] == MESSAGE_TYPE)
    {
        actionResult.open = result->response[1];
        actionResult.success = result->response[1] == goal->open;
    }
    else
    {
        actionResult.success = false;
    }
    actionServer.setSucceeded(actionResult);
}
