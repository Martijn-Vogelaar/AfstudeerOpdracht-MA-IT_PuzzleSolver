#include "CustomServerClient.hpp"

/**
 * @brief main functin which is called from start of the application
 * 
 * @param argc number of arguments
 * @param argv argv[1] should contain the ID of the sensor, argv[2] should contain the number of sensor which are used.
 * @return int 
 */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "custom_server_client");

    CustomServerClient customServerClient("customServerClient");
    ros::AsyncSpinner spinner(1);
    spinner.start();
    ros::waitForShutdown();
    spinner.stop();
    return 0;
}
