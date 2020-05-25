#ifndef SLIDER_CONTROLLER_HPP
#define SLIDER_CONTROLLER_HPP

#include "ros/ros.h"
#include <stdint.h>
#include <actionlib/client/simple_action_client.h>
#include "custom_server_client/TcpIpAction.h"
#include "slider_controller/control_slider.h"


#define TCP_IP_ACTION "customServerClient"
#define SLIDER_TOPIC "control_slider"


/**
 * @class SliderController
 * 
 * @brief  
 * 
 */

class SliderController
{
public:
    /**
     * @brief Construct a new Slider Controller object
     * 
     * @param aId is used to listen to the correct topic and send sensor readings with the
     *        right id of the sensor.
     */
    SliderController(uint8_t aId);

    /**
     * @brief Destroy the Slider Controller object
     * 
     */
    ~SliderController();


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

    actionlib::SimpleActionClient<custom_server_client::TcpIpAction> tcpIpActionClient;
    ros::Subscriber controlSliderSubscriber;

    void requestCallback(const slider_controller::control_sliderConstPtr& msg);
};

#endif //SLIDER_CONTROLLER_HPP