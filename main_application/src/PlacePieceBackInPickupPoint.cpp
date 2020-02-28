#include "PlacePieceBackInPickupPoint.hpp"
#include <iostream>
#include <memory>

PlacePieceBackInPickupPoint::PlacePieceBackInPickupPoint()
{
}

PlacePieceBackInPickupPoint::~PlacePieceBackInPickupPoint() {}

void PlacePieceBackInPickupPoint::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PlacePieceBackInPickupPoint::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PlacePieceBackInPickupPoint::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
