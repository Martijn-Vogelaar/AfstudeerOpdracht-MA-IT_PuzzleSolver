#ifndef MOVE_UNKNOWN_PIECE_HPP
#define MOVE_UNKNOWN_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class MoveUnknownPiece
   *
   * @brief MoveUnknownPiece is the class which represents the MoveUnknownPiece state.
   *
   */
class MoveUnknownPiece : public State
{
public:
    /**
     * @brief Construct a new MoveUnknownPiece object
     *
     */
    MoveUnknownPiece();
    /**
     * @brief Destroy the MoveUnknownPiece object
     *
     */
    ~MoveUnknownPiece();
    /**
     * @brief entryAction is being called when the MoveUnknownPiece state is being entered.
     *
     * @details When the MoveUnknownPiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * MoveUnknownPiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the MoveUnknownPiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // MOVE_UNKNOWN_PIECE_HPP