#include "PlaceCorrectly/RotatePieceOnPlace.hpp"

#include <iostream>
#include <memory>

RotatePieceOnPlace::RotatePieceOnPlace()
{
}

RotatePieceOnPlace::~RotatePieceOnPlace() {}

void RotatePieceOnPlace::entryAction(Context *)
{
}

void RotatePieceOnPlace::doActivity(Context *context)
{
    context->getMoveRobotClient().RotateGripper(0,3.14);
}

void RotatePieceOnPlace::exitAction(Context *)
{
}
