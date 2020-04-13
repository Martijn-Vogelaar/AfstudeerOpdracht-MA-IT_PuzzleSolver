#include "Shapes.hpp"
#include "ros/ros.h"
Shape puzzlePieceMeasurementToEnum(uint8_t measurement)
{
    switch (measurement)
    {
    case CIRCLE:
        return Shape::CIRCLE;
    case SQUARE:
        return Shape::SQUARE;
    case RECTANGLE_1:
        return Shape::RECTANGLE_1;
    case RECTANGLE_2:
        return Shape::RECTANGLE_2;
    default:
        return Shape::UNKNOWN;
    }
    return Shape::UNKNOWN;
}

uint8_t puzzlePieceToInt(Shape puzzlePiece)
{
    switch (puzzlePiece)
    {
    case Shape::CIRCLE:
        return CIRCLE;
    case Shape::SQUARE:
        return SQUARE;
    case Shape::RECTANGLE_1:
        return RECTANGLE_1;
    case Shape::RECTANGLE_2:
        return RECTANGLE_2;
    default:
        return UNKNOWN;
    }
    return UNKNOWN;
}
