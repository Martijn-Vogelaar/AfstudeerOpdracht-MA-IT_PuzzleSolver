#ifndef RECOGNIZE_PIECE_HPP
#define RECOGNIZE_PIECE_HPP

// Local
#include "State.hpp"
class Context;
#include "ros/ros.h"
#include "capacitive_sensor/capacitive_sensor_measurements.h"

#define CAPACITIVE_TOPIC "capacitive_sensor"

#define capacitive_sensor_ID 0

/**
 * @brief Atleast 5 measurements in a row need to be equal to have a "Good" measurement 
 * 
 */
#define NUMBER_OF_EQUAL_MEASUREMENTS 5

static const int allowedMeasurements[] = {1,3,5,9};


/**
   * @class RecognizePiece
   *
   * @brief RecognizePiece is the class which represents the RecognizePiece state.
   *
   * @details   In the RecognizePiece state the system will attempt to recognize the PuzzlePiece
   *            which is currently in the pickuppoint.
   *            If a piece is successfully recognized a transition will be made to MoveToRecognizedPiece.
   *            if the piece cannot be recognized a transition will be made to UnknownPieceInPickupPoint.
   *
   */
class RecognizePiece : public State
{
public:
    /**
     * @brief Construct a new RecognizePiece object
     *
     */
    RecognizePiece();
    /**
     * @brief Destroy the RecognizePiece object
     *
     */
    ~RecognizePiece();
    /**
     * @brief entryAction is being called when the RecognizePiece state is being entered.
     *
     * @details When the RecognizePiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * RecognizePiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the RecognizePiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;

private:
    ros::Subscriber capacitiveMeasurementSubscriber;

    uint8_t equalMeasurementCount;

    uint8_t currentMeasurement;

    void measurementCallback(const capacitive_sensor::capacitive_sensor_measurementsConstPtr& msg);
};
#endif // RECOGNIZE_PIECE_HPP