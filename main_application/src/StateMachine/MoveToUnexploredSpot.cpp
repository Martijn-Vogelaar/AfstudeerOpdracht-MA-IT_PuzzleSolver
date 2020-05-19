#include "MoveToUnexploredSpot.hpp"
#include "Context.hpp"
#include "PlacePiece.hpp"
#include "Poses.hpp"
#include "Shapes.hpp"
#include "PowerOff.hpp"
#include "Ready.hpp"
#include "PuzzlePieceSpot.hpp"
#include <memory>

MoveToUnexploredSpot::MoveToUnexploredSpot()
{
}

MoveToUnexploredSpot::~MoveToUnexploredSpot() {}

void MoveToUnexploredSpot::entryAction(Context *)
{
}

void MoveToUnexploredSpot::doActivity(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_DROP_POSITION);
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, ROBOT_DROP_POSITION2.position);
    context->getMoveRobotClient().ControlGripper(0,false,0);
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    // context->findEmptyUnexploredPuzzleSpot();
    
    // if (context->getCurrentPuzzlePieceSpot().getShape() != Shape::UNKNOWN)
    // {
    //     geometry_msgs::Pose goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    //     geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    //     context->getMoveRobotClient().MoveRobotNormal(0, placePiecePrepare);
    //     context->setState(std::make_shared<PlacePiece>());
    // }
    // else
    // {
    //     context->setState(std::make_shared<PowerOff>());
    // }
    context->setState(std::make_shared<Ready>());
}

void MoveToUnexploredSpot::exitAction(Context *)
{
}
