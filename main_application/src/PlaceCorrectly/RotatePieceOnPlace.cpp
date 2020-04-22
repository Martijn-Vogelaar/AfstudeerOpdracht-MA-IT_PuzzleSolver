#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include <memory>

RotatePieceOnPlace::RotatePieceOnPlace()
{
}

RotatePieceOnPlace::~RotatePieceOnPlace() {}

void RotatePieceOnPlace::entryAction(SubContext *context)
{
    context->getMoveRobotClient().RotateGripper(0, M_PI, true, true);
}

void RotatePieceOnPlace::doActivity(SubContext *context)
{
    context->setState(std::make_shared<CheckCorrectlyRotated>());
}

void RotatePieceOnPlace::exitAction(SubContext *)
{
}
