#ifndef PLACE_PIECE_BACK_IN_PICKUP_POINT_HPP
#define PLACE_PIECE_BACK_IN_PICKUP_POINT_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class PlacePieceBackInPickupPoint
   *
   * @brief PlacePieceBackInPickupPoint is the class which represents the PlacePieceBackInPickupPoint state.
   *
   */
class PlacePieceBackInPickupPoint : public State
{
public:
    /**
     * @brief Construct a new PlacePieceBackInPickupPoint object
     *
     */
    PlacePieceBackInPickupPoint();
    /**
     * @brief Destroy the PlacePieceBackInPickupPoint object
     *
     */
    ~PlacePieceBackInPickupPoint();
    /**
     * @brief entryAction is being called when the PlacePieceBackInPickupPoint state is being entered.
     *
     * @details When the PlacePieceBackInPickupPoint state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * PlacePieceBackInPickupPoint.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the PlacePieceBackInPickupPoint state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // PLACE_PIECE_BACK_IN_PICKUP_POINT_HPP