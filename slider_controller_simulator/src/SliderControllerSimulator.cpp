#include "SliderControllerSimulator.hpp"

using namespace gazebo;

GZ_REGISTER_WORLD_PLUGIN(SliderControllerSimulator)

SliderControllerSimulator::SliderControllerSimulator() : WorldPlugin()
{
}

SliderControllerSimulator::~SliderControllerSimulator()
{
}

void SliderControllerSimulator::Load(physics::WorldPtr aWorld, sdf::ElementPtr)
{
    if (!ros::isInitialized())
    {
        ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
                         << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
        return;
    }
    world = aWorld;
    physics = world->Physics();
    controlSliderSubscriber = n.subscribe(SLIDER_TOPIC, 1000, &SliderControllerSimulator::requestCallback, this);
}

void SliderControllerSimulator::requestCallback(const slider_controller_simulator::control_sliderConstPtr &msg)
{
    if (msg->open)
    {
        while (world->ModelByName("pickuppoint")->GetJoint("pickuppoint_JOINT_1")->Position() < 0.22)
        {
            world->ModelByName("pickuppoint")->GetJoint("pickuppoint_JOINT_1")->SetVelocity(0, 0.3);
        }
    }
    else
    {
        while (world->ModelByName("pickuppoint")->GetJoint("pickuppoint_JOINT_1")->Position() > 0.01)
        {
            world->ModelByName("pickuppoint")->GetJoint("pickuppoint_JOINT_1")->SetVelocity(0, -0.05);
        }
        modelSpawner.spawnPuzzlePiece();
    }
    world->ModelByName("pickuppoint")->GetJoint("pickuppoint_JOINT_1")->SetForce(0, 0.0);
    world->ModelByName("pickuppoint")->GetJoint("pickuppoint_JOINT_1")->SetVelocity(0, 0.0);
}
