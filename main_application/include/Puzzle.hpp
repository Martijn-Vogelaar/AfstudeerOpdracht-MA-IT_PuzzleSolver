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

    /**
     * @brief The functions returns an optional puzzlePieceSpot in which the given shape fits.
     *
     * @details The functions returns an optional puzzlePieceSpot in which the given shape fits.
     *          Depending on the given shape different puzzlepiece spots can be returned. It furthermore
     *          will not return emptypuzzle spots which already have been explored
     * 
     * @param shape A puzzleSpot with the shape of the given shape will be returned.
     * @return  std::optional<PuzzlePieceSpot> An optional PuzzlePieceSpot is returned since it is possible that 
                there are no suitable spots left.
     */
    std::optional<PuzzlePieceSpot> getEmptyPuzzleSpot(Shape shape);

    /**
     * @brief Resets all explored values of the available puzzlepiecespots, i.e.g all explored values are reset to false/
     * 
     */
    void resetExplored();

    /**
     * @brief Set a puzzlepiecespot to explored by supplying the puzzlespot ID.
     * 
     * @param puzzleID Depending on the given ID a puzzlespot is set to explored.
     */
    void setSpotExplored(uint8_t puzzleID);

    /**
     * @brief Set a puzzlepeicespot to filled by suppying the puzzleID.
     * 
     * @param puzzleID Depending on the given ID a puzzlespot is set to filled.
     */
    void setSpotFilled(uint8_t puzzleID);

    /**
     * @brief Add a puzzlePieceSpot to the puzzle.
     * 
     * @param puzzlePieceSpot Puzzlespot which is added to the puzzle.
     */
    void addPuzzlePieceSpot(PuzzlePieceSpot puzzlePieceSpot);

    /**
     * @brief Returns whether the puzzle is finished or not.
     * 
     * @return true Puzzle is finished
     * @return false Puzzle is unfinished
     */
    bool puzzleFinished();

private:
    std::vector <PuzzlePieceSpot> puzzleSpots;
};
#endif // PUZZLE_HPP