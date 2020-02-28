#include "RotatePieceOnPlace.hpp"
#include <iostream>
#include <memory>

RotatePieceOnPlace::RotatePieceOnPlace()
{
}

RotatePieceOnPlace::~RotatePieceOnPlace() {}

void RotatePieceOnPlace::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void RotatePieceOnPlace::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void RotatePieceOnPlace::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
