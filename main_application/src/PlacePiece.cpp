#include "PlacePiece.hpp"
#include "Context.hpp"
#include "Poses.hpp"
#include <memory>

PlacePiece::PlacePiece()
{
}

PlacePiece::~PlacePiece() {}

void PlacePiece::entryAction(Context *context)
{
    geometry_msgs::Pose goal = getPuzzlePiecePreparePlace(context->getCurrentPuzzlePiece());
    geometry_msgs::Pose placePiecePrepare = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    context->getMoveRobotClient().MoveRobotNormal(0, placePiecePrepare);
    subContext = std::make_shared<SubContext>(context);
}

void PlacePiece::doActivity(Context *)
{
    subContext->run();
}

void PlacePiece::exitAction(Context *)
{
}
