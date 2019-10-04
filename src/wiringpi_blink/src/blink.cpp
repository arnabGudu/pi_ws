#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <iostream>

//Wiring Pi header
#include "wiringPi.h"
//Wiring PI first pin
#define LED 1
//Callback to blink the LED according to the topic value
void blink_callback(const std_msgs::Bool::ConstPtr& msg)
{
if(msg->data == 1){
digitalWrite (LED, HIGH) ;
ROS_INFO("LED ON");
}
if(msg->data == 0){
digitalWrite (LED, LOW) ;
ROS_INFO("LED OFF");
}
}
int main(int argc, char** argv)
{
ros::init(argc, argv,"blink_led");
ROS_INFO("Started RPi Blink Node");
//Setting WiringPi
wiringPiSetup ();
//Setting LED pin as output
pinMode(LED, OUTPUT);
ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("blink_led",10,blink_callback);
ros::spin();
}
