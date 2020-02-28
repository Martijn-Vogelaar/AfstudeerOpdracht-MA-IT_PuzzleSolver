#ifndef PLACE_PIECE_IN_PUZZLE_HPP
#define PLACE_PIECE_IN_PUZZLE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class PlacePieceInPuzzle
   *
   * @brief PlacePieceInPuzzle is the class which represents the PlacePieceInPuzzle state.
   *
   */
class PlacePieceInPuzzle : public State
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
     * @brief entryAction is being called when the PlacePieceInPuzzle state is being entered.
     *
     * @details When the PlacePieceInPuzzle state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * PlacePieceInPuzzle.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the PlacePieceInPuzzle state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // PLACE_PIECE_IN_PUZZLE_HPP