#ifndef SHAPES_HPP
#define SHAPES_HPP
#include <stdint.h>


enum class Shape
{
    CIRCLE,
    SQUARE,
    RECTANGLE_1,
    RECTANGLE_2,
    UNKNOWN
};
const uint8_t UNKNOWN = 0;
const uint8_t CIRCLE = 1;
const uint8_t SQUARE = 5;
const uint8_t RECTANGLE_1 = 9;
const uint8_t RECTANGLE_2 = 3;

extern Shape puzzlePieceMeasurementToEnum(uint8_t measurement);
extern uint8_t puzzlePieceToInt(Shape puzzlePiece);

#endif //SHAPES_HPP