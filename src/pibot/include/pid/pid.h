#ifndef PID
#define PID

#include "ros/ros.h"
#include "std_msgs/Int16.h"

using namespace std;

class pid
{
public:
	pid(ros::NodeHandle _nh);
	void calc(int error);

private:
	ros::NodeHandle nh;
	ros::Publisher pub;

	int lastError;
	int intg;
	float kp, kd, ki;

	void motor(float balance);
};

#endif
