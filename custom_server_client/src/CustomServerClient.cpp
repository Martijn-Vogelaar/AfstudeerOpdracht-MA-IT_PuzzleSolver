#include "CustomServerClient.hpp"

#define MESSAGE_TYPE 1
#define IP "192.168.125.1"
#define PORT 2020

CustomServerClient::CustomServerClient(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&CustomServerClient::goalCallBack, this, _1), false),
                                                            actionName(aName),
                                                            endpoint(boost::asio::ip::address::from_string(IP), PORT), ios(), socket(ios)
{
    socket.connect(endpoint);
    actionServer.start();
}

CustomServerClient::~CustomServerClient()
{
    socket.close();
}

void CustomServerClient::goalCallBack(const custom_server_client::TcpIpGoalConstPtr &goal)
{
    try
    {
        socket.write_some(boost::asio::buffer(goal->request));
        std::vector<int8_t> response;
        std::array<int8_t, 1> size;
        socket.receive(boost::asio::buffer(size, sizeof(size)));

        response.resize(size[0]);
        socket.receive(boost::asio::buffer(response));

        actionResult.response = response;
        actionServer.setSucceeded(actionResult);
    }
    catch (const boost::system::system_error &ex)
    {
        ROS_ERROR("Socket failure!");
        ROS_ERROR(ex.what());
    }
}
