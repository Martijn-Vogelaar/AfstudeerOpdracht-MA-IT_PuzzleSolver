#include "PowerOff.hpp"
#include "Context.hpp"
#include <memory>

PowerOff::PowerOff()
{
}

PowerOff::~PowerOff() {}

void PowerOff::entryAction(Context *)
{
}

void PowerOff::doActivity(Context *)
{
    ROS_ERROR("Poweroff!");
}

void PowerOff::exitAction(Context *)
{
}
