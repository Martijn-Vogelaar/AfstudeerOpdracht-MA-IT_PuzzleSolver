#ifndef LIFT_PIECE_HPP
#define LIFT_PIECE_HPP

// Local
#include "SubState.hpp"
#include "TF2Handler.hpp"

class SubContext;
/**
   * @class LiftPiece
   *
   * @brief LiftPiece is the class which represents the LiftPiece SubState.
   *
   * @details   If a puzzlepiece cannot be rotated on it place, for example with angled shapes,
   *            the puzzle needs to be lifted out of the puzzle before rotating. The state LiftPiece
   *            lifts the puzzlepiece out of the puzzle straight up. After lifting a transition to
   *            RotatePieceInAir is made.
   *
   */
class LiftPiece : public SubState
{
public:
    /**
     * @brief Construct a new LiftPiece object
     *
     */
    LiftPiece();
    /**
     * @brief Destroy the LiftPiece object
     *
     */
    ~LiftPiece();
    /**
     * @brief entryAction is being called when the LiftPiece SubState is being entered.
     *
     * @details When the LiftPiece SubState is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(SubContext *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * LiftPiece.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(SubContext *aSubContext) override;
    /**
     * @brief exitAction is being called when the LiftPiece SubState is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(SubContext *aSubContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // LIFT_PIECE_HPP