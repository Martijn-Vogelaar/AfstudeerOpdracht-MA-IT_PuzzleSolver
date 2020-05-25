#include <iostream>
#include "Context.hpp"
#include "Poses.hpp"
#include <memory>
#include "ros/ros.h"
#include "PowerOff.hpp"
int main(int argc, char **argv)
{
    initializePoses();
    ros::init(argc, argv, "main_application");
    ros::start();
    Context context;
    while (ros::ok() && typeid(*context.getCurrentState()) != typeid(PowerOff))
    {
        context.run();
        ros::spinOnce();
    }
    return 0;
}