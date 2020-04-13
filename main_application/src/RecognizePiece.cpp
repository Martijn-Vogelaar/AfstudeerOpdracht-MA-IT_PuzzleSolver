#include "RecognizePiece.hpp"
#include <iostream>
#include <memory>
#include <algorithm>
#include "UnknownPieceInPickupPoint.hpp"
#include "MoveToRecognizedPiece.hpp"
RecognizePiece::RecognizePiece() : equalMeasurementCount(0), currentMeasurement(0)
{
}

RecognizePiece::~RecognizePiece() {}

void RecognizePiece::entryAction(Context *context)
{
    capacitiveMeasurementSubscriber = context->getNodeHandler().subscribe(CAPACITIVE_TOPIC, QUEUE_SIZE, &RecognizePiece::measurementCallback, this);
}

void RecognizePiece::doActivity(Context* context)
{
    if (equalMeasurementCount >= NUMBER_OF_EQUAL_MEASUREMENTS)
    {
        if(std::find(std::begin(allowedMeasurements), std::end(allowedMeasurements), currentMeasurement) != std::end(allowedMeasurements)){
            ROS_ERROR(std::string("Found shape:" + std::to_string(currentMeasurement)).c_str());
            context->setCurrentPuzzlePiece(currentMeasurement);
            context->setState(std::make_shared<MoveToRecognizedPiece>());
        }else{
            context->setState(std::make_shared<UnknownPieceInPickupPoint>());
        }
    }
}

void RecognizePiece::exitAction(Context *)
{
}

void RecognizePiece::measurementCallback(const capacitive_sensor::capacitive_sensor_measurementsConstPtr &msg)
{
    std::cout << "message received!" << std::endl;
    if (msg->id == CAPACITIVE_SENSOR_ID)
    {
        if (currentMeasurement == msg->value)
        {
            equalMeasurementCount++;
        }
        else
        {
            equalMeasurementCount = 0;
            currentMeasurement =  msg->value;
        }
    }
}
