#include "Puzzle.hpp"
#include "ros/ros.h"
Puzzle::Puzzle() {}

Puzzle::~Puzzle() {}

std::optional<PuzzlePieceSpot> Puzzle::getEmptyPuzzleSpot(Shape shape)
{
    for (PuzzlePieceSpot& spot : puzzleSpots)
    {
        if (spot.getShape() == shape && !spot.isFilled())
        {
            return spot;
        }
    }
    ROS_ERROR("NOT FOUND!");
    return std::nullopt;
}

void Puzzle::setSpotFilled(uint8_t puzzleID)
{
    for (PuzzlePieceSpot& spot : puzzleSpots)
    {
        if (spot.getID() == puzzleID)
        {
            ROS_ERROR("FILLED");
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