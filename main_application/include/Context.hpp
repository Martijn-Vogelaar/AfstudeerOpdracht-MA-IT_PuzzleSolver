#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "State.hpp"
#include <memory>
#include "MoveRobotClient.hpp"
#include "Shapes.hpp"

#define QUEUE_SIZE 1000

class State;
/**
   * @class Context
   *
   * @brief Context is a class which gives the states an interface to the
   * "outside world".
   *
   */
class Context
{
public:
  /**
     * @brief Construct a new Context object
     *
     */
  Context();

  /**
    * @brief Get the Move Robot Client object
    * 
    */
  MoveRobotClient &getMoveRobotClient();

  /**
    * @brief Get the Node Handler object
    * 
    * @return ros::NodeHandle& 
    */
  ros::NodeHandle &getNodeHandler();

  /**
     * @brief Set the currentState by supplying a shared_ptr to a state.
     *
     * @param state
     */
  void setState(const std::shared_ptr<State> &state);

  /**
     * @brief Run is the function which takes care of the handling of the
     * EventQueue and calling the doActivity functions of the different states.
     */
  void run();

  /**
   * @brief Set the Current Puzzle Piece object
   * 
   * @param aPuzzlePiece 
   */
  void setCurrentPuzzlePiece(uint8_t aPuzzlePiece);

  /**
   * @brief Set the Current Puzzle Piece object
   * 
   * @param aPuzzlePiece 
   */
  void setCurrentPuzzlePiece(Shape aPuzzlePiece);

  /**
   * @brief Get the Current Puzzle Piece object
   * 
   * @return Shape 
   */
  Shape getCurrentPuzzlePiece();

private:
  MoveRobotClient moveRobotClient;
  ros::NodeHandle nodeHandler;
  std::shared_ptr<State> mCurrentState;
  Shape currentPuzzlePiece;
};
#endif // Context_HPP