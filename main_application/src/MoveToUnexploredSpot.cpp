#include "MoveToUnexploredSpot.hpp"
#include "Context.hpp"
#include "PlacePiece.hpp"
#include <memory>

MoveToUnexploredSpot::MoveToUnexploredSpot()
{
}

MoveToUnexploredSpot::~MoveToUnexploredSpot() {}

void MoveToUnexploredSpot::entryAction(Context *)
{
}

void MoveToUnexploredSpot::doActivity(Context* context)
{
    context->setState(std::make_shared<PlacePiece>());
}

void MoveToUnexploredSpot::exitAction(Context *)
{
}
