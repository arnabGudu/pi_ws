#include "pid/pid.h"

pid::pid(ros::NodeHandle _nh) : nh(_nh)
{
	pub = nh.advertise<std_msgs::Int16>("speed", 1000);
	lastError = 0;
	intg = 0;
	
	kp = 0; kd = 0; ki = 0;
}

void pid::calc(int error)
{
	int diff = error - lastError;
	intg += error;
	lastError = error;
	float balance = kp * error + kd * diff + ki * intg;
	
	motor(balance);
}

void pid::motor(float balance)
{
	std_msgs::Int16 msg;
	msg.data = balance;
	pub.publish(msg);
}
