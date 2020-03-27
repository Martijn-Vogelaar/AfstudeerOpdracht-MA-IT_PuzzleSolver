#ifndef PUT_PIECE_IN_PICKUP_POINT_HPP
#define PUT_PIECE_IN_PICKUP_POINT_HPP

// Local
#include "Context.hpp"
#include "State.hpp"
/**
   * @class PutPieceInPickupPoint
   *
   * @brief PutPieceInPickupPoint is the class which represents the PutPieceInPickupPoint state.
   *
   */
class PutPieceInPickupPoint : public State
{
public:
    /**
     * @brief Construct a new PutPieceInPickupPoint object
     *
     */
    PutPieceInPickupPoint();
    /**
     * @brief Destroy the PutPieceInPickupPoint object
     *
     */
    ~PutPieceInPickupPoint();
    /**
     * @brief entryAction is being called when the PutPieceInPickupPoint state is being entered.
     *
     * @details When the PutPieceInPickupPoint state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * PutPieceInPickupPoint.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the PutPieceInPickupPoint state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // PUT_PIECE_IN_PICKUP_POINT_HPP