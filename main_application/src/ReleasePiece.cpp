#include "ReleasePiece.hpp"
#include <iostream>
#include <memory>

ReleasePiece::ReleasePiece()
{
}

ReleasePiece::~ReleasePiece() {}

void ReleasePiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ReleasePiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ReleasePiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
