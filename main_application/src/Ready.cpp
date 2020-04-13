#include "Ready.hpp"
#include "Context.hpp"
#include "PutPieceInPickupPoint.hpp"
#include <memory>

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
