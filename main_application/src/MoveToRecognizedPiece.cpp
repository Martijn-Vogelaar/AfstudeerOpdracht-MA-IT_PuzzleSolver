#include "MoveToRecognizedPiece.hpp"
#include <iostream>
#include <memory>
#include "Shapes.hpp"
#include "Poses.hpp"
#include "GrabPiece.hpp"

MoveToRecognizedPiece::MoveToRecognizedPiece()
{
}

MoveToRecognizedPiece::~MoveToRecognizedPiece() {}

void MoveToRecognizedPiece::entryAction(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    if (context->getCurrentPuzzlePiece() != Shape::UNKNOWN)
    {
        geometry_msgs::Pose goal = getPuzzlePiecePreparePickup(context->getCurrentPuzzlePiece());
        geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, BASE, goal);
        context->getMoveRobotClient().MoveRobotNormal(0, pose);
    }
}

void MoveToRecognizedPiece::doActivity(Context *context)
{
    if (context->getCurrentPuzzlePiece() != Shape::UNKNOWN)
    {
        geometry_msgs::Pose goal = getPuzzlePiecePickup(context->getCurrentPuzzlePiece());
        geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, BASE, goal);
        context->getMoveRobotClient().MoveRobotStraight(0, pose);
        context->setState(std::make_shared<GrabPiece>());
    }
}

void MoveToRecognizedPiece::exitAction(Context *)
{
}
