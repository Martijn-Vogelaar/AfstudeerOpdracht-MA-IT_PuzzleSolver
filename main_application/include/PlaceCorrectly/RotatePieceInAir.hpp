#ifndef ROTATE_PIECE_IN_AIR_HPP
#define ROTATE_PIECE_IN_AIR_HPP

// Local
#include "PlaceCorrectly/SubContext.hpp"
#include "State.hpp"
/**
   * @class RotatePieceInAir
   *
   * @brief RotatePieceInAir is the class which represents the RotatePieceInAir state.
   *
   */
class RotatePieceInAir : public State
{
public:
    /**
     * @brief Construct a new RotatePieceInAir object
     *
     */
    RotatePieceInAir();
    /**
     * @brief Destroy the RotatePieceInAir object
     *
     */
    ~RotatePieceInAir();
    /**
     * @brief entryAction is being called when the RotatePieceInAir state is being entered.
     *
     * @details When the RotatePieceInAir state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RotatePieceInAir.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aSubContext) override;
    /**
     * @brief exitAction is being called when the RotatePieceInAir state is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aSubContext) override;
};
#endif // ROTATE_PIECE_IN_AIR_HPP