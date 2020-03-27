#include "Init.hpp"
#include <iostream>
#include <memory>
#include "MoveRobotClient.hpp"
#include "Ready.hpp"

Init::Init()
{
}

Init::~Init() {}

void Init::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Init::doActivity(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, 0.424, 0, 0.65, 0, 0, 0, 1);
    context->setState(std::make_shared<Ready>());
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Init::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
