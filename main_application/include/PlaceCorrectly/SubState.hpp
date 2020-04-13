#ifndef SUB_STATE_HPP
#define SUB_STATE_HPP

#include "SubContext.hpp"

class SubContext;
/**
   * @brief SubState is an abstract/interface class which can be used to create
   * states
   *
   */
class SubState
{
public:
  /**
     * @brief Default constructor
     */
  SubState();

  /**
     * @brief Constructor
     *
     * @param aState SubState to start with
     */
  SubState(const SubState &aState) = delete;

  /**
     * @brief Destructor
     *
     */
  virtual ~SubState();

  /**
     * @brief entryAction is being called when the SubState is being entered.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
  virtual void entryAction(SubContext *aContext) = 0;

  /**
     * @brief doActivity is continiously being called while the system is in the
     * SubState.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
  virtual void doActivity(SubContext *aContext) = 0;

  /**
     * @brief exitAction is being called when the SubState SubState is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
  virtual void exitAction(SubContext *aContext) = 0;
};
#endif // SUB_STATE_HPP