#include "lane_hl/lane_hl.h"
#include "pid/pid.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "pibot");
	ros::NodeHandle nh;
	ros::Rate rate(10);
	
	lane l(argc, argv);
	pid p(nh);
	
	while(ros::ok())
	{
		p.calc(l.process());
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}	
