#include "CheckCorrectlyRotated.hpp"
#include "RotatePieceOnPlace.hpp"
#include "LiftPiece.hpp"
#include "SubContext.hpp"
#include "RemovePieceFromPuzzle.hpp"
#include "ReleasePiece.hpp"
#include "Shapes.hpp"
#include <memory>

CheckCorrectlyRotated::CheckCorrectlyRotated() : nonActivateCount(0)
{
        stopRobotPublisher = nodeHandler.advertise<abb_controller_messages::StopRobot>("StopRobot", 1000);
}

CheckCorrectlyRotated::~CheckCorrectlyRotated() {}

void CheckCorrectlyRotated::entryAction(SubContext *context)
{
        subContext = context;
        inductiveMeasurementSubscriber = context->getNodeHandler().subscribe(INDUCTIVE_TOPIC, QUEUE_SIZE, &CheckCorrectlyRotated::measurementCallback, this);
}

void CheckCorrectlyRotated::doActivity(SubContext *context)
{
        // if (nonActivateCount > NR_OF_MEASUREMENTS && context->getCurrentPuzzlePieceSpot().getShape() != Shape::CIRCLE)
        // {
        //         context->setState(std::make_shared<LiftPiece>());
        // }
        // else if (nonActivateCount > NR_OF_MEASUREMENTS_TIMEOUT)
        // {
        //         static uint8_t circleRotateCount = 1;
        //         if (circleRotateCount < 2)
        //         {
        //                 circleRotateCount++;
        //                 context->setState(std::make_shared<RotatePieceOnPlace>());
        //         }
        //         else
        //         {
        //                 circleRotateCount = 0;
        //                 context->getParentContext()->setState(std::make_shared<RemovePieceFromPuzzle>());
        //         }
        // }
}

void CheckCorrectlyRotated::exitAction(SubContext *)
{
}

void CheckCorrectlyRotated::measurementCallback(const inductive_sensor::inductive_sensor_measurementsConstPtr &msg)
{
        if (std::find(std::begin(allowedSensorIDs), std::end(allowedSensorIDs), msg->id) != std::end(allowedSensorIDs))
        {
                subContext->getParentContext()->getPuzzle().setSpotFilled(subContext->getCurrentPuzzlePieceSpot().getID());
                subContext->getParentContext()->getPuzzle().resetExplored();
                subContext->getParentContext()->setState(std::make_shared<ReleasePiece>());
                // if (msg->activated && msg->id == subContext->getParentContext()->getCurrentPuzzlePieceSpot().getID())
                // {
                //         abb_controller_messages::StopRobot msg;
                //         msg.stop = true;
                //         stopRobotPublisher.publish(msg);
                //         subContext->getParentContext()->getPuzzle().setSpotFilled(subContext->getCurrentPuzzlePieceSpot().getID());
                //         subContext->getParentContext()->getPuzzle().resetExplored();
                //         subContext->getParentContext()->setState(std::make_shared<ReleasePiece>());
                // }
                // else
                // {
                //         nonActivateCount++;
                // }
        }
}
