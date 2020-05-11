#include "gtest/gtest.h"
#include <thread>
#include <ctime>
#define private public
#include "InductiveSensor.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"


bool messageReceived = false;

void measurementCallback(const inductive_sensor::inductive_sensor_measurementsConstPtr &msg)
{
    if (msg->id == 1)
    {
        messageReceived = true;
    }
}

TEST(InductiveSensor, readmeasurement)
{
    InductiveSensor inductiveSensor(1);
    ros::NodeHandle nodeHandler;
    ros::Subscriber inductiveSensorMeasurementSubscriber = nodeHandler.subscribe("inductive_sensor", 1000, measurementCallback);
    std::thread inductiveSensorThread (&InductiveSensor::runMeasurement, &inductiveSensor);
    std::clock_t start;
    double duration;

    start = std::clock();
    while(( std::clock() - start ) / (double) CLOCKS_PER_SEC < 2 && !messageReceived){
        ros::spinOnce();
    }
    EXPECT_TRUE(messageReceived);
    messageReceived = false;
    inductiveSensorThread.join();
}

