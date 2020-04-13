#include "GrabPiece.hpp"
#include <iostream>
#include <memory>
#include "Poses.hpp"
#include "MoveToUnexploredSpot.hpp"
#include "Shapes.hpp"
GrabPiece::GrabPiece()
{
}

GrabPiece::~GrabPiece() {}

void GrabPiece::entryAction(Context *)
{
}

void GrabPiece::doActivity(Context *context)
{
    context->getMoveRobotClient().ControlGripper(0, true, puzzlePieceToInt(context->getCurrentPuzzlePiece()));
    ros::Duration(0.2).sleep();
    context->setState(std::make_shared<MoveToUnexploredSpot>());
}

void GrabPiece::exitAction(Context *context)
{
    geometry_msgs::Pose movePieceUp = tf2Handler.calculatePosition(PICKUP_POINT, BASE, PICKUP_POINT_MOVE_PIECE);
    context->getMoveRobotClient().MoveRobotStraight(0, movePieceUp);
}
