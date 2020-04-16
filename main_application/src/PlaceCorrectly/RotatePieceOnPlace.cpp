#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include <memory>
#include <math.h>
RotatePieceOnPlace::RotatePieceOnPlace()
{
}

RotatePieceOnPlace::~RotatePieceOnPlace() {}

void RotatePieceOnPlace::entryAction(SubContext *)
{
}

void RotatePieceOnPlace::doActivity(SubContext *context)
{
    context->getMoveRobotClient().RotateGripper(0, M_PI,true);
    context->setState(std::make_shared<CheckCorrectlyRotated>());
}

void RotatePieceOnPlace::exitAction(SubContext *)
{
}
