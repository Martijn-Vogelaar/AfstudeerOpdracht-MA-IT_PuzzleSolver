#include "Poses.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include "ros/ros.h"
geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_1;
geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_2;
geometry_msgs::Pose PICKUP_POINT_MOVE_BACK_1;
geometry_msgs::Pose PICKUP_POINT_MOVE_BACK_2;
geometry_msgs::Pose PICKUP_POINT_MOVE_SLIDER;
geometry_msgs::Pose PICKUP_POINT_MOVE_PIECE;
geometry_msgs::Pose ROBOT_HOME_POSE;

PuzzlePiecePoses CirclePoses;
PuzzlePiecePoses SquarePoses;
PuzzlePiecePoses Rectangle1Poses;
PuzzlePiecePoses Rectangle2Poses;

void initializePoses()
{
    tf2::Quaternion pickupPointAngle;
    pickupPointAngle.setRPY(0, 2.105, 1.57);

    tf2::Quaternion puzzleAngle;
    puzzleAngle.setRPY(0, 1.57, 0.78539);

    tf2::Quaternion pickupPointMovementAngle;
    pickupPointMovementAngle.setRPY(0, 1.57, 0);
    /**
     * Poses seen from the "eyes" of the pickuppoint
    **/

    PICKUP_POINT_PREPERATION_POSE_1.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_1.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_1.position.z = 0.42;
    PICKUP_POINT_PREPERATION_POSE_1.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_PREPERATION_POSE_2.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_2.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_2.position.z = 0.25;
    PICKUP_POINT_PREPERATION_POSE_2.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_SLIDER.position.x = -0.23;
    PICKUP_POINT_MOVE_SLIDER.position.y = -0.25;
    PICKUP_POINT_MOVE_SLIDER.position.z = 0.25;
    PICKUP_POINT_MOVE_SLIDER.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_SLIDER.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_SLIDER.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_SLIDER.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_BACK_1.position.x = -0.23;
    PICKUP_POINT_MOVE_BACK_1.position.y = -0.3;
    PICKUP_POINT_MOVE_BACK_1.position.z = 0.25;
    PICKUP_POINT_MOVE_BACK_1.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_BACK_1.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_BACK_1.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_BACK_1.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_BACK_2.position.x = -0.23;
    PICKUP_POINT_MOVE_BACK_2.position.y = -0.3;
    PICKUP_POINT_MOVE_BACK_2.position.z = 0.5;
    PICKUP_POINT_MOVE_BACK_2.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_BACK_2.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_BACK_2.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_BACK_2.orientation.w = pickupPointMovementAngle.w();

    /*************************************
     * Poses seen from the ROBOT         *
     *************************************/
    ROBOT_HOME_POSE.position.x = 0.424;
    ROBOT_HOME_POSE.position.y = 0;
    ROBOT_HOME_POSE.position.z = 0.65;
    ROBOT_HOME_POSE.orientation.x = 0.0;
    ROBOT_HOME_POSE.orientation.y = 0.0;
    ROBOT_HOME_POSE.orientation.z = 0.0;
    ROBOT_HOME_POSE.orientation.w = 1.0;

    /*************************************
     * Circle POSES                      *
     *************************************/

    CirclePoses.preparePickupPose.position.x = 0;
    CirclePoses.preparePickupPose.position.y = 0.255;
    CirclePoses.preparePickupPose.position.z = 0.1;
    CirclePoses.preparePickupPose.orientation.x = pickupPointAngle.x();
    CirclePoses.preparePickupPose.orientation.y = pickupPointAngle.y();
    CirclePoses.preparePickupPose.orientation.z = pickupPointAngle.z();
    CirclePoses.preparePickupPose.orientation.w = pickupPointAngle.w();

    CirclePoses.pickupPose.position.x = 0;
    CirclePoses.pickupPose.position.y = 0.248;
    CirclePoses.pickupPose.position.z = 0.09;
    CirclePoses.pickupPose.orientation.x = pickupPointAngle.x();
    CirclePoses.pickupPose.orientation.y = pickupPointAngle.y();
    CirclePoses.pickupPose.orientation.z = pickupPointAngle.z();
    CirclePoses.pickupPose.orientation.w = pickupPointAngle.w();

    CirclePoses.preparePlacePose.position.x = -0.07315;
    CirclePoses.preparePlacePose.position.y = 0.143;
    CirclePoses.preparePlacePose.position.z = 0.08;
    CirclePoses.preparePlacePose.orientation.x = puzzleAngle.x();
    CirclePoses.preparePlacePose.orientation.y = puzzleAngle.y();
    CirclePoses.preparePlacePose.orientation.z = puzzleAngle.z();
    CirclePoses.preparePlacePose.orientation.w = puzzleAngle.w();

    CirclePoses.placePose.position.x = -0.07315;
    CirclePoses.placePose.position.y = 0.143;
    CirclePoses.placePose.position.z = 0.012;
    CirclePoses.placePose.orientation.x = puzzleAngle.x();
    CirclePoses.placePose.orientation.y = puzzleAngle.y();
    CirclePoses.placePose.orientation.z = puzzleAngle.z();
    CirclePoses.placePose.orientation.w = puzzleAngle.w();

    /*************************************
     * Square POSES                      *
     *************************************/

    SquarePoses.preparePickupPose.position.x = 0;
    SquarePoses.preparePickupPose.position.y = 0.255;
    SquarePoses.preparePickupPose.position.z = 0.1;
    SquarePoses.preparePickupPose.orientation.x = pickupPointAngle.x();
    SquarePoses.preparePickupPose.orientation.y = pickupPointAngle.y();
    SquarePoses.preparePickupPose.orientation.z = pickupPointAngle.z();
    SquarePoses.preparePickupPose.orientation.w = pickupPointAngle.w();

    SquarePoses.pickupPose.position.x = 0;
    SquarePoses.pickupPose.position.y = 0.2497;
    SquarePoses.pickupPose.position.z = 0.084;
    SquarePoses.pickupPose.orientation.x = pickupPointAngle.x();
    SquarePoses.pickupPose.orientation.y = pickupPointAngle.y();
    SquarePoses.pickupPose.orientation.z = pickupPointAngle.z();
    SquarePoses.pickupPose.orientation.w = pickupPointAngle.w();

    SquarePoses.preparePlacePose.position.x = -0.081375;
    SquarePoses.preparePlacePose.position.y = -0.07875;
    SquarePoses.preparePlacePose.position.z = 0.08;
    SquarePoses.preparePlacePose.orientation.x = puzzleAngle.x();
    SquarePoses.preparePlacePose.orientation.y = puzzleAngle.y();
    SquarePoses.preparePlacePose.orientation.z = puzzleAngle.z();
    SquarePoses.preparePlacePose.orientation.w = puzzleAngle.w();

    SquarePoses.placePose.position.x = -0.081375;
    SquarePoses.placePose.position.y = -0.07875;
    SquarePoses.placePose.position.z = 0.01;
    SquarePoses.placePose.orientation.x = puzzleAngle.x();
    SquarePoses.placePose.orientation.y = puzzleAngle.y();
    SquarePoses.placePose.orientation.z = puzzleAngle.z();
    SquarePoses.placePose.orientation.w = puzzleAngle.w();

    /*************************************
     * Rectangle1 POSES                  *
     *************************************/

    Rectangle1Poses.preparePickupPose.position.x = 0;
    Rectangle1Poses.preparePickupPose.position.y = 0;
    Rectangle1Poses.preparePickupPose.position.z = 0;
    Rectangle1Poses.preparePickupPose.orientation.x = pickupPointAngle.x();
    Rectangle1Poses.preparePickupPose.orientation.y = pickupPointAngle.y();
    Rectangle1Poses.preparePickupPose.orientation.z = pickupPointAngle.z();
    Rectangle1Poses.preparePickupPose.orientation.w = pickupPointAngle.w();

    Rectangle1Poses.pickupPose.position.x = 0;
    Rectangle1Poses.pickupPose.position.y = 0;
    Rectangle1Poses.pickupPose.position.z = 0;
    Rectangle1Poses.pickupPose.orientation.x = pickupPointAngle.x();
    Rectangle1Poses.pickupPose.orientation.y = pickupPointAngle.y();
    Rectangle1Poses.pickupPose.orientation.z = pickupPointAngle.z();
    Rectangle1Poses.pickupPose.orientation.w = pickupPointAngle.w();

    Rectangle1Poses.preparePlacePose.position.x = 0.1;
    Rectangle1Poses.preparePlacePose.position.y = 0.1;
    Rectangle1Poses.preparePlacePose.position.z = 0.2;
    Rectangle1Poses.preparePlacePose.orientation.x = puzzleAngle.x();
    Rectangle1Poses.preparePlacePose.orientation.y = puzzleAngle.y();
    Rectangle1Poses.preparePlacePose.orientation.z = puzzleAngle.z();
    Rectangle1Poses.preparePlacePose.orientation.w = puzzleAngle.w();

    Rectangle1Poses.placePose.position.x = 0.1;
    Rectangle1Poses.placePose.position.y = 0.1;
    Rectangle1Poses.placePose.position.z = 0.2;
    Rectangle1Poses.placePose.orientation.x = puzzleAngle.x();
    Rectangle1Poses.placePose.orientation.y = puzzleAngle.y();
    Rectangle1Poses.placePose.orientation.z = puzzleAngle.z();
    Rectangle1Poses.placePose.orientation.w = puzzleAngle.w();

    /*************************************
     * Rectangle2 POSES                  *
     *************************************/

    Rectangle2Poses.preparePickupPose.position.x = 0;
    Rectangle2Poses.preparePickupPose.position.y = 0;
    Rectangle2Poses.preparePickupPose.position.z = 0;
    Rectangle2Poses.preparePickupPose.orientation.x = pickupPointAngle.x();
    Rectangle2Poses.preparePickupPose.orientation.y = pickupPointAngle.y();
    Rectangle2Poses.preparePickupPose.orientation.z = pickupPointAngle.z();
    Rectangle2Poses.preparePickupPose.orientation.w = pickupPointAngle.w();

    Rectangle2Poses.pickupPose.position.x = 0;
    Rectangle2Poses.pickupPose.position.y = 0;
    Rectangle2Poses.pickupPose.position.z = 0;
    Rectangle2Poses.pickupPose.orientation.x = pickupPointAngle.x();
    Rectangle2Poses.pickupPose.orientation.y = pickupPointAngle.y();
    Rectangle2Poses.pickupPose.orientation.z = pickupPointAngle.z();
    Rectangle2Poses.pickupPose.orientation.w = pickupPointAngle.w();

    Rectangle2Poses.preparePlacePose.position.x = 0.1;
    Rectangle2Poses.preparePlacePose.position.y = 0.1;
    Rectangle2Poses.preparePlacePose.position.z = 0.2;
    Rectangle2Poses.preparePlacePose.orientation.x = puzzleAngle.x();
    Rectangle2Poses.preparePlacePose.orientation.y = puzzleAngle.y();
    Rectangle2Poses.preparePlacePose.orientation.z = puzzleAngle.z();
    Rectangle2Poses.preparePlacePose.orientation.w = puzzleAngle.w();

    Rectangle2Poses.placePose.position.x = 0.1;
    Rectangle2Poses.placePose.position.y = 0.1;
    Rectangle2Poses.placePose.position.z = 0.2;
    Rectangle2Poses.placePose.orientation.x = puzzleAngle.x();
    Rectangle2Poses.placePose.orientation.y = puzzleAngle.y();
    Rectangle2Poses.placePose.orientation.z = puzzleAngle.z();
    Rectangle2Poses.placePose.orientation.w = puzzleAngle.w();

    PICKUP_POINT_MOVE_PIECE.position.x = 0;
    PICKUP_POINT_MOVE_PIECE.position.y = 0.248;
    PICKUP_POINT_MOVE_PIECE.position.z = 0.30; // 0.08
    PICKUP_POINT_MOVE_PIECE.orientation.x = pickupPointAngle.x();
    PICKUP_POINT_MOVE_PIECE.orientation.y = pickupPointAngle.y();
    PICKUP_POINT_MOVE_PIECE.orientation.z = pickupPointAngle.z();
    PICKUP_POINT_MOVE_PIECE.orientation.w = pickupPointAngle.w();

    /**
     * Poses seen from the eyes of the Puzzle
     * 
     * rectangle = induc 0
     * circle left under = induc 1
     * circle right up = induc 2
     * square = induc 3
     */
}

