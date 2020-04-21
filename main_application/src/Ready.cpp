#include "Ready.hpp"
#include "Context.hpp"
#include "PutPieceInPickupPoint.hpp"
#include "ModelSpawner.hpp"
#include "PowerOff.hpp"
#include "Poses.hpp"
#include <thread>
#include <memory>

uint8_t Ready::visitCount = 0;
Ready::Ready()
{
}

Ready::~Ready() {}

void Ready::entryAction(Context *context)
{
    context->getMoveRobotClient().MoveRobotNormal(0, ROBOT_HOME_POSE);
    ModelSpawner modelSpawner;

    if (visitCount == 0)
    {
        modelSpawner.spawnPuzzlePiece(Shape::RECTANGLE_1);
    }
    else if (visitCount == 1)
    {
        modelSpawner.spawnPuzzlePiece(Shape::CIRCLE);
    }
    else if (visitCount == 2)
    {
        modelSpawner.spawnPuzzlePiece(Shape::CIRCLE);
    }
    else if (visitCount == 3)
    {
        modelSpawner.spawnPuzzlePiece(Shape::SQUARE);
    }
}

void Ready::doActivity(Context *context)
{
    if (visitCount > 3)
    {
        context->setState(std::make_shared<PowerOff>());
    }
    else
    {
        context->setState(std::make_shared<PutPieceInPickupPoint>());
    }
}

void Ready::exitAction(Context *)
{
    visitCount++;
}
