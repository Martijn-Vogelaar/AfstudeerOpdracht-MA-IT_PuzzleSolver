#include "CapacitiveSensor.hpp"
#include "Capacitive_sensor/capacitive_sensor_measurements.h"
#include <gazebo/gazebo_client.hh>

#define MAX_NUMBER_OF_SENSORS 8
#define MAX_DISTANCE_TO_BE_ACTIVE 0.08

CapacitiveSensor::CapacitiveSensor(uint8_t aId, uint8_t aNumberOfSensors) : id(aId), sensorValue(0), numberOfSensors(aNumberOfSensors)
{
    p = n.advertise<capacitive_sensor::capacitive_sensor_measurements>("capacitive_sensor", 1000);
    if(sensorValue > MAX_NUMBER_OF_SENSORS){
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

        gazebo::common::Time::MSleep(10);
        ros::spinOnce();
        loop_rate.sleep();
    }
    gazebo::client::shutdown();
}

void CapacitiveSensor::distanceSensorCallback(ConstLaserScanStampedPtr &msg)
{

    uint8_t id = (uint8_t)msg->scan().frame()[6] - 48;  //Temporary ugly solution
    if (msg->scan().ranges(0) <= MAX_DISTANCE_TO_BE_ACTIVE)
    {
        sensorValue |= (1u << id);
    }
    else
    {
        sensorValue &= (0u << id);
    }
    capacitive_sensor::capacitive_sensor_measurements message;
    message.id = id;
    message.value = sensorValue;
    p.publish(message);
}