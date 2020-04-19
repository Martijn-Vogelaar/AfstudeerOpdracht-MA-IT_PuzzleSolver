#ifndef READY_HPP
#define READY_HPP

// Local
#include "State.hpp"
#include "ModelSpawner.hpp"
class Context;
/**
   * @class Ready
   *
   * @brief Ready is the class which represents the Ready state.
   *
   */
class Ready : public State
{
public:
    /**
     * @brief Construct a new Ready object
     *
     */
    Ready();
    /**
     * @brief Destroy the Ready object
     *
     */
    ~Ready();
    /**
     * @brief entryAction is being called when the Ready state is being entered.
     *
     * @details When the Ready state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * Ready.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the Ready state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;

private:
    static uint8_t visitCount;
};
#endif // READY_HPP