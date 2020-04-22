#ifndef ROTATE_PIECE_ON_PLACE_HPP
#define ROTATE_PIECE_ON_PLACE_HPP

// Local
#include "SubState.hpp"
#include "TF2Handler.hpp"

#include <stdint.h>

class SubContext;
/**
   * @class RotatePieceOnPlace
   *
   * @brief RotatePieceOnPlace is the class which represents the RotatePieceOnPlace SubState.
   *
   */
class RotatePieceOnPlace : public SubState
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
     * @brief entryAction is being called when the RotatePieceOnPlace SubState is being entered.
     *
     * @details When the RotatePieceOnPlace SubState is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(SubContext *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RotatePieceOnPlace.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(SubContext *aSubContext) override;
    /**
     * @brief exitAction is being called when the RotatePieceOnPlace SubState is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(SubContext *aSubContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // ROTATE_PIECE_ON_PLACE_HPP