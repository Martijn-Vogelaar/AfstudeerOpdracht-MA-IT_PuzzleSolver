#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "PlacePiece.hpp"
#include "Poses.hpp"
#include <memory>
#include <math.h>

RotatePieceOnPlace::RotatePieceOnPlace()
{
}

RotatePieceOnPlace::~RotatePieceOnPlace() {}

void RotatePieceOnPlace::entryAction(SubContext *context)
{
    if (!context->getMoveRobotClient().RotateGripper(0, M_PI, true, true))
    {
        ROS_ERROR("Move to other place!");
        context->getParentContext()->getPuzzle().setSpotExplored(context->getCurrentPuzzlePieceSpot().getID());
        geometry_msgs::Pose goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
        geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
        context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiecePrepare.position);
        context->getParentContext()->setState(std::make_shared<PlacePiece>());
    }
}

void RotatePieceOnPlace::doActivity(SubContext *context)
{
    context->setState(std::make_shared<CheckCorrectlyRotated>());
}

void RotatePieceOnPlace::exitAction(SubContext *)
{
}
