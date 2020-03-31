#include "Poses.hpp"

geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_1;
geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_2;
geometry_msgs::Pose PICKUP_POINT_MOVE_SLIDER;
geometry_msgs::Pose ROBOT_HOME_POSE;

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

    PICKUP_POINT_MOVE_SLIDER.position.x = -0.23;
    PICKUP_POINT_MOVE_SLIDER.position.y = -0.25;
    PICKUP_POINT_MOVE_SLIDER.position.z = 0.25;
    PICKUP_POINT_MOVE_SLIDER.orientation.x = 0.0143044;
    PICKUP_POINT_MOVE_SLIDER.orientation.y = 0.695357;
    PICKUP_POINT_MOVE_SLIDER.orientation.z = -0.00627331;
    PICKUP_POINT_MOVE_SLIDER.orientation.w = 0.718494;

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