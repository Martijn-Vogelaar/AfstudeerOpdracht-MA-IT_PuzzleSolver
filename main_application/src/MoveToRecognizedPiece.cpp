#include "MoveToRecognizedPiece.hpp"
#include <iostream>
#include <memory>

MoveToRecognizedPiece::MoveToRecognizedPiece()
{
}

MoveToRecognizedPiece::~MoveToRecognizedPiece() {}

void MoveToRecognizedPiece::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MoveToRecognizedPiece::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MoveToRecognizedPiece::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