geometry_msgs::Pose getPreparePickup();

geometry_msgs::Pose getPuzzlePiecePreparePickup(Shape puzzlePiece)
{
    switch (puzzlePiece)
    {
    case Shape::CIRCLE:
        return CirclePoses.preparePickupPose;
    case Shape::SQUARE:
        return SquarePoses.preparePickupPose;
    case Shape::RECTANGLE_1:
        return Rectangle1Poses.preparePickupPose;
    case Shape::RECTANGLE_2:
        return Rectangle2Poses.preparePickupPose;
    default:
        return CirclePoses.preparePickupPose;
    }
    return CirclePoses.preparePickupPose;
}

geometry_msgs::Pose getPuzzlePiecePickup(Shape puzzlePiece)
{
    switch (puzzlePiece)
    {
    case Shape::CIRCLE:
        return CirclePoses.pickupPose;
    case Shape::SQUARE:
        return SquarePoses.pickupPose;
    case Shape::RECTANGLE_1:
        return Rectangle1Poses.pickupPose;
    case Shape::RECTANGLE_2:
        return Rectangle2Poses.pickupPose;
    default:
        return CirclePoses.pickupPose;
    }
    return CirclePoses.pickupPose;
}

geometry_msgs::Pose getPuzzlePiecePreparePlace(Shape puzzlePiece)
{
    
    switch (puzzlePiece)
    {
    case Shape::CIRCLE:
        ROS_ERROR("CIRCLE");
        return CirclePoses.preparePlacePose;
    case Shape::SQUARE:
        ROS_ERROR("SQUARE");
        return SquarePoses.preparePlacePose;
    case Shape::RECTANGLE_1:
        ROS_ERROR("RECTANGLE_1");
        return Rectangle1Poses.preparePlacePose;
    case Shape::RECTANGLE_2:
        ROS_ERROR("RECTANGLE_2");
        return Rectangle2Poses.preparePlacePose;
    case Shape::UNKNOWN:
        ROS_ERROR("UNKNOWN");
    default:
        return CirclePoses.preparePlacePose;
    }
    return CirclePoses.pickupPose;
}

geometry_msgs::Pose getPuzzlePiecePlace(Shape puzzlePiece)
{
    switch (puzzlePiece)
    {
    case Shape::CIRCLE:
        return CirclePoses.placePose;
    case Shape::SQUARE:
        return SquarePoses.placePose;
    case Shape::RECTANGLE_1:
        return Rectangle1Poses.placePose;
    case Shape::RECTANGLE_2:
        return Rectangle2Poses.placePose;
    default:
        return CirclePoses.placePose;
    }
    return CirclePoses.pickupPose;
}