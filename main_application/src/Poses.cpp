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

void initializePoses()
{
    /**
     * Poses seen from the "eyes" of the pickuppoint
    **/

    PICKUP_POINT_PREPERATION_POSE_1.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_1.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_1.position.z = 0.42;
    PICKUP_POINT_PREPERATION_POSE_1.orientation.x = 0.0143044;
    PICKUP_POINT_PREPERATION_POSE_1.orientation.y = 0.695357;
    PICKUP_POINT_PREPERATION_POSE_1.orientation.z = -0.00627331;
    PICKUP_POINT_PREPERATION_POSE_1.orientation.w = 0.718494;

    PICKUP_POINT_PREPERATION_POSE_2.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_2.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_2.position.z = 0.25;
    PICKUP_POINT_PREPERATION_POSE_2.orientation.x = 0.0143044;
    PICKUP_POINT_PREPERATION_POSE_2.orientation.y = 0.695357;
    PICKUP_POINT_PREPERATION_POSE_2.orientation.z = -0.00627331;
    PICKUP_POINT_PREPERATION_POSE_2.orientation.w = 0.718494;

    PICKUP_POINT_MOVE_BACK.position.x = -0.23;
    PICKUP_POINT_MOVE_BACK.position.y = -0.25;
    PICKUP_POINT_MOVE_BACK.position.z = 0.5;
    PICKUP_POINT_MOVE_BACK.orientation.x = 0.0143044;
    PICKUP_POINT_MOVE_BACK.orientation.y = 0.695357;
    PICKUP_POINT_MOVE_BACK.orientation.z = -0.00627331;
    PICKUP_POINT_MOVE_BACK.orientation.w = 0.718494;

    PICKUP_POINT_MOVE_SLIDER.position.x = -0.23;
    PICKUP_POINT_MOVE_SLIDER.position.y = -0.25;
    PICKUP_POINT_MOVE_SLIDER.position.z = 0.25;
    PICKUP_POINT_MOVE_SLIDER.orientation.x = 0.0143044;
    PICKUP_POINT_MOVE_SLIDER.orientation.y = 0.695357;
    PICKUP_POINT_MOVE_SLIDER.orientation.z = -0.00627331;
    PICKUP_POINT_MOVE_SLIDER.orientation.w = 0.718494;

    tf2::Quaternion pickupPointAngle;
    pickupPointAngle.setRPY(0, 2.15, 1.57);

    PICKUP_POINT_CIRCLE_PREPARE.position.x = 0;
    PICKUP_POINT_CIRCLE_PREPARE.position.y = 0.255;
    PICKUP_POINT_CIRCLE_PREPARE.position.z = 0.1; // 0.08
    PICKUP_POINT_CIRCLE_PREPARE.orientation.x = pickupPointAngle.x();
    PICKUP_POINT_CIRCLE_PREPARE.orientation.y = pickupPointAngle.y();
    PICKUP_POINT_CIRCLE_PREPARE.orientation.z = pickupPointAngle.z();
    PICKUP_POINT_CIRCLE_PREPARE.orientation.w = pickupPointAngle.w();

    PICKUP_POINT_CIRCLE.position.x = 0;
    PICKUP_POINT_CIRCLE.position.y = 0.248;
    PICKUP_POINT_CIRCLE.position.z = 0.09; // 0.08
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
}