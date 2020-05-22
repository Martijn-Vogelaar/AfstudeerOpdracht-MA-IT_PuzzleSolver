#include "Ready.hpp"
#include "Context.hpp"
#include "PutPieceInPickupPoint.hpp"
#include "ModelSpawner.hpp"
#include "PowerOff.hpp"
#include "Poses.hpp"
#include <thread>
#include <memory>
#include "TF2Handler.hpp"
#include "Shapes.hpp"
#include "RecognizePiece.hpp"
uint8_t Ready::visitCount = 0;
Ready::Ready()
{
}

Ready::~Ready() {}

void Ready::entryAction(Context *context)
{
    context->getMoveRobotClient().ControlGripper(0,false,0);
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    // context->setCurrentPuzzlePiece(1);
    // context->findEmptyUnexploredPuzzleSpot();
    // TF2Handler tf2Handler;
    // geometry_msgs::Pose goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    // geometry_msgs::Pose placePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    // ROS_ERROR(std::string(std::to_string(placePiece.position.x) + "\t" +std::to_string(placePiece.position.y) + "\t" +std::to_string(placePiece.position.z)).c_str());
    // context->getMoveRobotClient().MoveRobotNormal(0, placePiece);

    // goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    // goal.position.z = goal.position.z-0.023;
    // placePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    // ROS_ERROR(std::string(std::to_string(placePiece.position.x) + "\t" +std::to_string(placePiece.position.y) + "\t" +std::to_string(placePiece.position.z)).c_str());
    // context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiece.position);

    // goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    // placePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    // ROS_ERROR(std::string(std::to_string(placePiece.position.x) + "\t" +std::to_string(placePiece.position.y) + "\t" +std::to_string(placePiece.position.z)).c_str());
    // context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiece.position);
    // goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePlace();
    // placePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal); 
    // ROS_ERROR(std::string(std::to_string(placePiece.position.x) + "\t" +std::to_string(placePiece.position.y) + "\t" +std::to_string(placePiece.position.z)).c_str());
    // context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiece.position);
    // ModelSpawner modelSpawner;

    // goal = context->getCurrentPuzzlePieceSpot().getPuzzlePiecePreparePlace();
    // placePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    // ROS_ERROR(std::string(std::to_string(placePiece.position.x) + "\t" +std::to_string(placePiece.position.y) + "\t" +std::to_string(placePiece.position.z)).c_str());
    // context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiece.position);


    // if (visitCount == 0)
    // {
    //     modelSpawner.spawnPuzzlePiece(Shape::CIRCLE);
    // }
    // else if (visitCount == 1)
    // {
    //     modelSpawner.spawnPuzzlePiece(Shape::CIRCLE);
    // }
    // else if (visitCount == 2)
    // {
    //     modelSpawner.spawnPuzzlePiece(Shape::RECTANGLE_1);
    // }
    // else if (visitCount == 3)
    // {
    //     modelSpawner.spawnPuzzlePiece(Shape::SQUARE);
    // }
}

void Ready::doActivity(Context *context)
{
       context->setState(std::make_shared<RecognizePiece>());
    // if (visitCount > 3)
    // {
    //     context->setState(std::make_shared<PowerOff>());
    // }
    // else
    // {
    //     context->setState(std::make_shared<PutPieceInPickupPoint>());
    // }
}

void Ready::exitAction(Context *)
{
    visitCount++;
}
