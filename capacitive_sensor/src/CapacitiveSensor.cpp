#include "CapacitiveSensor.hpp"
#include "capacitive_sensor/capacitive_sensor_measurements.h"

#define MESSAGE_TYPE 1
#define LOOP_RATE 1 //hz

CapacitiveSensor::CapacitiveSensor(uint8_t aId) : id(aId), sensorValue(0), tcpIpActionClient(TCP_IP_ACTION)
{
    tcpIpActionClient.waitForServer();
    p = n.advertise<capacitive_sensor::capacitive_sensor_measurements>("capacitive_sensor", 1000);
}

CapacitiveSensor::~CapacitiveSensor()
{
}

void CapacitiveSensor::runMeasurements()
{
    ros::Rate r(LOOP_RATE); // 10 hz

    while (ros::ok())
    {
        runMeasurement();
        r.sleep();
    }
}

void CapacitiveSensor::runMeasurement()
{
    custom_server_client::TcpIpGoal goal;
    goal.request.push_back(MESSAGE_TYPE);
    tcpIpActionClient.sendGoal(goal);
    tcpIpActionClient.waitForResult(ros::Duration(0));
    custom_server_client::TcpIpResultConstPtr result = tcpIpActionClient.getResult();
    capacitive_sensor::capacitive_sensor_measurements message;
    message.id = id;
    message.value = result->response[1];
    if (result->response[0] == MESSAGE_TYPE)
    {
        p.publish(message);
    }
}
