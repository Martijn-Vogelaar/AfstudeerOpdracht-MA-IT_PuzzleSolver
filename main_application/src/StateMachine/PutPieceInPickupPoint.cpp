#include "PutPieceInPickupPoint.hpp"
#include "Context.hpp"
#include "RecognizePiece.hpp"
#include <memory>

PutPieceInPickupPoint::PutPieceInPickupPoint()
{
}

PutPieceInPickupPoint::~PutPieceInPickupPoint() {}

void PutPieceInPickupPoint::entryAction(Context *context)
{
    controlSliderPublisher = context->getNodeHandler().advertise<slider_controller::control_slider>("control_slider", 1000);
    ros::Duration(1).sleep(); //Sleep is needed since the connection between the publisher and subscriber is otherwise not
                              //made before sending the first request;
}

void PutPieceInPickupPoint::doActivity(Context *context)
{

    slider_controller::control_slider request;
    request.id = 0;
    request.open = true;
    controlSliderPublisher.publish(request);
    ros::Duration(1.5).sleep();
    slider_controller::control_slider request2;
    request2.id = 0;
    request2.open = false;
    controlSliderPublisher.publish(request2);
    ros::Duration(1).sleep();

    context->setState(std::make_shared<RecognizePiece>());
}

void PutPieceInPickupPoint::exitAction(Context *context)
{
}
