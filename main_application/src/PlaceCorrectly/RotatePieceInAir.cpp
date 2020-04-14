#include "PlaceCorrectly/RotatePieceInAir.hpp"
#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"
#include "PlaceCorrectly/SubContext.hpp"

RotatePieceInAir::RotatePieceInAir()
{
}

RotatePieceInAir::~RotatePieceInAir() {}

void RotatePieceInAir::entryAction(SubContext *)
{
}

void RotatePieceInAir::doActivity(SubContext *context)
{
    context->getMoveRobotClient().RotateGripper(0, 1.57,false);
    context->setState(std::make_shared<PlacePieceInPuzzle>());
}

void RotatePieceInAir::exitAction(SubContext *)
{
}
