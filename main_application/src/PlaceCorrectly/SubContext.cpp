#include "PlaceCorrectly/SubContext.hpp"
#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"

SubContext::SubContext(Context* aParentContext) : parentContext(aParentContext)
{
  setState(std::make_shared<PlacePieceInPuzzle>());
}

// MoveRobotClient &SubContext::getMoveRobotClient()
// {
//   return moveRobotClient;
// }

// ros::NodeHandle &SubContext::getNodeHandler()
// {
//   return nodeHandler;
// }

// void SubContext::setState(const std::shared_ptr<State> &state)
// {
//   if (mCurrentState)
//   {
//     mCurrentState->exitAction(this);
//   }
//   mCurrentState = state;

//   mCurrentState->entryAction(this);
// }

// void SubContext::run()
// {
//   mCurrentState->doActivity(this);
// }

Context* SubContext::getContext(){
  return parentContext;
}
