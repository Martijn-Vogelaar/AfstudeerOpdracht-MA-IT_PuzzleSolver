#include "ReleasePiece.hpp"
#include "Poses.hpp"
#include "Context.hpp"
#include <memory>

ReleasePiece::ReleasePiece()
{
}

ReleasePiece::~ReleasePiece() {}

void ReleasePiece::entryAction(Context *context)
{
    ros::Duration(0.2).sleep();
    context->getMoveRobotClient().ControlGripper(0, false, puzzlePieceToInt(context->getCurrentPuzzlePiece()));
    context->setCurrentPuzzlePiece(Shape::UNKNOWN);
}

void ReleasePiece::doActivity(Context *context)
{
    geometry_msgs::Pose goal = getPuzzlePiecePreparePlace(context->getCurrentPuzzlePiece());
    geometry_msgs::Pose circlePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotNormal(0, circlePrepare);
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
}

void ReleasePiece::exitAction(Context *)
{
}
