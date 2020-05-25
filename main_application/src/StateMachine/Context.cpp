
#include "Context.hpp"
#include "Init.hpp"
#include "Poses.hpp"
#include "PuzzlePieceSpot.hpp"
#include <tf2/LinearMath/Quaternion.h>

Context::Context() : currentPuzzlePieceShape(Shape::UNKNOWN), currentPuzzlePieceSpot(PuzzlePieceSpot())
{
  setState(std::make_shared<Init>());
  puzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::RECTANGLE_1, Rectangle1Poses.placePose, 1));
  puzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::RECTANGLE_2, Rectangle2Poses.placePose, 1));
  puzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::CIRCLE, Circle1Poses.placePose, 2));
  puzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::CIRCLE, Circle2Poses.placePose, 3));
  puzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::SQUARE, SquarePoses.placePose, 4));
  // puzzle.setSpotFilled(2);
}

MoveRobotClient &Context::getMoveRobotClient()
{
  return moveRobotClient;
}

ros::NodeHandle &Context::getNodeHandler()
{
  return nodeHandler;
}

Puzzle &Context::getPuzzle()
{
  return puzzle;
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
  currentPuzzlePieceShape = puzzlePieceMeasurementToEnum(aPuzzlePiece);
}

void Context::findEmptyUnexploredPuzzleSpot()
{
  PuzzlePieceSpot *foundSpot = puzzle.getEmptyPuzzleSpot(currentPuzzlePieceShape);
  if (foundSpot) // Check if a spot was found
  {
    currentPuzzlePieceSpot = *foundSpot;
  }
  else
  {
    currentPuzzlePieceSpot = PuzzlePieceSpot();
  }
}

PuzzlePieceSpot Context::getCurrentPuzzlePieceSpot()
{
  return currentPuzzlePieceSpot;
}

Shape Context::getCurrentShape()
{
  return currentPuzzlePieceShape;
}

void Context::run()
{
  mCurrentState->doActivity(this);
}