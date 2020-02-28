
#include <iostream>
#include "Context.hpp"
#include "Init.hpp"

Context::Context()
{
  setState(std::make_shared<Init>());
}

void Context::setState(const std::shared_ptr<State> &state)
{
  if (mCurrentState)
  {
    mCurrentState->exitAction(this);
  }
  mCurrentState = state;

  mCurrentState->entryAction(this);
}

void Context::run()
{
  mCurrentState->doActivity(this);
}