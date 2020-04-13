#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"
#include <iostream>
#include <memory>
#include "Poses.hpp"
#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/LiftPiece.hpp"
#include "Shapes.hpp"

PlacePieceInPuzzle::PlacePieceInPuzzle()
{
}

PlacePieceInPuzzle::~PlacePieceInPuzzle() {}

void PlacePieceInPuzzle::entryAction(SubContext *context)
{
    // PUZZLE_CIRCLE_1_PREPARE
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    geometry_msgs::Pose goal = getPuzzlePiecePreparePlace(context->getParentContext()->getCurrentPuzzlePiece());
    geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotNormal(0, placePiecePrepare);
    goal = getPuzzlePiecePlace(context->getParentContext()->getCurrentPuzzlePiece());
    geometry_msgs::Pose palcePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraight(0, palcePiece);
}

void PlacePieceInPuzzle::doActivity(SubContext *context)
{
    if (context->getParentContext()->getCurrentPuzzlePiece() == Shape::CIRCLE)
    {
        context->setState(std::make_shared<RotatePieceOnPlace>());
    }
    else
    {
        context->setState(std::make_shared<LiftPiece>());
    }
}

void PlacePieceInPuzzle::exitAction(SubContext *)
{
}
