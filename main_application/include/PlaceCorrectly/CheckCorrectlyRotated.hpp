#ifndef CHECK_CORRECTLY_ROTATED_HPP
#define CHECK_CORRECTLY_ROTATED_HPP

// Local
#include "SubState.hpp"
#include "SubContext.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"
#include "capacitive_sensor/capacitive_sensor_measurements.h"
#include "abb_controller/StopRobot.h"
#include "ros/ros.h"
#include <map>

#define INDUCTIVE_TOPIC "inductive_sensor"

#define MIN_NR_OF_EQUAL_MEASUREMENTS 1

#define MIN_NR_OF_MEASUREMENTS 1

#define NR_OF_MEASUREMENTS 15

#define NR_OF_MEASUREMENTS_TIMEOUT 150


static const int allowedSensorIDs[] = {1, 3, 5, 9};

/**
   * @class CheckCorrectlyRotated
   *
   * @brief CheckCorrectlyRotated is the class which represents the CheckCorrectlyRotated SubState.
   *
   */
class CheckCorrectlyRotated : public SubState
{
public:
    /**
     * @brief Construct a new CheckCorrectlyRotated object
     *
     */
    CheckCorrectlyRotated();
    /**
     * @brief Destroy the CheckCorrectlyRotated object
     *
     */
    ~CheckCorrectlyRotated();
    /**
     * @brief entryAction is being called when the CheckCorrectlyRotated SubState is being entered.
     *
     * @details When the CheckCorrectlyRotated SubState is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(SubContext *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * CheckCorrectlyRotated.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(SubContext *aSubContext) override;
    /**
     * @brief exitAction is being called when the CheckCorrectlyRotated SubState is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(SubContext *aSubContext) override;

private:
    ros::Subscriber inductiveMeasurementSubscriber;
    ros::Publisher stopRobotPublisher;

    ros::NodeHandle nodeHandler;

    void measurementCallback(const inductive_sensor::inductive_sensor_measurementsConstPtr &msg);
    SubContext* subContext;
    uint16_t nonActivateCount;
    uint8_t puzzlePieceID;
};
#endif // CHECK_CORRECTLY_ROTATED_HPP