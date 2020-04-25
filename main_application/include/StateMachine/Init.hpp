#ifndef INIT_HPP
#define INIT_HPP

// Local
#include "State.hpp"

class Context;
/**
   * @class Init
   *
   * @brief Init is the class which represents the Init state.
   *
   * @details   In the init state the system is being initialized.
   *            After initialization a transition to the ready state is made.
   */
class Init : public State
{
public:
    /**
     * @brief Construct a new Init object
     *
     */
    Init();
    /**
     * @brief Destroy the Init object
     *
     */
    ~Init();
    /**
     * @brief entryAction is being called when the Init state is being entered.
     *
     * @details When the Init state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * Init.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the Init state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // INIT_HPP