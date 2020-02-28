#ifndef CHECK_CORRECTLY_ROTATED_HPP
#define CHECK_CORRECTLY_ROTATED_HPP

// Local
#include "Context.hpp"
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
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * CheckCorrectlyRotated.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the CheckCorrectlyRotated state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // CHECK_CORRECTLY_ROTATED_HPP