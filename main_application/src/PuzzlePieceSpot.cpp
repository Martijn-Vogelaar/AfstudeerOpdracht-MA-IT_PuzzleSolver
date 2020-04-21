#include "PuzzlePieceSpot.hpp"

PuzzlePieceSpot::PuzzlePieceSpot() : shape(Shape::UNKNOWN), id(0), filled(false) {

}

PuzzlePieceSpot::PuzzlePieceSpot(Shape aShape, geometry_msgs::Pose aPuzzlePieceSpotPose, uint8_t aId) : shape(aShape), puzzlePieceSpotPose(aPuzzlePieceSpotPose), id(aId), filled(false)
{
    puzzlePieceSpotPose.position.x = puzzlePieceSpotPose.position.x / scaleCorrection;
    puzzlePieceSpotPose.position.y = puzzlePieceSpotPose.position.y / scaleCorrection;
}

PuzzlePieceSpot::~PuzzlePieceSpot()
{
}

geometry_msgs::Pose PuzzlePieceSpot::getPuzzlePiecePreparePlace()
{
    geometry_msgs::Pose placePoint = puzzlePieceSpotPose;
    placePoint.position.z = placePoint.position.z + prepareDistance;
    return placePoint;
}
geometry_msgs::Pose PuzzlePieceSpot::getPuzzlePiecePlace()
{
    return puzzlePieceSpotPose;
}

Shape PuzzlePieceSpot::getShape()
{
    return shape;
}

bool PuzzlePieceSpot::isFilled()
{
    return filled;
}

void PuzzlePieceSpot::setFilled(bool aFilled)
{
    filled = aFilled;
}
uint8_t PuzzlePieceSpot::getID()
{
    return id;
}