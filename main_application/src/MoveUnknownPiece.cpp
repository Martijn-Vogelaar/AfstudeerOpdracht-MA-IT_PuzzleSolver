#include "MoveUnknownPiece.hpp"
#include <iostream>
#include <memory>

MoveUnknownPiece::MoveUnknownPiece()
{
}

MoveUnknownPiece::~MoveUnknownPiece() {}

void MoveUnknownPiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MoveUnknownPiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MoveUnknownPiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
