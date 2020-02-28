#ifndef LIFT_PIECE_HPP
#define LIFT_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class LiftPiece
   *
   * @brief LiftPiece is the class which represents the LiftPiece state.
   *
   */
class LiftPiece : public State
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
     * @brief entryAction is being called when the LiftPiece state is being entered.
     *
     * @details When the LiftPiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * LiftPiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the LiftPiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // LIFT_PIECE_HPP