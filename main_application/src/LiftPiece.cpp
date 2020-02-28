#include "LiftPiece.hpp"
#include <iostream>
#include <memory>

LiftPiece::LiftPiece()
{
}

LiftPiece::~LiftPiece() {}

void LiftPiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void LiftPiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void LiftPiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
