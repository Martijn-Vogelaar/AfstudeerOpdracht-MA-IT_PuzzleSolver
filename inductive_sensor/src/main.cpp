#include "InductiveSensor.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "inductive_sensor");
    if (argc == 2)
    {
        InductiveSensor inductiveSensor = InductiveSensor((uint8_t)atoi(argv[1]));
        inductiveSensor.runMeasurements(argc, argv);
        return 0;
    }
    else
    {
        return 1;
    }
}
