#include "PlaceCorrectly/RotatePieceInAir.hpp"
#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "Shapes.hpp"

RotatePieceInAir::RotatePieceInAir()
{
}

RotatePieceInAir::~RotatePieceInAir() {}

void RotatePieceInAir::entryAction(SubContext *)
{
}

void RotatePieceInAir::doActivity(SubContext *context)
{
    if (context->getParentContext()->getCurrentPuzzlePiece() == Shape::SQUARE)
    {
        context->getMoveRobotClient().RotateGripper(0, 1.57, false);
    }
    else
    {
        context->getMoveRobotClient().RotateGripper(0, 3.1415, false);
    }
    context->setState(std::make_shared<PlacePieceInPuzzle>());
}

void RotatePieceInAir::exitAction(SubContext *)
{
}
