#ifndef RELEASE_PIECE_HPP
#define RELEASE_PIECE_HPP

// Local
#include "State.hpp"
class Context;
#include "TF2Handler.hpp"

/**
   * @class ReleasePiece
   *
   * @brief ReleasePiece is the class which represents the ReleasePiece state.
   *
   * @details   In the ReleasePiece state the currently held puzzlepiece is released by "closing"
   *            the gripper. After releasing it the robotarm will be moved in a lineair manner
   *            to a position straight above the just placed puzzlepiece.
   *            After the movement is finished a transition to the Ready state is made.
   */
class ReleasePiece : public State
{
public:
    /**
     * @brief Construct a new ReleasePiece object
     *
     */
    ReleasePiece();
    /**
     * @brief Destroy the ReleasePiece object
     *
     */
    ~ReleasePiece();
    /**
     * @brief entryAction is being called when the ReleasePiece state is being entered.
     *
     * @details When the ReleasePiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * ReleasePiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the ReleasePiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // RELEASE_PIECE_HPP