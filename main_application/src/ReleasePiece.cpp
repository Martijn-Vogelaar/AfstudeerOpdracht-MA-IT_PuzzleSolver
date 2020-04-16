#include "ReleasePiece.hpp"
#include "Poses.hpp"
#include "Context.hpp"
#include "PutPieceInPickupPoint.hpp"
#include <memory>

ReleasePiece::ReleasePiece()
{
}

ReleasePiece::~ReleasePiece() {}

void ReleasePiece::entryAction(Context *context)
{
    ros::Duration(0.2).sleep();
    context->getMoveRobotClient().ControlGripper(0, false, puzzlePieceToInt(context->getCurrentPuzzlePiece()));
    context->setCurrentPuzzlePiece(Shape::UNKNOWN);
}

void ReleasePiece::doActivity(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    context->setState(std::make_shared<PutPieceInPickupPoint>());
}

void ReleasePiece::exitAction(Context *)
{
}
