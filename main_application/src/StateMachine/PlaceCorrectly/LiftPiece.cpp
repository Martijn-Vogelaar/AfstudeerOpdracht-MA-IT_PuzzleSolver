#include "LiftPiece.hpp"
#include "SubContext.hpp"
#include "RotatePieceInAir.hpp"
#include "Poses.hpp"
#include "PuzzlePieceSpot.hpp"

LiftPiece::LiftPiece()
{
}

LiftPiece::~LiftPiece() {}

void LiftPiece::entryAction(SubContext *)
{
}

void LiftPiece::doActivity(SubContext *context)
{
    geometry_msgs::Pose goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiecePrepare.position);
    context->setState(std::make_shared<RotatePieceInAir>());

}

void LiftPiece::exitAction(SubContext *)
{
}
