
#include "Context.hpp"
#include "Init.hpp"

Context::Context() : currentPuzzlePiece(Shape::UNKNOWN)
{
  setState(std::make_shared<Init>());
}

MoveRobotClient &Context::getMoveRobotClient()
{
  return moveRobotClient;
}

ros::NodeHandle &Context::getNodeHandler()
{
  return nodeHandler;
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

void Context::setCurrentPuzzlePiece(uint8_t aPuzzlePiece)
{
  currentPuzzlePiece = puzzlePieceMeasurementToEnum(aPuzzlePiece);
}

void Context::setCurrentPuzzlePiece(Shape aPuzzlePiece)
{
  currentPuzzlePiece = aPuzzlePiece;
}

Shape Context::getCurrentPuzzlePiece()
{
  return currentPuzzlePiece;
}

void Context::run()
{
  mCurrentState->doActivity(this);
}