#include "ros/ros.h"
#include <stdint.h>

/**
 * @class CapacitiveSensor
 * 
 * @brief   The class CapacitiveSensor is a class which can be used in the simulation ONLY.
 *          It is able to simulate a set of Capacitive sensors by listening to a gazebo topic which
 *          is used to send distance measurements. It then translates these measurements to a "sensor-
 *          reading" which are then send over a ros-topic. The node combines at most 8 different sensors
 *          to one value.
 * 
 */

class CapacitiveSensor
{
public:
    /**
     * @brief Construct a new Capacitive Sensor object
     * 
     * @param aId is used to listen to the correct topic and send sensor readings with the
     *        right id of the sensor.
     * 
     * @param aNumberOfSensors is used to determine the number of sensors this node needs to listen to.
     *        The max number of sensors is 8 and the minimum is 1.

     */


    CapacitiveSensor(uint8_t aId);

    /**
     * @brief Destroy the Capacitive Sensor object
     * 
     */
    ~CapacitiveSensor();
    /**
     * @brief runMeasurements is a blocking function which listens to the gazebo topic 
     *        indefinitely. 
     * 
     * @param argc 
     * @param argv 
     */
    void runMeasurements();

private:
    /**
     * @brief id is used to listen to the correct topic and send sensor readings with the
     *        right id of the sensor.
     */
    uint8_t id;

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
};