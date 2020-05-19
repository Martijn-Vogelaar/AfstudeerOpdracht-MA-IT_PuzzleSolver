#include "UnknownPieceInPickupPoint.hpp"
#include "Context.hpp"
#include "PowerOff.hpp"
#include <memory>

UnknownPieceInPickupPoint::UnknownPieceInPickupPoint()
{
}

UnknownPieceInPickupPoint::~UnknownPieceInPickupPoint() {}

void UnknownPieceInPickupPoint::entryAction(Context *)
{
}

void UnknownPieceInPickupPoint::doActivity(Context *context)
{
    ROS_ERROR("UnknownPiece, shutting down!");
    context->setState(std::make_shared<PowerOff>());
}

void UnknownPieceInPickupPoint::exitAction(Context *)
{
}
