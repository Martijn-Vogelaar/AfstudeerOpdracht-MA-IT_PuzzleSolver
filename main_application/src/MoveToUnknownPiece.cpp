#include "MoveToUnknownPiece.hpp"
#include <iostream>
#include <memory>

MoveToUnknownPiece::MoveToUnknownPiece()
{
}

MoveToUnknownPiece::~MoveToUnknownPiece() {}

void MoveToUnknownPiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MoveToUnknownPiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MoveToUnknownPiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
