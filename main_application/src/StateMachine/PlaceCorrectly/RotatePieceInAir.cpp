#include "RotatePieceInAir.hpp"
#include "PlacePieceInPuzzle.hpp"
#include "SubContext.hpp"
#include "Shapes.hpp"
#include <math.h>

int8_t RotatePieceInAir::unableToRotateFurther = 1;

RotatePieceInAir::RotatePieceInAir()
{
}

RotatePieceInAir::~RotatePieceInAir() {}

void RotatePieceInAir::entryAction(SubContext *)
{
}

void RotatePieceInAir::doActivity(SubContext *context)
{
    bool movementMade = true;
    if (context->getCurrentPuzzlePieceSpot().getShape() == Shape::SQUARE)
    {
        if (!context->getMoveRobotClient().RotateGripper(0, unableToRotateFurther * M_PI / 2, 1.0, false, true))
        {
            unableToRotateFurther = (uint8_t)-unableToRotateFurther;
            movementMade = false;
        }
    }
    else
    {
        if (!context->getMoveRobotClient().RotateGripper(0, unableToRotateFurther * M_PI, 1.0, false, true))
        {
            unableToRotateFurther = (uint8_t)-unableToRotateFurther;
            movementMade = false;
        }
    }
    if (movementMade)
    {
        context->setState(std::make_shared<PlacePieceInPuzzle>());
    }
}

void RotatePieceInAir::exitAction(SubContext *)
{
}
