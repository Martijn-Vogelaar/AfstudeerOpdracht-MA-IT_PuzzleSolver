#include "SliderController.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        ros::init(argc, argv, std::string("slider_controller" + std::string(argv[1])));
        SliderController sliderController((uint8_t)atoi(argv[1]));
        ros::spin();
        return 0;
    }
    else
    {
        ROS_ERROR("Incorrect number of arguments!");
        return 1;
    }
}
