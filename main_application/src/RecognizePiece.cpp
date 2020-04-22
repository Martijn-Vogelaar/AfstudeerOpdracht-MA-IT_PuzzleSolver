#include "RecognizePiece.hpp"
#include "Context.hpp"
#include <algorithm>
#include "UnknownPieceInPickupPoint.hpp"
#include "MoveToRecognizedPiece.hpp"
#include "PowerOff.hpp"
#include <memory>

RecognizePiece::RecognizePiece() : equalMeasurementCount(0), currentMeasurement(0)
{
}

RecognizePiece::~RecognizePiece() {}

void RecognizePiece::entryAction(Context *context)
{
    capacitiveMeasurementSubscriber = context->getNodeHandler().subscribe(CAPACITIVE_TOPIC, QUEUE_SIZE, &RecognizePiece::measurementCallback, this);
}

void RecognizePiece::doActivity(Context *context)
{
    if (equalMeasurementCount >= NUMBER_OF_EQUAL_MEASUREMENTS)
    {
        if (std::find(std::begin(allowedMeasurements), std::end(allowedMeasurements), currentMeasurement) != std::end(allowedMeasurements))
        {
            context->setCurrentPuzzlePiece(currentMeasurement);
            if (context->getCurrentShape() != Shape::UNKNOWN)
            {
                context->setState(std::make_shared<MoveToRecognizedPiece>());
            }
            else
            {
                context->setState(std::make_shared<PowerOff>());
            }
        }
        else
        {
            context->setState(std::make_shared<UnknownPieceInPickupPoint>());
        }
    }
}

void RecognizePiece::exitAction(Context *)
{
}

void RecognizePiece::measurementCallback(const capacitive_sensor::capacitive_sensor_measurementsConstPtr &msg)
{
    if (msg->id == CAPACITIVE_SENSOR_ID)
    {
        if (currentMeasurement == msg->value)
        {
            equalMeasurementCount++;
        }
        else
        {
            equalMeasurementCount = 0;
            currentMeasurement = msg->value;
        }
    }
}
