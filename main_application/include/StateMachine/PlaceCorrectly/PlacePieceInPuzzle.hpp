#ifndef PLACE_PIECE_IN_PUZZLE_HPP
#define PLACE_PIECE_IN_PUZZLE_HPP

// Local
#include "SubState.hpp"
#include "TF2Handler.hpp"

class SubContext;

/**
   * @class PlacePieceInPuzzle
   *
   * @brief PlacePieceInPuzzle is the class which represents the PlacePieceInPuzzle SubState.
   *
   * @details   The PlacePieceInPuzzle state places the current puzzle piece in the puzzle.
   *            After placing the puzzlepiece in the puzzle a transition to the CheckCorrectRotated
   *            state will be made.
   */
class PlacePieceInPuzzle : public SubState
{
public:
    /**
     * @brief Construct a new PlacePieceInPuzzle object
     *
     */
    PlacePieceInPuzzle();
    /**
     * @brief Destroy the PlacePieceInPuzzle object
     *
     */
    ~PlacePieceInPuzzle();
    /**
     * @brief entryAction is being called when the PlacePieceInPuzzle SubState is being entered.
     *
     * @details When the PlacePieceInPuzzle SubState is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(SubContext *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * PlacePieceInPuzzle.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(SubContext *aSubContext) override;
    /**
     * @brief exitAction is being called when the PlacePieceInPuzzle SubState is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(SubContext *aSubContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // PLACE_PIECE_IN_PUZZLE_HPP