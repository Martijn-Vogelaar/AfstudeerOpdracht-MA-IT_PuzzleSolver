#include "RotatePieceOnPlace.hpp"
#include "CheckCorrectlyRotated.hpp"
#include "SubContext.hpp"
#include <memory>

RotatePieceOnPlace::RotatePieceOnPlace()
{
}

RotatePieceOnPlace::~RotatePieceOnPlace() {}

void RotatePieceOnPlace::entryAction(SubContext *context)
{
    context->getMoveRobotClient().RotateGripper(0, 2*M_PI, true, true);
}

void RotatePieceOnPlace::doActivity(SubContext *context)
{
    context->setState(std::make_shared<CheckCorrectlyRotated>());
}

void RotatePieceOnPlace::exitAction(SubContext *)
{
}
