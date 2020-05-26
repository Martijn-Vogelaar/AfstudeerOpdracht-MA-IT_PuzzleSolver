#include "gtest/gtest.h"
#include "Shapes.hpp"

TEST(Shape, measurementToPiece)
{
    EXPECT_EQ(puzzlePieceMeasurementToEnum(1), Shape::CIRCLE);
    EXPECT_EQ(puzzlePieceMeasurementToEnum(5), Shape::SQUARE);
    EXPECT_EQ(puzzlePieceMeasurementToEnum(9), Shape::RECTANGLE_1);
    EXPECT_EQ(puzzlePieceMeasurementToEnum(3), Shape::RECTANGLE_2);
    EXPECT_EQ(puzzlePieceMeasurementToEnum(2), Shape::UNKNOWN);
}

TEST(Shape, pieceToMeasurement)
{
    EXPECT_EQ(puzzlePieceToInt(Shape::CIRCLE), 1);
    EXPECT_EQ(puzzlePieceToInt(Shape::SQUARE), 5);
    EXPECT_EQ(puzzlePieceToInt(Shape::RECTANGLE_1), 9);
    EXPECT_EQ(puzzlePieceToInt(Shape::RECTANGLE_2), 3);
    EXPECT_EQ(puzzlePieceToInt(Shape::UNKNOWN), 0);
}