#include "InductiveSensor.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"
#include <gazebo/gazebo_client.hh>
InductiveSensor::InductiveSensor(uint8_t aId) : id(aId)
{
    p = n.advertise<inductive_sensor::inductive_sensor_measurements>("inductive_sensor", 1000);
}

InductiveSensor::~InductiveSensor()
{
}

void InductiveSensor::runMeasurements(int argc, char **argv)
{
    gazebo::client::setup(argc, argv);
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    gazebo::transport::SubscriberPtr sub;

    ros::Rate loop_rate(10);
    node->Init();
    sub = node->Subscribe(std::string(IMAGE_TOPIC_1 + std::to_string(id) + IMAGE_TOPIC_2), &InductiveSensor::cameraCallback, this);
    std::cout << std::string(IMAGE_TOPIC_1 + std::to_string(id) + IMAGE_TOPIC_2) << std::endl;
    // loop
    while (ros::ok())
    {

        gazebo::common::Time::MSleep(10);
        ros::spinOnce();
        loop_rate.sleep();
    }
    // clean up
    gazebo::client::shutdown();
}

bool InductiveSensor::isActivated(cv::Mat image)
{
    cv::Mat test, combinedRed, lowRed, highRed;
    cv::inRange(image, cv::Scalar(0, 50, 50), cv::Scalar(10, 255, 255), lowRed);
    cv::inRange(image, cv::Scalar(170, 50, 50), cv::Scalar(180, 255, 255), highRed);
    combinedRed = lowRed + highRed;
    return cv::countNonZero(combinedRed) == 0;
}

void InductiveSensor::cameraCallback(ConstImageStampedPtr &msg)
{
    int width = (int)msg->image().width();
    int height = (int)msg->image().height();
    char *data;

    data = new char[msg->image().data().length() + 1];

    memcpy(data, msg->image().data().c_str(), msg->image().data().length());
    cv::Mat image(height, width, CV_8UC3, data);

    bool activated = isActivated(image);
    inductive_sensor::inductive_sensor_measurements message;
    message.id = 0;
    message.activated = activated;
    p.publish(message);
    delete data;
}