#include "CheckCorrectlyRotated.hpp"
#include <iostream>
#include <memory>

CheckCorrectlyRotated::CheckCorrectlyRotated()
{
}

CheckCorrectlyRotated::~CheckCorrectlyRotated() {}

void CheckCorrectlyRotated::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void CheckCorrectlyRotated::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void CheckCorrectlyRotated::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
