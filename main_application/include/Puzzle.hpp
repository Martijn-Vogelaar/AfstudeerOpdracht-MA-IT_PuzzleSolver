#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include "Shapes.hpp"
#include "PuzzlePieceSpot.hpp"
#include <geometry_msgs/Pose.h>
#include <vector>
#include <utility>
#include <optional>

class Puzzle
{
public:
    /**
     * @brief Construct a new Puzzle object
     *
     */
    Puzzle();
    /**
     * @brief Destroy the Puzzle object
     *
     */
    ~Puzzle();

    
    std::optional<PuzzlePieceSpot> getEmptyPuzzleSpot(Shape shape);

    void resetExplored();

    void setSpotExplored(uint8_t puzzleID);

    void setSpotFilled(uint8_t puzzleID);

    void addPuzzlePieceSpot(PuzzlePieceSpot puzzlePieceSpot);

    bool puzzleFinished();

private:
    std::vector <PuzzlePieceSpot> puzzleSpots;
};
#endif // PUZZLE_HPP