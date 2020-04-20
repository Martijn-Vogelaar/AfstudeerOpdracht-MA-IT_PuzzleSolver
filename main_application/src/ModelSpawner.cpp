#include "ModelSpawner.hpp"
#include <cstdlib>
#include <iostream>

ModelSpawner::ModelSpawner()
{
}
ModelSpawner::~ModelSpawner()
{
}

void ModelSpawner::spawnPuzzlePiece(Shape puzzlePiece)
{
    int outcome;
    switch (puzzlePiece)
    {
    case Shape::CIRCLE:
        outcome = std::system("roslaunch simulation circle1.launch");
        break;
    case Shape::CIRCLE2:
        outcome = std::system("roslaunch simulation circle2.launch");
        break;
    case Shape::SQUARE:
        outcome = std::system("roslaunch simulation square.launch");
        break;
    case Shape::RECTANGLE_1:
    case Shape::RECTANGLE_2:
        outcome = std::system("roslaunch simulation rectangle.launch");
        break;
    default:
        outcome = 1;
        break;
    }
    if (outcome == 1)
    {
        std::cout << "Something went wrong spawning the puzzlePiece" << std::endl;
    }
}