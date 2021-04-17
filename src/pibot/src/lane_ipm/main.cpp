#include "lane_ipm/lane_ipm.h"
#include "pid/pid.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "pibot");
	ros::NodeHandle nh;
	ros::Rate rate(10);
	
	ipm i(argc, argv);
	pid p(nh);
	
	while(ros::ok())
	{
		p.calc(i.process());
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}	
