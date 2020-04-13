#include "PutPieceInPickupPoint.hpp"
#include "Context.hpp"
#include "MoveRobotClient.hpp"
#include "RecognizePiece.hpp"
#include "Poses.hpp"
#include <geometry_msgs/Pose.h>
#include <memory>

PutPieceInPickupPoint::PutPieceInPickupPoint()
{
}

PutPieceInPickupPoint::~PutPieceInPickupPoint() {}

void PutPieceInPickupPoint::entryAction(Context *)
{
}

void PutPieceInPickupPoint::doActivity(Context *context)
{
    geometry_msgs::Pose pose1 = tf2Handler.calculatePosition(PICKUP_POINT, BASE, PICKUP_POINT_PREPERATION_POSE_1);
    geometry_msgs::Pose pose2 = tf2Handler.calculatePosition(PICKUP_POINT, BASE, PICKUP_POINT_PREPERATION_POSE_2);
    geometry_msgs::Pose pose3 = tf2Handler.calculatePosition(PICKUP_POINT, BASE, PICKUP_POINT_MOVE_SLIDER);
    context->getMoveRobotClient().MoveRobotNormal(0, pose1);
    context->getMoveRobotClient().MoveRobotStraight(0, pose2);
    context->getMoveRobotClient().MoveRobotStraight(0, pose3);
    context->setState(std::make_shared<RecognizePiece>());
}

void PutPieceInPickupPoint::exitAction(Context *context)
{
    geometry_msgs::Pose moveBackPose1 = tf2Handler.calculatePosition(PICKUP_POINT, BASE, PICKUP_POINT_MOVE_BACK_1);
    context->getMoveRobotClient().MoveRobotStraight(0, moveBackPose1);
    geometry_msgs::Pose moveBackPose2 = tf2Handler.calculatePosition(PICKUP_POINT, BASE, PICKUP_POINT_MOVE_BACK_2);
    context->getMoveRobotClient().MoveRobotStraight(0, moveBackPose2);
}
