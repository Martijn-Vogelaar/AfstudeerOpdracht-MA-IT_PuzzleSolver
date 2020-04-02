#ifndef PLACE_PIECE_IN_PUZZLE_HPP
#define PLACE_PIECE_IN_PUZZLE_HPP

// Local
#include "PlaceCorrectly/SubContext.hpp"
#include "State.hpp"
#include "TF2Handler.hpp"

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
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * PlacePieceInPuzzle.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aSubContext) override;
    /**
     * @brief exitAction is being called when the PlacePieceInPuzzle state is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aSubContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // PLACE_PIECE_IN_PUZZLE_HPP