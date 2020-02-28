#include "GrabPiece.hpp"
#include <iostream>
#include <memory>

GrabPiece::GrabPiece()
{
}

GrabPiece::~GrabPiece() {}

void GrabPiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GrabPiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GrabPiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
