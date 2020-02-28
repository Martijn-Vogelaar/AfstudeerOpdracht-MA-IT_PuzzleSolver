
#include <iostream>
#include "Context.hpp"

Context::Context()
{
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