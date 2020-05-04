#include "CapacitiveSensor.hpp"

/**
 * @brief main functin which is called from start of the application
 * 
 * @param argc number of arguments
 * @param argv argv[1] should contain the ID of the sensor, argv[2] should contain the number of sensor which are used.
 * @return int 
 */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "capacitive_sensor");
    if (argc == 2)
    {
        CapacitiveSensor capacitiveSensor = CapacitiveSensor((uint8_t)atoi(argv[1]));
        capacitiveSensor.runMeasurements();
        return 0;
    }
    else
    {
        return 1;
    }
}
