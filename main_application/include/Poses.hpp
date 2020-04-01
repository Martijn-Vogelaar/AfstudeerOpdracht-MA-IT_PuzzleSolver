#ifndef POSES_HPP
#define POSES_HPP

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>

#include <string>
const std::string BASE = "base";
const std::string PICKUP_POINT = "pickuppoint";

extern geometry_msgs::Pose PICKUP_POINT_CIRCLE;
extern geometry_msgs::Pose PICKUP_POINT_CIRCLE_PREPARE;
extern geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_1;
extern geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_2;
extern geometry_msgs::Pose PICKUP_POINT_MOVE_BACK;
extern geometry_msgs::Pose PICKUP_POINT_MOVE_SLIDER;
extern geometry_msgs::Pose PICKUP_POINT_MOVE_PIECE;
extern geometry_msgs::Pose ROBOT_HOME_POSE;

extern void initializePoses();
#endif //POSES_HPP