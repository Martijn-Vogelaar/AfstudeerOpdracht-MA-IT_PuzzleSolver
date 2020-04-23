#include "MoveToUnexploredSpot.hpp"
#include "Context.hpp"
#include "PlacePiece.hpp"
#include "Poses.hpp"
#include "Shapes.hpp"
#include "PowerOff.hpp"
#include "PuzzlePieceSpot.hpp"
#include <memory>

MoveToUnexploredSpot::MoveToUnexploredSpot()
{
}

MoveToUnexploredSpot::~MoveToUnexploredSpot() {}

void MoveToUnexploredSpot::entryAction(Context *)
{
}

void MoveToUnexploredSpot::doActivity(Context *context)
{
    context->findEmptyUnexploredPuzzleSpot();
    if (context->getCurrentPuzzlePieceSpot().getShape() != Shape::UNKNOWN)
    {
        geometry_msgs::Pose goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
        geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
        context->getMoveRobotClient().MoveRobotNormal(0, placePiecePrepare);
        context->setState(std::make_shared<PlacePiece>());
    }
    else
    {
        context->setState(std::make_shared<PowerOff>());
    }
}

void MoveToUnexploredSpot::exitAction(Context *)
{
}
