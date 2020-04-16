#ifndef TF2_HANDLER_H
#define TF2_HANDLER_H

#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Pose.h>

#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>

/**
   * @brief Class able to calculate the pose between objects using TF2
   *
   */
class TF2Handler
{
public:
    /**
     * @brief Construct a new TF2Handler object
     *
     */
    TF2Handler();

    /**
     * @brief Destroy the TF2Handler object
     *
     */
    virtual ~TF2Handler() = default;

    /**
     * @brief This functions returns the transformation between the first and second given frame
     *
     * @param aFromFrame From from which the transformation will be made
     * @param aToFrame From to which the transformation will be made
     * @param aPose Pose which has to be transformed from the aFromFrame to the aToFrame
     * @return 
     */
    geometry_msgs::Pose calculatePosition(const std::string &aFromFrame,
                                         const std::string &aToFrame, geometry_msgs::Pose &aPose);

private:
    // tf2_ros::TransformBroadcaster Broadcaster;
    tf2_ros::Buffer mBuffer;
    tf2_ros::TransformListener mTfListener;
};

#endif