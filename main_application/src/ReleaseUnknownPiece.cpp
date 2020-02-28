#include "ReleaseUnknownPiece.hpp"
#include <iostream>
#include <memory>

ReleaseUnknownPiece::ReleaseUnknownPiece()
{
}

ReleaseUnknownPiece::~ReleaseUnknownPiece() {}

void ReleaseUnknownPiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ReleaseUnknownPiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ReleaseUnknownPiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
