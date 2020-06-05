#include "Ready.hpp"
#include "Context.hpp"
#include "PutPieceInPickupPoint.hpp"
#include "Poses.hpp"
#include <memory>
Ready::Ready()
{
}

Ready::~Ready() {}

void Ready::entryAction(Context *context)
{
    context->getMoveRobotClient().ControlGripper(0, false, 99);
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
}

void Ready::doActivity(Context *context)
{
    context->setState(std::make_shared<PutPieceInPickupPoint>());
}

void Ready::exitAction(Context *)
{
}
