#ifndef GRAB_UNKNOWN_PIECE_HPP
#define GRAB_UNKNOWN_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class GrabUnknownPiece
   *
   * @brief GrabUnknownPiece is the class which represents the GrabUnknownPiece state.
   *
   */
class GrabUnknownPiece : public State
{
public:
    /**
     * @brief Construct a new GrabUnknownPiece object
     *
     */
    GrabUnknownPiece();
    /**
     * @brief Destroy the GrabUnknownPiece object
     *
     */
    ~GrabUnknownPiece();
    /**
     * @brief entryAction is being called when the GrabUnknownPiece state is being entered.
     *
     * @details When the GrabUnknownPiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * GrabUnknownPiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the GrabUnknownPiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // GRAB_UNKNOWN_PIECE_HPP