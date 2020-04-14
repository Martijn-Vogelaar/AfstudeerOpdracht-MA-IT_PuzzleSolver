#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/LiftPiece.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "ReleasePiece.hpp"
#include "Shapes.hpp"
#include <memory>

CheckCorrectlyRotated::CheckCorrectlyRotated()
{
        stopRobotPublisher = nodeHandler.advertise<abb_controller::StopRobot>("StopRobot", 1000);
}

CheckCorrectlyRotated::~CheckCorrectlyRotated() {}

void CheckCorrectlyRotated::entryAction(SubContext *context)
{
        subContext = context;
        inductiveMeasurementSubscriber = context->getNodeHandler().subscribe(INDUCTIVE_TOPIC, QUEUE_SIZE, &CheckCorrectlyRotated::measurementCallback, this);
}

void CheckCorrectlyRotated::doActivity(SubContext *context)
{
        if (nonActivateCount > 1000 && context->getParentContext()->getCurrentPuzzlePiece() != Shape::CIRCLE)
        {
                context->setState(std::make_shared<LiftPiece>());
        }
}

void CheckCorrectlyRotated::exitAction(SubContext *)
{
}

void CheckCorrectlyRotated::measurementCallback(const inductive_sensor::inductive_sensor_measurementsConstPtr &msg)
{
        ROS_ERROR("inductive message received!");
        if (std::find(std::begin(allowedSensorIDs), std::end(allowedSensorIDs), msg->id) != std::end(allowedSensorIDs))
        {
                if (msg->activated)
                {
                        ROS_WARN("inductive message received!");
                        abb_controller::StopRobot msg;
                        msg.stop = true;
                        stopRobotPublisher.publish(msg);
                        subContext->getParentContext()->setState(std::make_shared<ReleasePiece>());
                }
                else
                {
                        nonActivateCount++;
                }
        }
}
