#include "InductiveSensor.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"
#include <boost/asio.hpp>
#include <array>

#define MESSAGE_TYPE 2
#define LOOP_RATE 1
#define IP "192.168.125.1"
#define PORT 2020

InductiveSensor::InductiveSensor(uint8_t aId) : id(aId)
{
    p = n.advertise<inductive_sensor::inductive_sensor_measurements>("inductive_sensor", 1000);
}

InductiveSensor::~InductiveSensor()
{
}

void InductiveSensor::runMeasurements()
{
    ros::Rate r(LOOP_RATE); // 10 hz

    while (ros::ok())
    {
        r.sleep();
    }
}

void InductiveSensor::runMeasurement()
{
    std::array<char, 2> request = {MESSAGE_TYPE, id};
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(IP), PORT);
    boost::asio::io_service ios;
    try
    {
        boost::asio::ip::tcp::socket socket(ios);

        socket.connect(endpoint);
        socket.write_some(boost::asio::buffer(request, sizeof(request)));

        std::array<char, 2> response;
        socket.receive(boost::asio::buffer(response, sizeof(response)));

        inductive_sensor::inductive_sensor_measurements message;
        message.id = id;
        message.activated = response[1];
        p.publish(message);
        socket.close();
    }
    catch (const boost::system::system_error &ex)
    {
        ROS_ERROR("Socket failure!");
    }
}
