#ifndef RELEASE_UNKNOWN_PIECE_HPP
#define RELEASE_UNKNOWN_PIECE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class ReleaseUnknownPiece
   *
   * @brief ReleaseUnknownPiece is the class which represents the ReleaseUnknownPiece state.
   *
   */
class ReleaseUnknownPiece : public State
{
public:
    /**
     * @brief Construct a new ReleaseUnknownPiece object
     *
     */
    ReleaseUnknownPiece();
    /**
     * @brief Destroy the ReleaseUnknownPiece object
     *
     */
    ~ReleaseUnknownPiece();
    /**
     * @brief entryAction is being called when the ReleaseUnknownPiece state is being entered.
     *
     * @details When the ReleaseUnknownPiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * ReleaseUnknownPiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the ReleaseUnknownPiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // RELEASE_UNKNOWN_PIECE_HPP