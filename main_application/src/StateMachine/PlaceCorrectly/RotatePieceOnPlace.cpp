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
    context->getMoveRobotClient().RotateGripper(0, M_PI, 1.0, false, false);
}

void RotatePieceOnPlace::doActivity(SubContext *context)
{
    context->rotateTask = std::async(&MoveRobotClient::RotateGripper, &context->getMoveRobotClient(), 0,  -M_PI, 0.05, false, false);
    context->setState(std::make_shared<CheckCorrectlyRotated>());
}

void RotatePieceOnPlace::exitAction(SubContext *)
{
}
