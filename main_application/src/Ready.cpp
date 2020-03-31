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
}

void Ready::doActivity(Context* context)
{
    context->setState(std::make_shared<PutPieceInPickupPoint>());
}

void Ready::exitAction(Context *)
{
}
