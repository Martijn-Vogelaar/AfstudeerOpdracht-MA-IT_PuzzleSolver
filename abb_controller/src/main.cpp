#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <tf/transform_datatypes.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  static const std::string PLANNING_GROUP = "manipulator";

  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
  move_group.setPlannerId("RRTConnectkConfigDefault");
  const robot_state::JointModelGroup *joint_model_group =
      move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
  move_group.setNumPlanningAttempts(100);

  geometry_msgs::Pose currentPose = move_group.getCurrentPose().pose;
  ROS_ERROR(std::string(std::to_string(currentPose.position.x) + "-" + std::to_string(currentPose.position.y)+ "-"+ std::to_string(currentPose.position.z)).c_str());

  // ROS_ERROR(std::to_string(currentPose.position.x).c_str());
  // ROS_ERROR(std::to_string(currentPose.position.y).c_str());
  // ROS_ERROR(std::to_string(currentPose.position.z).c_str());

  geometry_msgs::Pose target_pose1;

  std::vector<geometry_msgs::Pose> waypoints;
  // for (double i = 0; i < 0.04; i += 0.02)
  // {
  //   geometry_msgs::Pose newPose;
  //   newPose.position.x = currentPose.position.x - i;
  //   newPose.position.z = currentPose.position.z - i;
  //   newPose.position.y = currentPose.position.y;

  //   waypoints.push_back(newPose);
  //   ROS_ERROR(std::string(std::to_string(newPose.position.x) + "-" + std::to_string(newPose.position.y)+ "-"+
  //   std::to_string(newPose.position.z)).c_str());
  // }
  if (true)
  {
    geometry_msgs::Pose newPose;
    newPose.position.x = currentPose.position.x - 0.30;
    newPose.position.y = currentPose.position.y;
    newPose.position.z = currentPose.position.z;
    waypoints.push_back(newPose);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;

    moveit_msgs::RobotTrajectory trajectory;
    const double jump_threshold = 0.0;
    const double eef_step = 0.001;
    double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
    my_plan.trajectory_ = trajectory;
    if(move_group.execute(my_plan)){
      ROS_ERROR("SUCCES");
    };
  }

  waypoints.clear();
  if (true)
  {
    geometry_msgs::Pose newPose;
      geometry_msgs::Pose currentPose2 = move_group.getCurrentPose().pose;
  ROS_ERROR(std::string(std::to_string(currentPose2.position.x) + "-" + std::to_string(currentPose2.position.y)+ "-"+ std::to_string(currentPose2.position.z)).c_str());

    newPose.position.x = currentPose2.position.x + 0.10;
    newPose.position.y = currentPose2.position.y;
    newPose.position.z = currentPose2.position.z;
    waypoints.push_back(newPose);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;

    moveit_msgs::RobotTrajectory trajectory;
    const double jump_threshold = 0.0;
    const double eef_step = 0.01;
    double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
    my_plan.trajectory_ = trajectory;
    move_group.execute(my_plan);
  }
  tf::Quaternion q;
  currentPose = move_group.getCurrentPose().pose;
  for (double i = -2; i <= 2; i += 0.25)
  {
    q.setRPY(i, i, i);

    target_pose1.position.x = currentPose.position.x;
    target_pose1.position.y = currentPose.position.y;
    target_pose1.position.z = currentPose.position.z;
    target_pose1.orientation.w = q.w();
    target_pose1.orientation.x = q.x();
    target_pose1.orientation.y = q.y();
    target_pose1.orientation.z = q.z();
    move_group.setPoseTarget(target_pose1);

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;

    bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    move_group.move();
  }

  ros::shutdown();
  return 0;
}