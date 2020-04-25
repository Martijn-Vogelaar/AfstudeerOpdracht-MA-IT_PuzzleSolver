#ifndef ROTATE_PIECE_IN_AIR_HPP
#define ROTATE_PIECE_IN_AIR_HPP

// Local
#include "TF2Handler.hpp"
#include "SubState.hpp"

class SubContext;
/**
   * @class RotatePieceInAir
   *
   * @brief RotatePieceInAir is the class which represents the RotatePieceInAir SubState.
   *
   * @details   RotatePieceInAir rotates a puzzlepiece which is currently hovering above the puzzle.
   *            Depending on the shape of the puzzlepiece different rotations can be made. After the
   *            rotation is finished a transition to the CheckCorrectlyRotated state will be made.
   *
   */
class RotatePieceInAir : public SubState
{
public:
    /**
     * @brief Construct a new RotatePieceInAir object
     *
     */
    RotatePieceInAir();
    /**
     * @brief Destroy the RotatePieceInAir object
     *
     */
    ~RotatePieceInAir();
    /**
     * @brief entryAction is being called when the RotatePieceInAir SubState is being entered.
     *
     * @details When the RotatePieceInAir SubState is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(SubContext *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RotatePieceInAir.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(SubContext *aSubContext) override;
    /**
     * @brief exitAction is being called when the RotatePieceInAir SubState is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(SubContext *aSubContext) override;

private:
    static int8_t unableToRotateFurther;

};
#endif // ROTATE_PIECE_IN_AIR_HPP