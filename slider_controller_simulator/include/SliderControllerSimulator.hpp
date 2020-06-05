#ifndef SLIDER_CONTROLLER_SIMULATOR_HPP
#define SLIDER_CONTROLLER_SIMULATOR_HPP

#include "ros/ros.h"
#include <stdint.h>
#include <actionlib/client/simple_action_client.h>
#include "slider_controller_simulator/control_slider.h"
#include "gazebo/gazebo.hh"
#include <gazebo/physics/physics.hh>
#include "gazebo/physics/PhysicsTypes.hh"
#include <gazebo/transport/TransportTypes.hh>
#include <gazebo/common/Time.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/common/Events.hh>
#include "gazebo/msgs/msgs.hh"
#include "gazebo/transport/transport.hh"
#include "ModelSpawner.hpp"

#define SLIDER_TOPIC "control_slider"

using namespace gazebo;

/**
 * @class SliderControllerSimulator
 * 
 * @brief  The SliderControllerSimulator is a plugin for gazebo which listens to a topic and open/closes the simulated slider depending on the content of the message.
 * 
 */

class SliderControllerSimulator : public WorldPlugin 
{
public:
    /**
     * @brief Construct a new Slider Controller object
     * 
     * @param aId is used to listen to the correct topic and send sensor readings with the
     *        right id of the sensor.
     */
    SliderControllerSimulator();

    /**
     * @brief Destroy the Slider Controller object
     * 
     */
    ~SliderControllerSimulator();

    /**
     * @brief Load is the function called when the plugin is loaded.
     * 
     * @param _world 
     */
    void Load(physics::WorldPtr _world, sdf::ElementPtr);

private:

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

    ros::Subscriber controlSliderSubscriber;

    void requestCallback(const slider_controller_simulator::control_sliderConstPtr &msg);

    physics::PhysicsEnginePtr physics;

    physics::WorldPtr world;

    ModelSpawner modelSpawner;
};

#endif //SLIDER_CONTROLLER_SIMULATOR_HPP