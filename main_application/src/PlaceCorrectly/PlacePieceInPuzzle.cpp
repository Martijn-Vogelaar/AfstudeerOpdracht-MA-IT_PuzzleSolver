#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "Poses.hpp"
#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "Shapes.hpp"
#include "Context.hpp"

PlacePieceInPuzzle::PlacePieceInPuzzle()
{
}

PlacePieceInPuzzle::~PlacePieceInPuzzle() {}

void PlacePieceInPuzzle::entryAction(SubContext *context)
{
    geometry_msgs::Pose goal = getPuzzlePiecePlace(context->getParentContext()->getCurrentPuzzlePiece());
    geometry_msgs::Pose placePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiece.position);
}

void PlacePieceInPuzzle::doActivity(SubContext *context)
{
    if (context->getParentContext()->getCurrentPuzzlePiece() == Shape::CIRCLE)
    {
        context->setState(std::make_shared<RotatePieceOnPlace>());
    }
    else
    {
        context->setState(std::make_shared<CheckCorrectlyRotated>());
    }
}

void PlacePieceInPuzzle::exitAction(SubContext *)
{
}
