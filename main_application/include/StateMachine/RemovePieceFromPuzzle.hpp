#ifndef REMOVE_PIECE_FROM_PUZZLE_HPP
#define REMOVE_PIECE_FROM_PUZZLE_HPP

// Local
#include "State.hpp"
#include "TF2Handler.hpp"

class Context;
/**
   * @class RemovePieceFromPuzzle
   *
   * @brief RemovePieceFromPuzzle is the class which represents the RemovePieceFromPuzzle state.
   *
   * @details   If the PlaceCorrectly state has tried all possible rotation in the visisted spot.
   *            The RemovePieceFromPuzzle will remove the piece frmo the puzzle by lifting the
   *            piece straight up in a lineair manner. After this movement is finished a transition
   *            to the MoveToUnexploredSpot state is made.
   *            
   */
class RemovePieceFromPuzzle : public State
{
public:
    /**
     * @brief Construct a new RemovePieceFromPuzzle object
     *
     */
    RemovePieceFromPuzzle();
    /**
     * @brief Destroy the RemovePieceFromPuzzle object
     *
     */
    ~RemovePieceFromPuzzle();
    /**
     * @brief entryAction is being called when the RemovePieceFromPuzzle state is being entered.
     *
     * @details When the RemovePieceFromPuzzle state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RemovePieceFromPuzzle.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the RemovePieceFromPuzzle state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // REMOVE_PIECE_FROM_PUZZLE_HPP