#ifndef MOVE_TO_UNKNOWN_PIECE_HPP
#define MOVE_TO_UNKNOWN_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class MoveToUnknownPiece
   *
   * @brief MoveToUnknownPiece is the class which represents the MoveToUnknownPiece state.
   *
   */
class MoveToUnknownPiece : public State
{
public:
    /**
     * @brief Construct a new MoveToUnknownPiece object
     *
     */
    MoveToUnknownPiece();
    /**
     * @brief Destroy the MoveToUnknownPiece object
     *
     */
    ~MoveToUnknownPiece();
    /**
     * @brief entryAction is being called when the MoveToUnknownPiece state is being entered.
     *
     * @details When the MoveToUnknownPiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * MoveToUnknownPiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the MoveToUnknownPiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // MOVE_TO_UNKNOWN_PIECE_HPP