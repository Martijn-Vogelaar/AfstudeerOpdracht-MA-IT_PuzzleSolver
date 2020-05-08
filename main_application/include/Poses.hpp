#ifndef POSES_HPP
#define POSES_HPP

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>

#include "Shapes.hpp"

#include <string>


/**
 * @brief PuzzlePiecePoses stores the pose where a puzzlepiece has to be pickedup and where it should be placed
 * 
 */
struct PuzzlePiecePoses
{
    geometry_msgs::Pose pickupPose;
    geometry_msgs::Pose placePose;
};

const std::string BASE = "base";
const std::string PICKUP_POINT = "pickuppoint";
const std::string PUZZLE = "EmptyPuzzle";

extern PuzzlePiecePoses Circle1Poses;
extern PuzzlePiecePoses Circle2Poses;
extern PuzzlePiecePoses SquarePoses;
extern PuzzlePiecePoses Rectangle1Poses;
extern PuzzlePiecePoses Rectangle2Poses;



extern geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_1;
extern geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_2;
extern geometry_msgs::Pose PICKUP_POINT_MOVE_BACK_1;
extern geometry_msgs::Pose PICKUP_POINT_MOVE_BACK_2;
extern geometry_msgs::Pose PICKUP_POINT_MOVE_SLIDER;
extern geometry_msgs::Pose PICKUP_POINT_MOVE_PIECE;



extern geometry_msgs::Pose ROBOT_HOME_POSE;
extern geometry_msgs::Pose ROBOT_HOME_POSE2;

/**
 * @brief Initializes all poses
 * 
 */
extern void initializePoses();

extern geometry_msgs::Pose getPuzzlePiecePreparePickup(Shape puzzlePiece);
extern geometry_msgs::Pose getPuzzlePiecePickup(Shape puzzlePiece);
extern geometry_msgs::Pose getPuzzlePiecePreparePlace(Shape puzzlePiece);
extern geometry_msgs::Pose getPuzzlePiecePlace(Shape puzzlePiece);

#endif //POSES_HPP