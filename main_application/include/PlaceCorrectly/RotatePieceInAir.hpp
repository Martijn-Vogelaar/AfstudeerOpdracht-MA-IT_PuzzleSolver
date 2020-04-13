#ifndef ROTATE_PIECE_IN_AIR_HPP
#define ROTATE_PIECE_IN_AIR_HPP

// Local
#include "PlaceCorrectly/SubContext.hpp"
#include "SubState.hpp"
/**
   * @class RotatePieceInAir
   *
   * @brief RotatePieceInAir is the class which represents the RotatePieceInAir SubState.
   *
   */
class RotatePieceInAir : public SubState
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
     * @brief entryAction is being called when the RotatePieceInAir SubState is being entered.
     *
     * @details When the RotatePieceInAir SubState is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(SubContext *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RotatePieceInAir.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(SubContext *aSubContext) override;
    /**
     * @brief exitAction is being called when the RotatePieceInAir SubState is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(SubContext *aSubContext) override;
};
#endif // ROTATE_PIECE_IN_AIR_HPP