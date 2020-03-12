#include "ros/ros.h"
#include <stdint.h>
#include <opencv2/opencv.hpp>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/transport/transport.hh>

#define IMAGE_TOPIC_1 "/gazebo/default/sensor/" 
#define IMAGE_TOPIC_2 "/link/webcam/image"

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
    void runMeasurements(int argc, char **argv);

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
     * @brief Is activated is used to "translate" an image to a sensor reading.
     * 
     * @param image 
     * @return true is returned when the sensor is fully covered by a red area.
     * @return false is returned when the sensor is partially or not covered by a red area.
     */
    bool isActivated(cv::Mat image);

    /**
     * @brief This camera callback function is called everytime gazebo posts an image on the topic.
     * 
     * @param msg 
     */
    void cameraCallback(ConstImageStampedPtr &msg);
};