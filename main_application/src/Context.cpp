
#include <iostream>
#include "Context.hpp"
#include "Init.hpp"

Context::Context()
{
  setState(std::make_shared<Init>());
}

MoveRobotClient& Context::getMoveRobotClient(){
  return moveRobotClient;
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