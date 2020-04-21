#include "Puzzle.hpp"

Puzzle::Puzzle() {}

Puzzle::~Puzzle() {}

std::optional<PuzzlePieceSpot> Puzzle::getEmptyPuzzleSpot(Shape shape)
{
    for (PuzzlePieceSpot spot : puzzleSpots)
    {
        if (spot.getShape() == shape && !spot.isFilled())
        {
            return spot;
        }
    }
    return std::nullopt;
}

void Puzzle::setSpotFilled(uint8_t puzzleID)
{
    for (PuzzlePieceSpot spot : puzzleSpots)
    {
        if (spot.getID() == puzzleID)
        {
            spot.setFilled(true);
        }
    }
}

void Puzzle::addPuzzlePieceSpot(PuzzlePieceSpot puzzlePieceSpot)
{
    puzzleSpots.push_back(puzzlePieceSpot);
}

bool Puzzle::puzzleFinished()
{
    return false;
}