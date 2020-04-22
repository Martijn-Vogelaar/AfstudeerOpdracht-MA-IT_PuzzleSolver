#include "MoveToRecognizedPiece.hpp"
#include "Shapes.hpp"
#include "Poses.hpp"
#include "GrabPiece.hpp"
#include "Context.hpp"
#include <memory>

MoveToRecognizedPiece::MoveToRecognizedPiece()
{
}

MoveToRecognizedPiece::~MoveToRecognizedPiece() {}

void MoveToRecognizedPiece::entryAction(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    if (context->getCurrentShape() != Shape::UNKNOWN)
    {
        geometry_msgs::Pose goal = getPuzzlePiecePreparePickup(context->getCurrentShape());
        geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, BASE, goal);
        context->getMoveRobotClient().MoveRobotNormal(0, pose);
    }
}

void MoveToRecognizedPiece::doActivity(Context *context)
{
    if (context->getCurrentShape() != Shape::UNKNOWN)
    {
        geometry_msgs::Pose goal = getPuzzlePiecePickup(context->getCurrentShape());
        geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, BASE, goal);
        context->getMoveRobotClient().MoveRobotStraight(0, pose);
        context->setState(std::make_shared<GrabPiece>());
    }
}

void MoveToRecognizedPiece::exitAction(Context *)
{
}
