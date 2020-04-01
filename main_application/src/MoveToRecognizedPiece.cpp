#include "MoveToRecognizedPiece.hpp"
#include <iostream>
#include <memory>
#include "Shapes.hpp"
#include "Poses.hpp"
#include "GrabPiece.hpp"

MoveToRecognizedPiece::MoveToRecognizedPiece(uint8_t aPuzzlePieceId) : puzzlePieceId(aPuzzlePieceId)
{
}

MoveToRecognizedPiece::~MoveToRecognizedPiece() {}

void MoveToRecognizedPiece::entryAction(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    geometry_msgs::Pose goal = PICKUP_POINT_CIRCLE;
    bool knownShape = true;
    switch (puzzlePieceId)
    {
    case Shapes::CIRCLE:
        goal = PICKUP_POINT_CIRCLE_PREPARE;
        break;
    case Shapes::SQUARE:
        // statements
        break;
    case Shapes::RECTANGLE_1:
        // statements
        break;
    case Shapes::RECTANGLE_2:
        // statements
        break;
    default:
        knownShape = false;
    }
    if (knownShape)
    {
        geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, BASE, goal);
        context->getMoveRobotClient().MoveRobotNormal(0, pose);
    }
}

void MoveToRecognizedPiece::doActivity(Context *context)
{
    geometry_msgs::Pose goal = PICKUP_POINT_CIRCLE;
    bool knownShape = true;
    switch (puzzlePieceId)
    {
    case Shapes::CIRCLE:
        goal = PICKUP_POINT_CIRCLE;
        break;
    case Shapes::SQUARE:
        // statements
        break;
    case Shapes::RECTANGLE_1:
        // statements
        break;
    case Shapes::RECTANGLE_2:
        // statements
        break;
    default:
        knownShape = false;
    }
    if (knownShape)
    {
        geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, BASE, goal);
        context->getMoveRobotClient().MoveRobotStraight(0, pose);
        context->setState(std::make_shared<GrabPiece>());
    }
}

void MoveToRecognizedPiece::exitAction(Context *context)
{
}
