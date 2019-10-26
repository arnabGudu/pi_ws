#include "cam.h"

cam::cam(int argc, char** argv, ros::NodeHandle _nh) : it(_nh), nh(_nh)
{
	if (argc == 1)
	{
		cout<<"openening video feed from cam 0"<<endl;
		cap.open(1);
		video();
	}
	else
	{
		for (int i = 1; i <= argc; i++)
		{
			if (argv[i][0] == '~')
			{
				cout<<"openening video from file"<<endl;
				cap.open(argv[i]);
			}
			else if (argv[i][0] == '/')
			{
				if (argv[i][1] == 'h' && argv[i][2] == 'o' && argv[i][3] == 'm' && argv[i][4] == 'e')
				{
					cout<<"openening video from file"<<endl;
					cap.open(argv[i]);
					video();
				}	
				else
				{
					cout<<"openening video from node"<<endl;
					sub = it.subscribe(argv[1], 1, &cam::callback, this);
				}
			}
			else
			{	
				cout<<"openening video feed from cam 0"<<endl;
				cap.open(1);
				video();
			}
		}	
	}
}

cam::~cam()
{
	cap.release();
}

void cam::callback(const sensor_msgs::ImageConstPtr& _msg)
{
	src = cv_bridge::toCvShare(_msg, "bgr8")->image;
}

void cam::video()
{
	while(cap.isOpened())
	{
		cap >> src;
		if (src.empty())
			break;
		
		perform();
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
	if (waitKey(10) == ' ')
		cap.release();
}
