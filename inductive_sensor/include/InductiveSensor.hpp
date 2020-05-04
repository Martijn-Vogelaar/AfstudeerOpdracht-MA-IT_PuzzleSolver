#include "ros/ros.h"
#include <stdint.h>


/**
 * @class InductiveSensor
 * 
 * @brief   The class InductiveSensor is a class which can be used in the simulation ONLY.
 *          It is able to simulate an inductive sensor by listening to a gazebo topic which
 *          is used to send images of a camera. It then translates these images to "sensor-
 *          readings" which are then send over a ros-topic 
 * 
 */

class InductiveSensor
{
public:
    /**
     * @brief Construct a new Inductive Sensor object
     * 
     * @param aId is used to listen to the correct topic and send sensor readings with the
     *        right id of the sensor.
     */
    InductiveSensor(uint8_t aId);

    /**
     * @brief Destroy the Inductive Sensor object
     * 
     */
    ~InductiveSensor();
    /**
     * @brief runMeasurements is a blocking function which listens to the gazebo topic 
     *        indefinitely 
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
};