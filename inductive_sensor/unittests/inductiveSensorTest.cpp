#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gmock/gmock-more-matchers.h"
#include <thread>
#include <ctime>
#include <algorithm>
#define private public
#include "InductiveSensor.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"

using testing::ElementsAreArray;

bool defaultReceived[4] = {false, false, false, false};
bool messagesReceived[4] = {false, false, false, false};

uint16_t noMeasurementsReceived = 0;
uint8_t measurementRate = 10;
uint16_t numberOfSensors = 4;

void measurementCallback(const inductive_sensor::inductive_sensor_measurementsConstPtr &msg)
{
    if (msg->id > 0 && msg->id <= numberOfSensors)
    {
        noMeasurementsReceived++;
        messagesReceived[msg->id - 1] = true;
    }
}

TEST(InductiveSensor, runMeasurement)
{
    noMeasurementsReceived = 0;
    std::copy(std::begin(defaultReceived), std::end(defaultReceived), std::begin(messagesReceived));
    InductiveSensor inductiveSensor(1, measurementRate);
    ros::NodeHandle nodeHandler;
    ros::Subscriber inductiveSensorMeasurementSubscriber = nodeHandler.subscribe("inductive_sensor", 1000, measurementCallback);
    std::thread inductiveSensorThread(&InductiveSensor::runMeasurement, &inductiveSensor);
    std::clock_t start;
    double duration;

    start = std::clock();
    while ((std::clock() - start) / (double)CLOCKS_PER_SEC < 2 && !std::all_of(
                                                                      std::begin(messagesReceived),
                                                                      std::end(messagesReceived),
                                                                      [](bool i) {
                                                                          return i; // or return !i ;
                                                                      }))
    {
        ros::spinOnce();
    }
    EXPECT_THAT(messagesReceived, ElementsAreArray({true, true, true, true}));
    EXPECT_EQ(noMeasurementsReceived, numberOfSensors);
    inductiveSensorThread.join();
}

TEST(InductiveSensor, runMeasurements)
{
    noMeasurementsReceived = 0;
    uint16_t loopDuration = 2;
    std::copy(std::begin(defaultReceived), std::end(defaultReceived), std::begin(messagesReceived));
    InductiveSensor inductiveSensor(1, measurementRate);
    ros::NodeHandle nodeHandler;
    ros::Subscriber inductiveSensorMeasurementSubscriber = nodeHandler.subscribe("inductive_sensor", 1000, measurementCallback);
    std::thread inductiveSensorThread(&InductiveSensor::runMeasurements, &inductiveSensor);
    std::clock_t start;
    double duration;

    start = std::clock();
    while ((std::clock() - start) / (double)CLOCKS_PER_SEC < loopDuration)
    {
        ros::spinOnce();
    }
    EXPECT_THAT(messagesReceived, ElementsAreArray({true, true, true, true}));
    EXPECT_NEAR(noMeasurementsReceived, measurementRate * loopDuration * numberOfSensors, numberOfSensors);
    ros::shutdown();
    inductiveSensorThread.join();
}
