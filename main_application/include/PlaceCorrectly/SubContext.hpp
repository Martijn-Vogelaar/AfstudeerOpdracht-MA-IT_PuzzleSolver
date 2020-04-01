#ifndef SUB_CONTEXT_HPP
#define SUB_CONTEXT_HPP

#include "State.hpp"
#include "MoveRobotClient.hpp"
#include "Context.hpp"
#include <memory>

#define QUEUE_SIZE 1000

class State;
/**
   * @class SubContext
   *
   * @brief SubContext is a class which gives the states an interface to the
   * "outside world".
   *
   */
class SubContext : public Context
{
public:
  /**
     * @brief Construct a new SubContext object
     *
     */
  SubContext(Context* aParentContext);

  /**
   * @brief Get the Context object
   * 
   * @return Context 
   */
  Context* getContext();

private:
  Context* parentContext;
};
#endif // SUB_CONTEXT_HPP