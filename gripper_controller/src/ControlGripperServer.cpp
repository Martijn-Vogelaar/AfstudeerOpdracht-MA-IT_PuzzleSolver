#include "ControlGripperServer.hpp"

#define MESSAGE_TYPE 0
#define PORT 2020

ControlGripperServer::ControlGripperServer(std::string aName, std::string aIpAddress) : actionServer(nodeHandler, aName, boost::bind(&ControlGripperServer::goalCallback, this, _1), false),
                                                                actionName(aName)
{
    ipAddres = boost::asio::ip::address::from_string(aIpAddress);
    actionServer.start();
}

ControlGripperServer::~ControlGripperServer()
{
}

void ControlGripperServer::goalCallback(const abb_controller_messages::ControlGripperGoalConstPtr &goal)
{
    std::array<char,2> request = {MESSAGE_TYPE,goal->open};
    boost::asio::ip::tcp::endpoint endpoint(ipAddres, PORT);
    boost::asio::io_service ios;	
     try{
            boost::asio::ip::tcp::socket socket(ios);

            socket.connect(endpoint);
            socket.write_some( boost::asio::buffer(request,sizeof(request)));

            std::array<char,2> response;
            socket.receive(boost::asio::buffer(response,sizeof(response)));
            socket.close();
            actionResult.robotID = goal->robotID;
            actionResult.open = response[1];
            actionResult.success = response[1] == goal->open;
            actionServer.setSucceeded(actionResult);
        }
        catch ( const boost::system::system_error& ex ){
            ROS_ERROR("Socket failure!");
            // throw 444;
        }
}
