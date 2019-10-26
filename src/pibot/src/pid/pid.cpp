#include "pid/pid.h"

pid::pid(ros::NodeHandle _nh) : nh(_nh)
{
	pub = nh.advertise<std_msgs::Int16>("speed", 1000);
	lastError = 0;
	intg = 0;
	kp = 0; kd = 0; ki = 0;
	save_flag = 0;
	config_name = ros::package::getPath("pibot") + "/config/pid.conf";
	load();
	trackbar();
}

void pid::load()
{
	ifstream config(config_name.c_str());
	config>>kp;
	config>>kd;
	config>>ki;
	config>>sp;
	config.close();
}

void pid::trackbar()
{
	namedWindow("pid");
	createTrackbar("kp", "pid", &kp, 100, NULL);
	createTrackbar("kd", "pid", &kd, 100, NULL);
	createTrackbar("ki", "pid", &ki, 100, NULL);
	createTrackbar("sp", "pid", &sp, 100, NULL);
	createTrackbar("save", "pid", &save_flag, 1, NULL);
}

void pid::save()
{
	ofstream config(config_name.c_str());
	config<<kp<<'\n';
	config<<kd<<'\n';
	config<<ki<<'\n';
	config<<sp<<'\n';
	config.close();
}

void pid::calc(int error)
{
	if (save_flag == 1)
		save();
	
	int diff = error - lastError;
	intg += error;
	lastError = error;
	float balance = (kp * error + kd * diff + ki * intg) * 0.01;
	
	motor(balance);
}

void pid::motor(float balance)
{
	std_msgs::Int16 msg;
	msg.data = balance;
	pub.publish(msg);
}
