#include "cam.h"

cam::cam(int argc, char** argv, ros::NodeHandle _nh) : it(_nh), nh(_nh)
{
	for (int i = 0; i < argc; i++)
		cout<<"i: "<<i<<"\t"<<argv[i]<<endl;
		
	if (argv[1] != NULL)	
		sub = it.subscribe(argv[1], 1, &cam::callback, this);
	else
		video();
}

void cam::callback(const sensor_msgs::ImageConstPtr& _msg)
{
	src = cv_bridge::toCvShare(_msg, "bgr8")->image;
	perform();
	waitKey(10);
}

void cam::video()
{
	VideoCapture cap(0);
	while(cap.isOpened())
	{
		cap >> src;
		if (src.empty())
			break;
		
		perform();
		if (waitKey(10) == ' ')
			break;
	}
}

void cam::perform()
{
	resize(src, src, Size(), .25, .25, CV_INTER_AREA);
	cvtColor(src, src, CV_BGR2GRAY);
	show();
}

void cam::show()
{
	imshow("src", src);
}
