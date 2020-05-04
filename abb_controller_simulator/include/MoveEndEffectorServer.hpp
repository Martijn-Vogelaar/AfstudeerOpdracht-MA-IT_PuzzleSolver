#ifndef MOVE_END_EFFECTOR_SERVER_HPP
#define MOVE_END_EFFECTOR_SERVER_HPP


#include <actionlib/server/simple_action_server.h>
#include <abb_simulator_controller/MoveEndEffectorAction.h>

#include <moveit/move_group_interface/move_group_interface.h>

#define PLANNING_GROUP "manipulator"


/**
 * @class MoveEndEffectorServer
 * 
 * @brief The class MoveEndEffectorServer is a class which can be used to catch action requests from the MoveEndEffector action.
 *        The class handles the incoming requests and provides feedback during the handling of the requests. Eventually
 *        a result will be presented to the node which send the request.
 * 
 */ 
class MoveEndEffectorServer
{
protected:
    moveit::planning_interface::MoveGroupInterface move_group;
    ros::NodeHandle nodeHandler;
    actionlib::SimpleActionServer<abb_simulator_controller::MoveEndEffectorAction> actionServer;
    std::string actionName;
    abb_simulator_controller::MoveEndEffectorFeedback actionFeedback;
    abb_simulator_controller::MoveEndEffectorResult actionResult;
    bool executeMovement(geometry_msgs::Pose goalPose);

public:
    /**
     * @brief Construct a new Move End Effector Server object
     * 
     * @param name Name which will be used to present this node to ROS
     */
    MoveEndEffectorServer(std::string name);

    /**
     * @brief Destroy the Move End Effector Server object
     * 
     */
    ~MoveEndEffectorServer();


    /**
     * @brief Callback function which is called when any node uses the MoveEndEffector action.
     * 
     * @param goal Message with the request of the action.
     */
    void goalCallback(const abb_simulator_controller::MoveEndEffectorGoalConstPtr &goal);
};

#endif //MOVE_END_EFFECTOR_SERVER_HPP