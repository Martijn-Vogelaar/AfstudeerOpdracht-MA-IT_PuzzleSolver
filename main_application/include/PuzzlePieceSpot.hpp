#ifndef PUZZLE_PIECE_SPOT_HPP
#define PUZZLE_PIECE_SPOT_HPP

#include "Shapes.hpp"
#include <geometry_msgs/Pose.h>

const double prepareDistance = 0.04; //cm

const double scaleCorrection = 1; //Original = 1.1 new is 1.01

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

    /**
     * @brief Get the pose where the puzzlepiece should be moved before it is being placed.
     * 
     * @return geometry_msgs::Pose 
     */
    geometry_msgs::Pose getPuzzlePiecePreparePlace();

    /**
     * @brief Get the pose where the puzzlepiece should be placed.
     * 
     * @return geometry_msgs::Pose 
     */
    geometry_msgs::Pose getPuzzlePiecePlace();

    /**
     * @brief Get the Shape of the puzzlepiecespot.
     * 
     * @return Shape 
     */
    Shape getShape();

    /**
     * @brief returns whether the spot is filled or not
     * 
     * @return true Spot is filled
     * @return false Spot is not filled
     */
    bool isFilled();
    
    /**
     * @brief Set the whether the spot is filled or not.
     * 
     * @param aFilled 
     */
    void setFilled(bool aFilled);

    /**
     * @brief Returns whether the spot is already explored previously.
     * 
     * @return true 
     * @return false 
     */
    bool isExplored();

    /**
     * @brief Set whether the spot is explored or not.
     * 
     * @param aExplored 
     */
    void setExplored(bool aExplored);

    /**
     * @brief Get the ID of the spot.
     * 
     * @return uint8_t 
     */
    uint8_t getID();

private:
    Shape shape;
    geometry_msgs::Pose puzzlePieceSpotPose;
    uint8_t id;
    bool filled;
    bool explored;
};
#endif // PUZZLE_PIECE_SPOT_HPP