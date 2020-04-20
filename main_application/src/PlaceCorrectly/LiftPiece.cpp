#include "PlaceCorrectly/LiftPiece.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "PlaceCorrectly/RotatePieceInAir.hpp"
#include "Poses.hpp"

LiftPiece::LiftPiece()
{
}

LiftPiece::~LiftPiece() {}

void LiftPiece::entryAction(SubContext *)
{
}

void LiftPiece::doActivity(SubContext *context)
{
    geometry_msgs::Pose goal = getPuzzlePiecePreparePlace(context->getParentContext()->getCurrentPuzzlePiece());
    geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiecePrepare.position);
    context->setState(std::make_shared<RotatePieceInAir>());

}

void LiftPiece::exitAction(SubContext *)
{
}
