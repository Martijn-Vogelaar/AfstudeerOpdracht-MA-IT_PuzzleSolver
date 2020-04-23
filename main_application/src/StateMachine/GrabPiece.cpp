#include "GrabPiece.hpp"
#include "Poses.hpp"
#include "MoveToUnexploredSpot.hpp"
#include "Shapes.hpp"
#include "Context.hpp"
#include <memory>

GrabPiece::GrabPiece()
{
}

GrabPiece::~GrabPiece() {}

void GrabPiece::entryAction(Context *)
{
}

void GrabPiece::doActivity(Context *context)
{
    context->getMoveRobotClient().ControlGripper(0, true, puzzlePieceToInt(context->getCurrentShape()));
    context->setState(std::make_shared<MoveToUnexploredSpot>());
}

void GrabPiece::exitAction(Context *context)
{
    geometry_msgs::Pose goal = getPuzzlePiecePreparePickup(context->getCurrentShape());
    geometry_msgs::Pose pose = tf2Handler.calculatePosition(PICKUP_POINT, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, pose.position);
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
}
