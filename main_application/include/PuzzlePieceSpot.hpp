#ifndef PUZZLE_PIECE_SPOT_HPP
#define PUZZLE_PIECE_SPOT_HPP

#include "Shapes.hpp"
#include <geometry_msgs/Pose.h>

const double prepareDistance = 0.04; //cm

const double scaleCorrection = 1.08910891089; //Original = 1.1 new is 1.01

class PuzzlePieceSpot
{
public:
    PuzzlePieceSpot();
    /**
     * @brief Construct a new PuzzlePieceSpot object
     *
     */
    PuzzlePieceSpot(Shape aShape, geometry_msgs::Pose aPuzzlePieceSpotPose, uint8_t aId);

    /**
     * @brief Destroy the PuzzlePieceSpot object
     *
     */
    ~PuzzlePieceSpot();

    geometry_msgs::Pose getPuzzlePiecePreparePlace();
    geometry_msgs::Pose getPuzzlePiecePlace();
    Shape getShape();
    bool isFilled();
    void setFilled(bool aFilled);
    uint8_t getID();

private:
    Shape shape;
    geometry_msgs::Pose puzzlePieceSpotPose;
    uint8_t id;
    bool filled;
};
#endif // PUZZLE_PIECE_SPOT_HPP