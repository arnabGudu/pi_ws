#ifndef PID
#define PID

#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "fstream"
#include "ros/package.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class pid
{
public:
	pid(ros::NodeHandle _nh);
	void calc(int error);
	void save(int , void *);

private:
	ros::NodeHandle nh;
	ros::Publisher pub;

	int lastError;
	int intg;
	int kp, kd, ki, sp;
	int save_flag;
	
	string config_name;

	void load();
	void trackbar();
	void motor(float balance);
};

#endif
