#include "InductiveSensor.hpp"
#include "inductive_sensor/inductive_sensor_measurements.h"
#include <gazebo/gazebo_client.hh>

#define DEBUG false

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

    ros::Rate loop_rate(2);
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
    cv::cvtColor(image, test, cv::COLOR_RGB2BGR);
    cv::cvtColor(image, image, cv::COLOR_RGB2HSV);
    cv::inRange(image, cv::Scalar(0, 50, 20), cv::Scalar(5, 255, 255), lowRed);
    cv::inRange(image, cv::Scalar(175, 50, 20), cv::Scalar(180, 255, 255), highRed);
    cv::bitwise_or(lowRed, highRed, combinedRed);

    if (DEBUG)
    {
        // cv::cvtColor(image, test, cv::COLOR_RGB2BGR);
        cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE); // Create a window for display.
        cv::imshow("Display window", test);
        cv::namedWindow("Display window1", cv::WINDOW_AUTOSIZE); // Create a window for display.
        cv::imshow("Display window1", lowRed);
        cv::namedWindow("Display window2", cv::WINDOW_AUTOSIZE); // Create a window for display.
        cv::imshow("Display window2", highRed);
        cv::namedWindow("Display window3", cv::WINDOW_AUTOSIZE); // Create a window for display.
        cv::imshow("Display window3", combinedRed);
        cv::waitKey(1); // Wait for a keystroke in the window
    }
    return cv::countNonZero(combinedRed) == combinedRed.rows * combinedRed.cols;
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
    message.id = id;
    message.activated = activated;
    p.publish(message);
    delete data;
}