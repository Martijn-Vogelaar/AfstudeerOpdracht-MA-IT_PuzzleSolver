#ifndef UNKNOWN_PIECE_IN_PICKUP_POINT_HPP
#define UNKNOWN_PIECE_IN_PICKUP_POINT_HPP

// Local
#include "State.hpp"
class Context;
/**
   * @class UnknownPieceInPickupPoint
   *
   * @brief UnknownPieceInPickupPoint is the class which represents the UnknownPieceInPickupPoint state.
   *
   */
class UnknownPieceInPickupPoint : public State
{
public:
    /**
     * @brief Construct a new UnknownPieceInPickupPoint object
     *
     */
    UnknownPieceInPickupPoint();
    /**
     * @brief Destroy the UnknownPieceInPickupPoint object
     *
     */
    ~UnknownPieceInPickupPoint();
    /**
     * @brief entryAction is being called when the UnknownPieceInPickupPoint state is being entered.
     *
     * @details When the UnknownPieceInPickupPoint state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * UnknownPieceInPickupPoint.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the UnknownPieceInPickupPoint state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // UNKNOWN_PIECE_IN_PICKUP_POINT_HPP