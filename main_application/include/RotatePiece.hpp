#ifndef ROTATE_PIECE_HPP
#define ROTATE_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class RotatePiece
   *
   * @brief RotatePiece is the class which represents the RotatePiece state.
   *
   */
class RotatePiece : public State
{
public:
    /**
     * @brief Construct a new RotatePiece object
     *
     */
    RotatePiece();
    /**
     * @brief Destroy the RotatePiece object
     *
     */
    ~RotatePiece();
    /**
     * @brief entryAction is being called when the RotatePiece state is being entered.
     *
     * @details When the RotatePiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RotatePiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the RotatePiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // ROTATE_PIECE_HPP