#ifndef GRAB_PIECE_HPP
#define GRAB_PIECE_HPP

// Local
#include "State.hpp"
#include "TF2Handler.hpp"

class Context;

  /**
   * @class GrabPiece
   *
   * @brief GrabPiece is the class which represents the GrabPiece state.
   *
   * @details   The state grabpiece opens the grippers causing the gripper to hold the puzzle-
   *            piece to be grabbed. The piece will furthermore be moved out of the pickuppoint
   *            to the "home" position of the robot.
   *
   */
class GrabPiece : public State
{
public:
    /**
     * @brief Construct a new GrabPiece object
     *
     */
    GrabPiece();
    /**
     * @brief Destroy the GrabPiece object
     *
     */
    ~GrabPiece();
    /**
     * @brief entryAction is being called when the GrabPiece state is being entered.
     *
     * @details When the GrabPiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * GrabPiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the GrabPiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
private:
    TF2Handler tf2Handler;
};
#endif // GRAB_PIECE_HPP