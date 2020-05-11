#include "CapacitiveSensor.hpp"
#include "capacitive_sensor/capacitive_sensor_measurements.h"
#include <gazebo/gazebo_client.hh>

#define MAX_NUMBER_OF_SENSORS 8
#define MAX_DISTANCE_TO_BE_ACTIVE 0.025

CapacitiveSensor::CapacitiveSensor(uint8_t aId, uint8_t aNumberOfSensors) : id(aId), sensorValue(0), numberOfSensors(aNumberOfSensors)
{
    p = n.advertise<capacitive_sensor::capacitive_sensor_measurements>("capacitive_sensor", 1000);
    if (numberOfSensors > MAX_NUMBER_OF_SENSORS)
    {
        throw;
    }
}

CapacitiveSensor::~CapacitiveSensor()
{
}

void CapacitiveSensor::runMeasurements(int argc, char **argv)
{
    gazebo::client::setup(argc, argv);
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    std::vector<gazebo::transport::SubscriberPtr> subs;
    subs.resize(numberOfSensors);

    ros::Rate loop_rate(10);
    node->Init();
    for (uint8_t i = 0; i < numberOfSensors; ++i)
    {
        subs[i] = node->Subscribe(std::string(IMAGE_TOPIC_1 + std::to_string(i) + IMAGE_TOPIC_2), &CapacitiveSensor::distanceSensorCallback, this);
    }
    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
    gazebo::client::shutdown();
}

void CapacitiveSensor::distanceSensorCallback(ConstLaserScanStampedPtr &msg)
{
    int senderID = msg->scan().frame()[6] - '0'; //Temporary ugly solution
    if (msg->scan().ranges(0) <= MAX_DISTANCE_TO_BE_ACTIVE)
    {
        sensorValue |= (uint8_t)(1UL << senderID);
    }
    else
    {
        sensorValue &= (uint8_t)~(1UL << senderID);
    }

    capacitive_sensor::capacitive_sensor_measurements message;
    message.id = id;
    message.value = sensorValue;
    p.publish(message);
}