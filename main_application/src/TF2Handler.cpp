#include "TF2Handler.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
TF2Handler::TF2Handler() : mTfListener(mBuffer)
{
}

geometry_msgs::Pose TF2Handler::calculatePosition(const std::string &aFromFrame,
                                                  const std::string &aToFrame, geometry_msgs::Pose &aPose)
{

    geometry_msgs::TransformStamped lTransformStamped;
    lTransformStamped.header.stamp = ros::Time::now();
    lTransformStamped.header.frame_id = aFromFrame;

    lTransformStamped.transform.translation.x = aPose.position.x;
    lTransformStamped.transform.translation.y = aPose.position.y;
    lTransformStamped.transform.translation.z = aPose.position.z;


    tf2::Quaternion lQ = tf2::Quaternion(aPose.orientation.x,
                                         aPose.orientation.y,
                                         aPose.orientation.z,
                                         aPose.orientation.w);

    lQ.normalize();
 lTransformStamped.transform.rotation.x = lQ.x();
    lTransformStamped.transform.rotation.y = lQ.y();
    lTransformStamped.transform.rotation.z = lQ.z();
    lTransformStamped.transform.rotation.w = lQ.w();

    
    lTransformStamped = mBuffer.transform(lTransformStamped, aToFrame , ros::Duration(3.0));

    geometry_msgs::Pose lPose;
    lPose.position.x = lTransformStamped.transform.translation.x;
    lPose.position.y = lTransformStamped.transform.translation.y;
    lPose.position.z = lTransformStamped.transform.translation.z;
    lPose.orientation.x = lTransformStamped.transform.rotation.x;
    lPose.orientation.y = lTransformStamped.transform.rotation.y;
    lPose.orientation.z = lTransformStamped.transform.rotation.z;
    lPose.orientation.w = lTransformStamped.transform.rotation.w;

    return lPose;
}