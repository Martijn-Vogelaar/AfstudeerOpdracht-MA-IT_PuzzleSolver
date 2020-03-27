#include "Ready.hpp"
#include <iostream>
#include <memory>
#include "PutPieceInPickupPoint.hpp"

Ready::Ready()
{
}

Ready::~Ready() {}

void Ready::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Ready::doActivity(Context* context)
{
    context->setState(std::make_shared<PutPieceInPickupPoint>());
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Ready::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
