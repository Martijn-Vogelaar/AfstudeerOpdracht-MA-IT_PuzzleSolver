#include "MoveToUnexploredSpot.hpp"
#include <iostream>
#include <memory>
#include "PlacePiece.hpp"

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
