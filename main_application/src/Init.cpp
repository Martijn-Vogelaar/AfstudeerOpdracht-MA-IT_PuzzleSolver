#include "Init.hpp"
#include <iostream>
#include <memory>

Init::Init()
{
}

Init::~Init() {}

void Init::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Init::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Init::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
