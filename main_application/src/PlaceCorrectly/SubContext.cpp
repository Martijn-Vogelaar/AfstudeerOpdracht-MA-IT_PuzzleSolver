#include "PlaceCorrectly/SubContext.hpp"
#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"

SubContext::SubContext(Context *aParentContext) : parentContext(aParentContext)
{
  setState(std::make_shared<PlacePieceInPuzzle>());
}

Context* SubContext::getParentContext()
{
  return parentContext;
}


void SubContext::setState(const std::shared_ptr<SubState> &state)
{
  if (currentSubState)
  {
    currentSubState->exitAction(this);
  }
  currentSubState = state;

  currentSubState->entryAction(this);
}



void SubContext::run()
{
  currentSubState->doActivity(this);
}


