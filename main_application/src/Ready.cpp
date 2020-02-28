#include "Ready.hpp"
#include <iostream>
#include <memory>

Ready::Ready()
{
}

Ready::~Ready() {}

void Ready::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Ready::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Ready::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
