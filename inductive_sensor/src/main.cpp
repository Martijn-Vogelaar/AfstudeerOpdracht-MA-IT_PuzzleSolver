#include "InductiveSensor.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        ros::init(argc, argv, std::string("inductive_sensor" + std::string(argv[1])));
        InductiveSensor inductiveSensor((uint8_t)atoi(argv[1]), (uint8_t)atoi(argv[2]));
        inductiveSensor.runMeasurements();
        return 0;
    }
    else
    {
        ROS_ERROR("Incorrect number of arguments!");
        return 1;
    }
}
