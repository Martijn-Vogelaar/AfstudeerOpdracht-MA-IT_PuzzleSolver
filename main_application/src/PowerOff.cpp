#include "PowerOff.hpp"
#include "Context.hpp"
#include <memory>

PowerOff::PowerOff()
{
}

PowerOff::~PowerOff() {}

void PowerOff::entryAction(Context *)
{
    ROS_ERROR("Poweroff!");
}

void PowerOff::doActivity(Context *)
{
}

void PowerOff::exitAction(Context *)
{
}
