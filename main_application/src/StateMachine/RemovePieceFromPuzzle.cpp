#include "RemovePieceFromPuzzle.hpp"
#include "Context.hpp"
#include "MoveToUnexploredSpot.hpp"
#include "Poses.hpp"
#include <memory>

RemovePieceFromPuzzle::RemovePieceFromPuzzle()
{
}

RemovePieceFromPuzzle::~RemovePieceFromPuzzle() {}

void RemovePieceFromPuzzle::entryAction(Context *context)
{
    ROS_ERROR("RemovePieceFromPuzzle");
    context->getPuzzle().setSpotExplored(context->getCurrentPuzzlePieceSpot().getID());
    geometry_msgs::Pose goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiecePrepare.position);
}

void RemovePieceFromPuzzle::doActivity(Context *context)
{
    context->setState(std::make_shared<MoveToUnexploredSpot>());
}

void RemovePieceFromPuzzle::exitAction(Context *)
{
}
