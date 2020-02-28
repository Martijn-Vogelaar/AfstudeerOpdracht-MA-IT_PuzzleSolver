#ifndef ROTATE_PIECE_ON_PLACE_HPP
#define ROTATE_PIECE_ON_PLACE_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class RotatePieceOnPlace
   *
   * @brief RotatePieceOnPlace is the class which represents the RotatePieceOnPlace state.
   *
   */
class RotatePieceOnPlace : public State
{
public:
    /**
     * @brief Construct a new RotatePieceOnPlace object
     *
     */
    RotatePieceOnPlace();
    /**
     * @brief Destroy the RotatePieceOnPlace object
     *
     */
    ~RotatePieceOnPlace();
    /**
     * @brief entryAction is being called when the RotatePieceOnPlace state is being entered.
     *
     * @details When the RotatePieceOnPlace state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RotatePieceOnPlace.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the RotatePieceOnPlace state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // ROTATE_PIECE_ON_PLACE_HPP