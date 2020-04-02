#include "Poses.hpp"
#include <tf2/LinearMath/Quaternion.h>

geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_1;
geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_2;
geometry_msgs::Pose PICKUP_POINT_MOVE_BACK;
geometry_msgs::Pose PICKUP_POINT_MOVE_SLIDER;
geometry_msgs::Pose PICKUP_POINT_MOVE_PIECE;
geometry_msgs::Pose ROBOT_HOME_POSE;
geometry_msgs::Pose PICKUP_POINT_CIRCLE;
geometry_msgs::Pose PICKUP_POINT_CIRCLE_PREPARE;
geometry_msgs::Pose PUZZLE_CIRCLE_1_PREPARE;
geometry_msgs::Pose PUZZLE_CIRCLE_1;
geometry_msgs::Pose PUZZLE_CIRCLE_2_PREPARE;
geometry_msgs::Pose PUZZLE_CIRCLE_2;
geometry_msgs::Pose PUZZLE_RECTANGLE_PREPARE;
geometry_msgs::Pose PUZZLE_RECTANGLE;
geometry_msgs::Pose PUZZLE_SQUARE_PREPARE;
geometry_msgs::Pose PUZZLE_SQUARE;
void initializePoses()
{
    /**
     * Poses seen from the "eyes" of the pickuppoint
    **/
    tf2::Quaternion pickupPointMovementAngle;
    pickupPointMovementAngle.setRPY(0, 1.57, 0);

    PICKUP_POINT_PREPERATION_POSE_1.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_1.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_1.position.z = 0.42;
    PICKUP_POINT_PREPERATION_POSE_1.orientation.x= pickupPointMovementAngle.x();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.y= pickupPointMovementAngle.y();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.z= pickupPointMovementAngle.z();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.w= pickupPointMovementAngle.w();

    PICKUP_POINT_PREPERATION_POSE_2.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_2.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_2.position.z = 0.25;
    PICKUP_POINT_PREPERATION_POSE_2.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_BACK.position.x = -0.23;
    PICKUP_POINT_MOVE_BACK.position.y = -0.25;
    PICKUP_POINT_MOVE_BACK.position.z = 0.5;
    PICKUP_POINT_MOVE_BACK.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_BACK.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_BACK.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_BACK.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_SLIDER.position.x = -0.23;
    PICKUP_POINT_MOVE_SLIDER.position.y = -0.25;
    PICKUP_POINT_MOVE_SLIDER.position.z = 0.25;
    PICKUP_POINT_MOVE_SLIDER.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_SLIDER.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_SLIDER.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_SLIDER.orientation.w = pickupPointMovementAngle.w();

    tf2::Quaternion pickupPointAngle;
    pickupPointAngle.setRPY(0, 2.105, 1.57);

    // -0.001591
    // -0.013563
    // 
    // 0.007395
    // -0.011433


    PICKUP_POINT_CIRCLE_PREPARE.position.x = 0;
    PICKUP_POINT_CIRCLE_PREPARE.position.y = 0.255;
    PICKUP_POINT_CIRCLE_PREPARE.position.z = 0.1;
    PICKUP_POINT_CIRCLE_PREPARE.orientation.x = pickupPointAngle.x();
    PICKUP_POINT_CIRCLE_PREPARE.orientation.y = pickupPointAngle.y();
    PICKUP_POINT_CIRCLE_PREPARE.orientation.z = pickupPointAngle.z();
    PICKUP_POINT_CIRCLE_PREPARE.orientation.w = pickupPointAngle.w();

    PICKUP_POINT_CIRCLE.position.x = 0;
    PICKUP_POINT_CIRCLE.position.y = 0.248;
    PICKUP_POINT_CIRCLE.position.z = 0.09;
    PICKUP_POINT_CIRCLE.orientation.x = pickupPointAngle.x();
    PICKUP_POINT_CIRCLE.orientation.y = pickupPointAngle.y();
    PICKUP_POINT_CIRCLE.orientation.z = pickupPointAngle.z();
    PICKUP_POINT_CIRCLE.orientation.w = pickupPointAngle.w();

    PICKUP_POINT_MOVE_PIECE.position.x = 0;
    PICKUP_POINT_MOVE_PIECE.position.y = 0.248;
    PICKUP_POINT_MOVE_PIECE.position.z = 0.30; // 0.08
    PICKUP_POINT_MOVE_PIECE.orientation.x = pickupPointAngle.x();
    PICKUP_POINT_MOVE_PIECE.orientation.y = pickupPointAngle.y();
    PICKUP_POINT_MOVE_PIECE.orientation.z = pickupPointAngle.z();
    PICKUP_POINT_MOVE_PIECE.orientation.w = pickupPointAngle.w();
    /**
     * Poses seen from the "eyes" of the Robot
    **/
    ROBOT_HOME_POSE.position.x = 0.424;
    ROBOT_HOME_POSE.position.y = 0;
    ROBOT_HOME_POSE.position.z = 0.65;
    ROBOT_HOME_POSE.orientation.x = 0.0;
    ROBOT_HOME_POSE.orientation.y = 0.0;
    ROBOT_HOME_POSE.orientation.z = 0.0;
    ROBOT_HOME_POSE.orientation.w = 1.0;

    /**
     * Poses seen from the eyes of the Puzzle
     * 
     * rectangle = induc 0
     * circle left under = induc 1
     * circle right up = induc 2
     * square = induc 3
     */

    tf2::Quaternion puzzleAngle;
    puzzleAngle.setRPY(0, 1.57, 0);

    PUZZLE_CIRCLE_1_PREPARE.position.x = -0.07315;
    PUZZLE_CIRCLE_1_PREPARE.position.y = 0.143;
    PUZZLE_CIRCLE_1_PREPARE.position.z = 0.08;
    PUZZLE_CIRCLE_1_PREPARE.orientation.x = puzzleAngle.x();
    PUZZLE_CIRCLE_1_PREPARE.orientation.y = puzzleAngle.y();
    PUZZLE_CIRCLE_1_PREPARE.orientation.z = puzzleAngle.z();
    PUZZLE_CIRCLE_1_PREPARE.orientation.w = puzzleAngle.w();

    PUZZLE_CIRCLE_1.position.x = -0.07315;
    PUZZLE_CIRCLE_1.position.y = 0.143;
    PUZZLE_CIRCLE_1.position.z = 0.02;
    PUZZLE_CIRCLE_1.orientation.x = puzzleAngle.x();
    PUZZLE_CIRCLE_1.orientation.y = puzzleAngle.y();
    PUZZLE_CIRCLE_1.orientation.z = puzzleAngle.z();
    PUZZLE_CIRCLE_1.orientation.w = puzzleAngle.w();

    PUZZLE_CIRCLE_2_PREPARE.position.x = 0.1;
    PUZZLE_CIRCLE_2_PREPARE.position.y = 0.1;
    PUZZLE_CIRCLE_2_PREPARE.position.z = 0.2;
    PUZZLE_CIRCLE_2_PREPARE.orientation.x = puzzleAngle.x();
    PUZZLE_CIRCLE_2_PREPARE.orientation.y = puzzleAngle.y();
    PUZZLE_CIRCLE_2_PREPARE.orientation.z = puzzleAngle.z();
    PUZZLE_CIRCLE_2_PREPARE.orientation.w = puzzleAngle.w();

    PUZZLE_CIRCLE_2.position.x = 0.1;
    PUZZLE_CIRCLE_2.position.y = 0.1;
    PUZZLE_CIRCLE_2.position.z = 0.2;
    PUZZLE_CIRCLE_2.orientation.x = puzzleAngle.x();
    PUZZLE_CIRCLE_2.orientation.y = puzzleAngle.y();
    PUZZLE_CIRCLE_2.orientation.z = puzzleAngle.z();
    PUZZLE_CIRCLE_2.orientation.w = puzzleAngle.w();

    PUZZLE_RECTANGLE_PREPARE.position.x = 0.1;
    PUZZLE_RECTANGLE_PREPARE.position.y = 0.1;
    PUZZLE_RECTANGLE_PREPARE.position.z = 0.2;
    PUZZLE_RECTANGLE_PREPARE.orientation.x = puzzleAngle.x();
    PUZZLE_RECTANGLE_PREPARE.orientation.y = puzzleAngle.y();
    PUZZLE_RECTANGLE_PREPARE.orientation.z = puzzleAngle.z();
    PUZZLE_RECTANGLE_PREPARE.orientation.w = puzzleAngle.w();

    PUZZLE_RECTANGLE.position.x = 0.1;
    PUZZLE_RECTANGLE.position.y = 0.1;
    PUZZLE_RECTANGLE.position.z = 0.2;
    PUZZLE_RECTANGLE.orientation.x = puzzleAngle.x();
    PUZZLE_RECTANGLE.orientation.y = puzzleAngle.y();
    PUZZLE_RECTANGLE.orientation.z = puzzleAngle.z();
    PUZZLE_RECTANGLE.orientation.w = puzzleAngle.w();

    PUZZLE_SQUARE_PREPARE.position.x = 0.1;
    PUZZLE_SQUARE_PREPARE.position.y = 0.1;
    PUZZLE_SQUARE_PREPARE.position.z = 0.2;
    PUZZLE_SQUARE_PREPARE.orientation.x = puzzleAngle.x();
    PUZZLE_SQUARE_PREPARE.orientation.y = puzzleAngle.y();
    PUZZLE_SQUARE_PREPARE.orientation.z = puzzleAngle.z();
    PUZZLE_SQUARE_PREPARE.orientation.w = puzzleAngle.w();

    PUZZLE_SQUARE.position.x = 0.1;
    PUZZLE_SQUARE.position.y = 0.1;
    PUZZLE_SQUARE.position.z = 0.2;
    PUZZLE_SQUARE.orientation.x = puzzleAngle.x();
    PUZZLE_SQUARE.orientation.y = puzzleAngle.y();
    PUZZLE_SQUARE.orientation.z = puzzleAngle.z();
    PUZZLE_SQUARE.orientation.w = puzzleAngle.w();
}