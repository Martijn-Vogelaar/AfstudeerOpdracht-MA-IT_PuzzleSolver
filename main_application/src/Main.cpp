#include <iostream>
#include "Context.hpp"
#include "Poses.hpp"
#include <memory>
#include "ros/ros.h"

int main(int argc, char **argv)
{
    initializePoses();
    ros::init(argc, argv, "main_application");
    ros::start();
    std::shared_ptr<Context> lContext =
        std::make_shared<Context>();
    while(ros::ok()){
        lContext->run();
            ros::spinOnce();
    }
    return 0;
}