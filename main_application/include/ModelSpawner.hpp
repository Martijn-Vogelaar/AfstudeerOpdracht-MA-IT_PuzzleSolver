#ifndef MODEL_SPAWNER_HPP
#define MODEL_SPAWNER_HPP

#include "Shapes.hpp"

/**
 * @brief ModelSpawner is able to spawn different kinds of puzzlepieces in gazebo.
 * 
 */
class ModelSpawner
{
  
public:

    ModelSpawner();
   ~ModelSpawner();

    /**
    * @brief spawnPuzzlePiece spawns a puzzle piece in the gazebo simulation.
    * 
    * @param puzzlePiece Depending on the geiven puzzlePiece different puzzle pieces can be spawned in gazebo.
    */
   void spawnPuzzlePiece(Shape puzzlePiece);
};

#endif //MOVE_ROBOT_CLIENT_HPP