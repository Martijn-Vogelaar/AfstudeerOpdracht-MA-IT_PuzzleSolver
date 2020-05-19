#include "InductiveSensor.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"
#include <array>

#define MESSAGE_TYPE 2
#define LOOP_RATE 1

InductiveSensor::InductiveSensor(uint8_t aId) : id(aId), tcpIpActionClient(TCP_IP_ACTION)
{
    tcpIpActionClient.waitForServer();
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
        runMeasurement();
        r.sleep();
    }
}

void InductiveSensor::runMeasurement()
{
    custom_server_client::TcpIpGoal goal;
    goal.request.push_back(MESSAGE_TYPE);
    goal.request.push_back((int8_t)id);
    tcpIpActionClient.sendGoal(goal);
    tcpIpActionClient.waitForResult();
    custom_server_client::TcpIpResultConstPtr result = tcpIpActionClient.getResult();
    inductive_sensor::inductive_sensor_measurements message;
    message.id = id;
    message.activated = result->response[1];
    if (result->response[0] == MESSAGE_TYPE)
    {
        p.publish(message);
    }

}
