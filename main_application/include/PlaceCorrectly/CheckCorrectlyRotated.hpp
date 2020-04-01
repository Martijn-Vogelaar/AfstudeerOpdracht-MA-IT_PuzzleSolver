#ifndef CHECK_CORRECTLY_ROTATED_HPP
#define CHECK_CORRECTLY_ROTATED_HPP

// Local
#include "PlaceCorrectly/SubContext.hpp"
#include "State.hpp"
/**
   * @class CheckCorrectlyRotated
   *
   * @brief CheckCorrectlyRotated is the class which represents the CheckCorrectlyRotated state.
   *
   */
class CheckCorrectlyRotated : public State
{
public:
    /**
     * @brief Construct a new CheckCorrectlyRotated object
     *
     */
    CheckCorrectlyRotated();
    /**
     * @brief Destroy the CheckCorrectlyRotated object
     *
     */
    ~CheckCorrectlyRotated();
    /**
     * @brief entryAction is being called when the CheckCorrectlyRotated state is being entered.
     *
     * @details When the CheckCorrectlyRotated state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aSubContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * CheckCorrectlyRotated.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aSubContext) override;
    /**
     * @brief exitAction is being called when the CheckCorrectlyRotated state is being exited.
     *
     * @param aSubContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aSubContext) override;
};
#endif // CHECK_CORRECTLY_ROTATED_HPP