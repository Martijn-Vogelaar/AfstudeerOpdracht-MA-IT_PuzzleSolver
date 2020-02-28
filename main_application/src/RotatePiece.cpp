#include "RotatePiece.hpp"
#include <iostream>
#include <memory>

RotatePiece::RotatePiece()
{
}

RotatePiece::~RotatePiece() {}

void RotatePiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void RotatePiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void RotatePiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
