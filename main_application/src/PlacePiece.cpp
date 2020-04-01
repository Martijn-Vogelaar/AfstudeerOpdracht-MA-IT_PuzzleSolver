#include "PlacePiece.hpp"
#include <iostream>
#include <memory>

PlacePiece::PlacePiece()
{
}

PlacePiece::~PlacePiece() {}

void PlacePiece::entryAction(Context *context)
{
    subContext = std::make_shared<SubContext>(context);
}

void PlacePiece::doActivity(Context *)
{
    subContext->run();
}

void PlacePiece::exitAction(Context *)
{
}
