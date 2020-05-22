#ifndef MOVE_ROBOT_CLIENT_HPP
#define MOVE_ROBOT_CLIENT_HPP

#include <actionlib/client/simple_action_client.h>
#include <abb_controller_messages/MoveEndEffectorAction.h>
#include <abb_controller_messages/MoveEndEffectorStraightAction.h>
#include <abb_controller_messages/ControlGripperAction.h>
#include <abb_controller_messages/RotateGripperAction.h>
#include <abb_controller_messages/MoveEndEffectorStraightNoRotationAction.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>


#define ACTION_NORMAL "MoveEndEffectorAction"

#define ACTION_STRAIGHT "MoveEndEffectorStraightAction"

#define ACTION_STRAIGHT_NO_ROTATION "MoveEndEffectorStraightNoRotationAction"

#define ACTION_CONTROL_GRIPPER "ControlGripperAction"

#define ACTION_ROTATE_GRIPPER "RotateGripperAction"


/**
 * @class MoveRobotClient
 * 
 * @brief MoveRobotClient is an interface to easily use actions which requests movements form the abb_controller
 * 
 * @details MoveRobotClient is an interface to easily use actions presented by the abb_controller
 *          This includes:      Moving
 *                              Moving in a straight manner
 *                              Controller the gripper
 *                              Rotating the end effector
 * 
 */
class MoveRobotClient
{
private:
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorAction> actionClientNormal;
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorStraightAction> actionClientStraight;
    actionlib::SimpleActionClient<abb_controller_messages::MoveEndEffectorStraightNoRotationAction> actionClientStraightNoRotation;
    actionlib::SimpleActionClient<abb_controller_messages::ControlGripperAction> actionClientControlGripper;
    actionlib::SimpleActionClient<abb_controller_messages::RotateGripperAction> actionClientRotateGripper;

public:
    /**
     * @brief MoveRobotStraight will move a robot with a certain id in a straight line to a given Pose.
     * 
     * @param aRobotID is the number of the robot which should be moved
     * @param aGoal contains the position(x,y,z) and orientation(x,y,z,w) where the robot should move towards
     */
    bool MoveRobotStraight(uint8_t aRobotID, geometry_msgs::Pose aGoal);


    /**
     * @brief MoveRobotStraightNoRotation will move a robot with a certain id in a straight line to a given Pose.
     *        It differs from MoveRobotStraight since no orientation has to be supplied. The current orientation 
     *        of the robot will be used to make the movement. 
     * 
     * @param aRobotID is the id of the robot which should be moved
     * @param aGoal contains the position(x,y,z)
     */
    bool MoveRobotStraightNoRotation(uint8_t aRobotID, geometry_msgs::Point aGoal);

    /**
     * @brief MoveRobotNormal will move a robot with a certain id ito a given Pose.
     *        It differs from MoveRobotStraight since the movement will not happen in a straight line.
     *        The usage of this method is prefered over the straight method if it is not necessary.
     * 
     * @param aRobotID is the id of the robot which should be moved
     * @param aGoal contains the position(x,y,z) and orientation(x,y,z,w) where the robot should move towards
     */
    bool MoveRobotNormal(uint8_t aRobotID, geometry_msgs::Pose aGoal);


    /**
     * @brief ControlGripper will open or close a gripper of a certain robot.
     * 
     * @param aRobotID is the id of the robot which should be moved 
     * @param aOpen indicates whether the gripper should be opened or closed
     * @param aPuzzleID 
     */
    bool ControlGripper(uint8_t aRobotID, bool aOpen, uint8_t aPuzzleID);

    /**
     * @brief RotateGripper will rotate the gripper with a certain angle
     * 
     * @param aRobotID is the id of the robot which should be rotated
     * @param aRotation indicates how many radians it should be rotated
     * @param aSpeedfactor factor with which the rotation will be made. 1.0 equals the maximum speed, 0.1 equals 10% of the maximum speed etc.
     * @param async
     * @param increase Define whether it should be increased or moved to the given rotation
     */
    bool RotateGripper(uint8_t aRobotID, double aRotation, double aSpeedfactor, bool async, bool increase);


    /**
     * @brief Construct a new Move Robot Client object
     * 
     */
    MoveRobotClient();

    /**
     * @brief Destroy the Move Robot Client object
     * 
     */
    ~MoveRobotClient();
};

#endif //MOVE_ROBOT_CLIENT_HPP