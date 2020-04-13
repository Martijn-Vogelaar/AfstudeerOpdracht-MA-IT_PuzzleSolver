#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/LiftPiece.hpp"
#include "ReleasePiece.hpp"
#include "Shapes.hpp"
#include <iostream>
#include <memory>

CheckCorrectlyRotated::CheckCorrectlyRotated()
{
        stopRobotPublisher = nodeHandler.advertise<abb_controller::StopRobot>("StopRobot", 1000);
        currentMeasurement.insert(std::make_pair<uint8_t, bool>(0, false));
        currentMeasurement.insert(std::make_pair<uint8_t, bool>(1, false));
        currentMeasurement.insert(std::make_pair<uint8_t, bool>(3, false));
        currentMeasurement.insert(std::make_pair<uint8_t, bool>(5, false));
        currentMeasurement.insert(std::make_pair<uint8_t, bool>(9, false));
        consecutiveMeasurements.insert(std::make_pair<uint8_t, uint8_t>(0, 0));
        consecutiveMeasurements.insert(std::make_pair<uint8_t, uint8_t>(1, 0));
        consecutiveMeasurements.insert(std::make_pair<uint8_t, uint8_t>(3, 0));
        consecutiveMeasurements.insert(std::make_pair<uint8_t, uint8_t>(5, 0));
        consecutiveMeasurements.insert(std::make_pair<uint8_t, uint8_t>(9, 0));
        numberOfMeasurements.insert(std::make_pair<uint8_t, uint8_t>(0, 0));
        numberOfMeasurements.insert(std::make_pair<uint8_t, uint8_t>(1, 0));
        numberOfMeasurements.insert(std::make_pair<uint8_t, uint8_t>(3, 0));
        numberOfMeasurements.insert(std::make_pair<uint8_t, uint8_t>(5, 0));
        numberOfMeasurements.insert(std::make_pair<uint8_t, uint8_t>(9, 0));
}

CheckCorrectlyRotated::~CheckCorrectlyRotated() {}

void CheckCorrectlyRotated::entryAction(SubContext *context)
{
        inductiveMeasurementSubscriber = context->getNodeHandler().subscribe(INDUCTIVE_TOPIC, QUEUE_SIZE, &CheckCorrectlyRotated::measurementCallback, this);
}

void CheckCorrectlyRotated::doActivity(SubContext *context)
{
        Shape currentPuzzlePiece1 = context->getParentContext()->getCurrentPuzzlePiece();
        uint8_t currentPuzzlePiece = puzzlePieceToInt(currentPuzzlePiece1);

        if (currentMeasurement.at(currentPuzzlePiece) && consecutiveMeasurements.at(currentPuzzlePiece) > MIN_NR_OF_EQUAL_MEASUREMENTS)
        {
                ROS_ERROR("Correctly Rotated!");
                abb_controller::StopRobot msg;
                msg.stop = true;
                stopRobotPublisher.publish(msg);
                context->getParentContext()->setState(std::make_shared<ReleasePiece>());
        }
        else if (!currentMeasurement.at(currentPuzzlePiece) && numberOfMeasurements.at(currentPuzzlePiece) >= MIN_NR_OF_MEASUREMENTS && currentPuzzlePiece1 != Shape::CIRCLE)
        {
                ROS_ERROR("Not correctly rotated!");

                ROS_ERROR("Not where we are supposed to be");
                ROS_ERROR(std::string(std::to_string((int)Shape::CIRCLE)).c_str());
                ROS_ERROR(std::string(std::to_string((int)currentPuzzlePiece1)).c_str());

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
                }
                if (currentMeasurement[msg->id] == msg->activated)
                {
                        consecutiveMeasurements[msg->id]++;
                }
                else
                {
                        currentMeasurement[msg->id] = msg->activated;
                        consecutiveMeasurements[msg->id] = 0;
                }
                numberOfMeasurements[msg->id]++;
        }
}
