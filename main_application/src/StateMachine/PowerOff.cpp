#include "PowerOff.hpp"
#include "Context.hpp"
#include "Poses.hpp"
#include <memory>

PowerOff::PowerOff()
{
}

PowerOff::~PowerOff() {}

void PowerOff::entryAction(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    ROS_ERROR("Poweroff!");
}

void PowerOff::doActivity(Context *)
{
}

void PowerOff::exitAction(Context *)
{
}
