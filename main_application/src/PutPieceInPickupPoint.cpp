#include "PutPieceInPickupPoint.hpp"
#include <iostream>
#include <memory>
#include "MoveRobotClient.hpp"
#include "RecognizePiece.hpp"

PutPieceInPickupPoint::PutPieceInPickupPoint()
{
}

PutPieceInPickupPoint::~PutPieceInPickupPoint() {}

void PutPieceInPickupPoint::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PutPieceInPickupPoint::doActivity(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, -0.48, -0.16, 0.42, 0.0143044, 0.695357, -0.00627331, 0.718494);
    context->getMoveRobotClient().MoveRobotStraight(0, -0.48, -0.16, 0.25, 0.0143044, 0.695357, -0.00627331, 0.718494);
    context->getMoveRobotClient().MoveRobotStraight(0, -0.235, -0.16, 0.25, 0.0143044, 0.695357, -0.00627331, 0.718494);
    context->setState(std::make_shared<RecognizePiece>());
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PutPieceInPickupPoint::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
