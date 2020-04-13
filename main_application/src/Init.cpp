#include "Init.hpp"
#include <memory>
#include "MoveRobotClient.hpp"
#include "Ready.hpp"
#include "Poses.hpp"
#include "MoveToRecognizedPiece.hpp"
#include "MoveToUnexploredSpot.hpp"
#include "Context.hpp"

Init::Init()
{
}

Init::~Init() {}

void Init::entryAction(Context *)
{
}

void Init::doActivity(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    context->setState(std::make_shared<Ready>());
}

void Init::exitAction(Context *)
{
}
