#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"
#include <iostream>
#include <memory>
#include "Poses.hpp"
#include "PlaceCorrectly/RotatePieceOnPlace.hpp"


PlacePieceInPuzzle::PlacePieceInPuzzle()
{
}

PlacePieceInPuzzle::~PlacePieceInPuzzle() {}

void PlacePieceInPuzzle::entryAction(SubContext *context)
{
    // PUZZLE_CIRCLE_1_PREPARE
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    geometry_msgs::Pose goal = getPuzzlePiecePreparePlace(context->getCurrentPuzzlePiece());
    geometry_msgs::Pose circlePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotNormal(0, circlePrepare);
    goal = getPuzzlePiecePlace(context->getCurrentPuzzlePiece());
    geometry_msgs::Pose circlePlacement = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraight(0, circlePlacement);
}

void PlacePieceInPuzzle::doActivity(SubContext *context)
{
    context->setState(std::make_shared<RotatePieceOnPlace>());
}

void PlacePieceInPuzzle::exitAction(SubContext *)
{
}
