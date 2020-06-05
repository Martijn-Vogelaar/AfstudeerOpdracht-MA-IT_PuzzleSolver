#ifndef MODEL_SPAWNER_HPP
#define MODEL_SPAWNER_HPP


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
    */
   void spawnPuzzlePiece();
};

#endif //MOVE_ROBOT_CLIENT_HPP