#include "cam/cam.h"
#include "pid/pid.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "pibot");
	ros::NodeHandle nh;
	ros::Rate rate(10);
	cam c;
	pid p(nh);
	
	while(ros::ok())
	{
		p.calc(c.process());
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}	
