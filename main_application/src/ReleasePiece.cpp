#include "ReleasePiece.hpp"
#include "Poses.hpp"
#include "Context.hpp"
#include "Ready.hpp"
#include <memory>

ReleasePiece::ReleasePiece()
{
}

ReleasePiece::~ReleasePiece() {}

void ReleasePiece::entryAction(Context *context)
{
    ros::Duration(1).sleep();
    context->getMoveRobotClient().ControlGripper(0, false, puzzlePieceToInt(context->getCurrentPuzzlePieceSpot().getShape()));
    geometry_msgs::Pose goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    geometry_msgs::Pose pose = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, pose.position);
    context->setCurrentPuzzlePiece(0);
}

void ReleasePiece::doActivity(Context *context)
{
    context->setState(std::make_shared<Ready>());
}

void ReleasePiece::exitAction(Context *)
{
}
