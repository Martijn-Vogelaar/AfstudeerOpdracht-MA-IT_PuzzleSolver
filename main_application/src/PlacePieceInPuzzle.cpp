#include "PlacePieceInPuzzle.hpp"
#include <iostream>
#include <memory>

PlacePieceInPuzzle::PlacePieceInPuzzle()
{
}

PlacePieceInPuzzle::~PlacePieceInPuzzle() {}

void PlacePieceInPuzzle::entryAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PlacePieceInPuzzle::doActivity(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void PlacePieceInPuzzle::exitAction(Context *)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
