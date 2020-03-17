#include <iostream>
#include "Context.hpp"
#include "Init.hpp"
#include <memory>
#include "ros/ros.h"

int main(int argc, char **argv)
{
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