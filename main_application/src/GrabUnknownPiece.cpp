#include "GrabUnknownPiece.hpp"
#include <iostream>
#include <memory>

GrabUnknownPiece::GrabUnknownPiece()
{
}

GrabUnknownPiece::~GrabUnknownPiece() {}

void GrabUnknownPiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GrabUnknownPiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GrabUnknownPiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
