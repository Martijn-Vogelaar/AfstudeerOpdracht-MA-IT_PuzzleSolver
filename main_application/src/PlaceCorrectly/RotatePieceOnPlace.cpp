#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include <memory>
#include <math.h>

int8_t RotatePieceOnPlace::unableToRotateFurther = 1;

RotatePieceOnPlace::RotatePieceOnPlace()
{
}

RotatePieceOnPlace::~RotatePieceOnPlace() {}

void RotatePieceOnPlace::entryAction(SubContext *context)
{
    if (!context->getMoveRobotClient().RotateGripper(0, unableToRotateFurther * M_PI / 1, true))
    {
        unableToRotateFurther = -unableToRotateFurther;
        context->setState(std::make_shared<RotatePieceOnPlace>());
    }
}

void RotatePieceOnPlace::doActivity(SubContext *context)
{
    context->setState(std::make_shared<CheckCorrectlyRotated>());
}

void RotatePieceOnPlace::exitAction(SubContext *)
{
}
