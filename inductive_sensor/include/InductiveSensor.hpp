#include "ros/ros.h"
#include <stdint.h>
#include <actionlib/client/simple_action_client.h>
#include "custom_server_client/TcpIpAction.h"

#define TCP_IP_ACTION "customServerClient"


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
    InductiveSensor(uint8_t aId, uint8_t aLoopRate);

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
     * @brief loopRate is used to set the speed of which the sensor's status should be retrieved and published.
     * 
     */
    uint8_t loopRate;

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

    actionlib::SimpleActionClient<custom_server_client::TcpIpAction> tcpIpActionClient;

    void runMeasurement();
};