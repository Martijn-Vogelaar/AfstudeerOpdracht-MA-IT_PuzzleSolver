#include "ControlGripperServer.hpp"
#include <boost/asio.hpp>

#define MESSAGE_TYPE 0
#define IP "192.168.125.1"
#define PORT 2020

ControlGripperServer::ControlGripperServer(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&ControlGripperServer::goalCallback, this, _1), false),
                                                                actionName(aName)
{
    actionServer.start();
}

ControlGripperServer::~ControlGripperServer()
{
}

void ControlGripperServer::goalCallback(const abb_controller_messages::ControlGripperGoalConstPtr &goal)
{
    std::array<char,2> request = {MESSAGE_TYPE,goal->open};
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(IP), PORT);
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
        }
}
