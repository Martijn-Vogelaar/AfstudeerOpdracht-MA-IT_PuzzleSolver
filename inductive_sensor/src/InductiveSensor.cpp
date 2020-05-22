#include "InductiveSensor.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"
#include <array>

#define MESSAGE_TYPE 2

InductiveSensor::InductiveSensor(uint8_t aId, uint8_t aLoopRate) : id(aId), loopRate(aLoopRate), tcpIpActionClient(TCP_IP_ACTION)
{
    tcpIpActionClient.waitForServer();
    p = n.advertise<inductive_sensor::inductive_sensor_measurements>("inductive_sensor", 1000);
}

InductiveSensor::~InductiveSensor()
{
}

void InductiveSensor::runMeasurements()
{
    ros::Rate r(loopRate);

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
    tcpIpActionClient.sendGoal(goal);
    tcpIpActionClient.waitForResult(ros::Duration(0));
    custom_server_client::TcpIpResultConstPtr result = tcpIpActionClient.getResult();
    for(size_t i = 1; i < result->response.size(); ++i){
    inductive_sensor::inductive_sensor_measurements message;
        message.id = i;
        message.activated = result->response[i];
        if (result->response[0] == MESSAGE_TYPE)
        {
            p.publish(message);
        }
    }
    

}
