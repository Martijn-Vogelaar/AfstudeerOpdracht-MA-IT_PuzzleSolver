#ifndef RECOGNIZE_PIECE_HPP
#define RECOGNIZE_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class RecognizePiece
   *
   * @brief RecognizePiece is the class which represents the RecognizePiece state.
   *
   */
class RecognizePiece : public State
{
public:
    /**
     * @brief Construct a new RecognizePiece object
     *
     */
    RecognizePiece();
    /**
     * @brief Destroy the RecognizePiece object
     *
     */
    ~RecognizePiece();
    /**
     * @brief entryAction is being called when the RecognizePiece state is being entered.
     *
     * @details When the RecognizePiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RecognizePiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the RecognizePiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // RECOGNIZE_PIECE_HPP