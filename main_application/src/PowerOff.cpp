#include "PowerOff.hpp"
#include <iostream>
#include <memory>

PowerOff::PowerOff()
{
}

PowerOff::~PowerOff() {}

void PowerOff::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PowerOff::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PowerOff::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
