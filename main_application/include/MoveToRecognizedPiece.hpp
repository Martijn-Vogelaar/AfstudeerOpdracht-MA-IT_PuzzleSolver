#ifndef MOVE_TO_RECOGNIZED_PIECE_HPP
#define MOVE_TO_RECOGNIZED_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
#include "TF2Handler.hpp"
/**
   * @class MoveToRecognizedPiece
   *
   * @brief MoveToRecognizedPiece is the class which represents the MoveToRecognizedPiece state.
   *
   */
class MoveToRecognizedPiece : public State
{
public:
    /**
     * @brief Construct a new MoveToRecognizedPiece object
     *
     */
    MoveToRecognizedPiece();
    /**
     * @brief Destroy the MoveToRecognizedPiece object
     *
     */
    ~MoveToRecognizedPiece();
    /**
     * @brief entryAction is being called when the MoveToRecognizedPiece state is being entered.
     *
     * @details When the MoveToRecognizedPiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * MoveToRecognizedPiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the MoveToRecognizedPiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // MOVE_TO_RECOGNIZED_PIECE_HPP