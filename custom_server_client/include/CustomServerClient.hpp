#ifndef CUSTOM_SERVER_CLIENT_HPP
#define CUSTOM_SERVER_CLIENT_HPP

#include "ros/ros.h"
#include <stdint.h>
#include <boost/asio.hpp>
#include <actionlib/server/simple_action_server.h>
#include <custom_server_client/TcpIpAction.h> 


class CustomServerClient
{
public:
    /**
     * @brief Construct a new Capacitive Sensor object
     * 
     * 
     */

    CustomServerClient(std::string name);

    /**
     * @brief Destroy the Capacitive Sensor object
     * 
     */
    ~CustomServerClient();

    /**
     * @brief Callback function which is called.
     * 
     * @param goal Message with the request of the action.
     */
    void goalCallBack(const custom_server_client::TcpIpGoalConstPtr &goal);

private:
    ros::NodeHandle nodeHandler;
    actionlib::SimpleActionServer<custom_server_client::TcpIpAction> actionServer;
    std::string actionName;
    custom_server_client::TcpIpFeedback actionFeedback;
    custom_server_client::TcpIpResult actionResult;
    /**
     * @brief n which is a nodeHandle is used to communicate using ROS
     * 
     */
    ros::NodeHandle n;

    /**
     * @brief p which is a publisher is used to be able to publish messages on a ROS-topic.
     * 
     */
    ros::Publisher p;

    /**
     * @brief sensorValue holds the last known values of all sensors.
     * 
     * @details 0 means no sensors active
     *          1 means sensor number 1 active
     *          2 means sensor number 2 active
     *          4 means sensor number 3 is active
     *          8 means sensor number 4 is active
     *          a combination of these numbers means that a combination of sensors is active.
     * 
     */
    uint8_t sensorValue;

    boost::asio::ip::tcp::endpoint endpoint;
    boost::asio::io_service ios;
    boost::asio::ip::tcp::socket socket;

    void runMeasurement();
};

#endif