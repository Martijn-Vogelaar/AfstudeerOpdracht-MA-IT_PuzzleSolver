// #include <moveit/move_group_interface/move_group_interface.h>
// #include <moveit/planning_scene_interface/planning_scene_interface.h>

// #include <moveit_msgs/DisplayRobotState.h>
// #include <moveit_msgs/DisplayTrajectory.h>

// #include <moveit_msgs/AttachedCollisionObject.h>
// #include <moveit_msgs/CollisionObject.h>

// #include <moveit_visual_tools/moveit_visual_tools.h>
// #include <tf/transform_datatypes.h>

// int main(int argc, char **argv)
// {
//   ros::init(argc, argv, "move_group_interface_tutorial");
//   ros::NodeHandle node_handle;
//   ros::AsyncSpinner spinner(1);
//   spinner.start();
//   ROS_ERROR("AWOW");
//   static const std::string PLANNING_GROUP = "manipulator";

//   moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
//   move_group.setPlannerId("RRTConnectkConfigDefault");
//   const robot_state::JointModelGroup *joint_model_group =
//       move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

//   geometry_msgs::Pose currentPose = move_group.getCurrentPose().pose;
//   ROS_ERROR(std::string(std::to_string(currentPose.position.x) + "-" + std::to_string(currentPose.position.y) + "-" + std::to_string(currentPose.position.z)).c_str());


//   geometry_msgs::Pose target_pose1;

//   std::vector<geometry_msgs::Pose> waypoints;
  

//   geometry_msgs::Pose newPose;
//   geometry_msgs::Pose currentPose2 = move_group.getCurrentPose().pose;
//   ROS_ERROR(std::string(std::to_string(currentPose2.position.x) + "-" + std::to_string(currentPose2.position.y) + "-" + std::to_string(currentPose2.position.z)).c_str());

//   newPose.position.x = currentPose2.position.x + 0.10;
//   newPose.position.y = currentPose2.position.y;
//   newPose.position.z = currentPose2.position.z;
//   waypoints.push_back(newPose);
//   moveit::planning_interface::MoveGroupInterface::Plan my_plan;

//   moveit_msgs::RobotTrajectory trajectory;
//   const double jump_threshold = 0.0;
//   const double eef_step = 0.01;
//   double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
//   my_plan.trajectory_ = trajectory;
//   move_group.execute(my_plan);;
//   ros::shutdown();
//   return 0;
// }