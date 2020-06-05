#include "ModelSpawner.hpp"
#include <cstdlib>
#include <iostream>
#include "ros/ros.h"
ModelSpawner::ModelSpawner()
{
}
ModelSpawner::~ModelSpawner()
{
}

void ModelSpawner::spawnPuzzlePiece()
{
    static uint8_t count = 0;
    int outcome;
    switch (count)
    {
    case 0:
        outcome = std::system("roslaunch simulation circle2.launch");
        break;
    case 1:
        outcome = std::system("roslaunch simulation circle1.launch");
        break;
    case 2:
        outcome = std::system("roslaunch simulation square.launch");
        break;
    case 3:
        outcome = std::system("roslaunch simulation rectangle.launch");
        break;
    default:
        outcome = 0;
        break;
    }
    if(outcome != 0){
        ROS_ERROR("Something went wrong spawning the puzzlePiece");
    }
}