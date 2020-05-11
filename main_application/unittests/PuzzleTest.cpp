#include "gtest/gtest.h"
#include "Puzzle.hpp"
#include "PuzzlePieceSpot.hpp"
#include "Shapes.hpp"
#include "Poses.hpp"
#include <geometry_msgs/Pose.h>

Puzzle testPuzzle;
Puzzle &initPuzzle()
{
    testPuzzle = Puzzle();
    initializePoses();
    testPuzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::RECTANGLE_1, Rectangle1Poses.placePose, 1));
    testPuzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::RECTANGLE_2, Rectangle2Poses.placePose, 1));
    testPuzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::CIRCLE, Circle1Poses.placePose, 2));
    testPuzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::CIRCLE, Circle2Poses.placePose, 3));
    testPuzzle.addPuzzlePieceSpot(PuzzlePieceSpot(Shape::SQUARE, SquarePoses.placePose, 4));
    return testPuzzle;
}

TEST(Puzzle, getEmptyRectangle)
{
    Puzzle testPuzzle = initPuzzle();
    PuzzlePieceSpot *emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::RECTANGLE_1);
    EXPECT_EQ(emptySpot->getID(), 1);
    EXPECT_EQ(emptySpot->getShape(), Shape::RECTANGLE_1);
}

TEST(Puzzle, getPiecePlaces)
{
    Puzzle testPuzzle = initPuzzle();
    PuzzlePieceSpot *emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::SQUARE);
    geometry_msgs::Pose placePose = emptySpot->getPuzzlePiecePlace();
    geometry_msgs::Pose preparePlacePose = placePose;
    preparePlacePose.position.z = preparePlacePose.position.z + 0.04; // Prepare place distance
    EXPECT_EQ(emptySpot->getPuzzlePiecePreparePlace(), preparePlacePose);
}

TEST(Puzzle, noEmptySpot)
{
    Puzzle testPuzzle;
    PuzzlePieceSpot *emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::RECTANGLE_1);
    EXPECT_TRUE(emptySpot == NULL);
}

TEST(Puzzle, testSpotFilled)
{
    Puzzle testPuzzle = initPuzzle();
    testPuzzle.setSpotFilled(1);
    PuzzlePieceSpot *emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::RECTANGLE_1);
    EXPECT_TRUE(emptySpot == NULL);
}

TEST(Puzzle, testTwoSpotsFilled)
{
    Puzzle testPuzzle = initPuzzle();
    PuzzlePieceSpot *emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    EXPECT_EQ(emptySpot->getID(), 2);
    EXPECT_EQ(emptySpot->getShape(), Shape::CIRCLE);
    testPuzzle.setSpotFilled(2);
    emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    EXPECT_EQ(emptySpot->getID(), 3);
    EXPECT_EQ(emptySpot->getShape(), Shape::CIRCLE);
    testPuzzle.setSpotFilled(3);
    emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    EXPECT_TRUE(emptySpot == NULL);
}

TEST(Puzzle, testSpotExplored)
{
    Puzzle testPuzzle = initPuzzle();
    PuzzlePieceSpot *emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    EXPECT_EQ(emptySpot->getID(), 2);
    EXPECT_EQ(emptySpot->getShape(), Shape::CIRCLE);
    testPuzzle.setSpotExplored(2);
    emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    EXPECT_EQ(emptySpot->getID(), 3);
    EXPECT_EQ(emptySpot->getShape(), Shape::CIRCLE);
}

TEST(Puzzle, testExploredAndPlacedInSecondSpot)
{
    Puzzle testPuzzle = initPuzzle();
    PuzzlePieceSpot *emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    testPuzzle.setSpotExplored(2);
    emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    testPuzzle.setSpotFilled(3);
    emptySpot = testPuzzle.getEmptyPuzzleSpot(Shape::CIRCLE);
    EXPECT_EQ(emptySpot->getID(), 2);
    EXPECT_EQ(emptySpot->getShape(), Shape::CIRCLE);
}

TEST(Puzzle, puzzleIsFinished){
    Puzzle testPuzzle = initPuzzle();
    testPuzzle.setSpotFilled(1);
    testPuzzle.setSpotFilled(2);
    testPuzzle.setSpotFilled(3);
    testPuzzle.setSpotFilled(4);
    EXPECT_TRUE(testPuzzle.puzzleFinished());
}

TEST(Puzzle, puzzleIsUnfinished){
    Puzzle testPuzzle = initPuzzle();
    testPuzzle.setSpotFilled(1);
    testPuzzle.setSpotFilled(3);
    testPuzzle.setSpotFilled(4);
    EXPECT_FALSE(testPuzzle.puzzleFinished());
}