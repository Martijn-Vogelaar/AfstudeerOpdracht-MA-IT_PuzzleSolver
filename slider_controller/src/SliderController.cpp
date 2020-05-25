#include "SliderController.hpp"
#include <array>

#define MESSAGE_TYPE 3

SliderController::SliderController(uint8_t aId) : id(aId), tcpIpActionClient(TCP_IP_ACTION)
{
    tcpIpActionClient.waitForServer();
    controlSliderSubscriber = n.subscribe(SLIDER_TOPIC, 1000, &SliderController::requestCallback, this);
}

SliderController::~SliderController()
{
}

void SliderController::requestCallback(const slider_controller::control_sliderConstPtr &msg)
{
    custom_server_client::TcpIpGoal goal;
    goal.request.push_back(MESSAGE_TYPE);
    goal.request.push_back(msg->open);
    tcpIpActionClient.sendGoal(goal);
    tcpIpActionClient.waitForResult(ros::Duration(0));
    custom_server_client::TcpIpResultConstPtr result = tcpIpActionClient.getResult();
}
