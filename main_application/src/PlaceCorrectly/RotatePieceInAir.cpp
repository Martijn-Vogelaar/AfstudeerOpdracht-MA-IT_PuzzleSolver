#include "PlaceCorrectly/RotatePieceInAir.hpp"
#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "Shapes.hpp"
#include <math.h>
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
        context->getMoveRobotClient().RotateGripper(0, M_PI/2, false);
    }
    else
    {
        context->getMoveRobotClient().RotateGripper(0, M_PI, false);
    }
    context->setState(std::make_shared<PlacePieceInPuzzle>());
}

void RotatePieceInAir::exitAction(SubContext *)
{
}
