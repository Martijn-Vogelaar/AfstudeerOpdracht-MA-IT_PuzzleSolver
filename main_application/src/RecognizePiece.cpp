#include "RecognizePiece.hpp"
#include <iostream>
#include <memory>

RecognizePiece::RecognizePiece()
{
}

RecognizePiece::~RecognizePiece() {}

void RecognizePiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void RecognizePiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void RecognizePiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
