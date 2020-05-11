#include "Puzzle.hpp"
#include "ros/ros.h"
Puzzle::Puzzle() {}

Puzzle::~Puzzle() {}

PuzzlePieceSpot *Puzzle::getEmptyPuzzleSpot(Shape shape)
{
    for (PuzzlePieceSpot &spot : puzzleSpots)
    {
        if (spot.getShape() == shape && !spot.isFilled() && !spot.isExplored())
        {
            return &spot;
        }
    }
    return NULL;
}

void Puzzle::resetExplored()
{
    for (PuzzlePieceSpot &spot : puzzleSpots)
    {
        spot.setExplored(false);
    }
}

void Puzzle::setSpotExplored(uint8_t puzzleID)
{
    for (PuzzlePieceSpot &spot : puzzleSpots)
    {
        if (spot.getID() == puzzleID)
        {
            spot.setExplored(true);
        }
    }
}

void Puzzle::setSpotFilled(uint8_t puzzleID)
{
    for (PuzzlePieceSpot &spot : puzzleSpots)
    {
        if (spot.getID() == puzzleID)
        {
            spot.setFilled(true);
            resetExplored();
        }
    }
}

void Puzzle::addPuzzlePieceSpot(PuzzlePieceSpot puzzlePieceSpot)
{
    puzzleSpots.push_back(puzzlePieceSpot);
}

bool Puzzle::puzzleFinished()
{
    for (PuzzlePieceSpot &spot : puzzleSpots)
    {
        if (!spot.isFilled())
        {
            return false;
        }
    }
    return true;
}