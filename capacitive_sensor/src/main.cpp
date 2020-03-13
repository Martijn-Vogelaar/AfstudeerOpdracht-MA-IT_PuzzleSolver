#include "CapacitiveSensor.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "capacitive_sensor");
    if (argc == 2)
    {
        CapacitiveSensor capacitiveSensor = CapacitiveSensor((uint8_t)atoi(argv[1]),2);
        capacitiveSensor.runMeasurements(argc, argv);
        return 0;
    }
    else
    {
        return 1;
    }
}
