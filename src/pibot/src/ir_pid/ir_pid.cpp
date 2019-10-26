#include "ir_pid.h"

ir::ir(ros::NodeHandle _nh) : it(_nh), nh(_nh)
{
	//kp = 20; kd = 186; vel = 264;
	kp = 20, ki = 0, kd = 80, vel = 50;
	index = 0;

	pub = nh.advertise<std_msgs::Int16>("speed", 1000);
	trackbar();
}

void ir::show()
{
	imshow("src", src);
	//imshow("blr", blr);
	//imshow("hsv", hsv);
	//imshow("thres", thres);
	//imshow("canny", canny);
	if (waitKey(10) == ' ')
		cap.release();
}

void ir::trackbar()
{
	namedWindow("thres");
	createTrackbar("h", "thres", &h, 255, NULL);
	createTrackbar("s", "thres", &s, 255, NULL);
	createTrackbar("v", "thres", &v, 255, NULL);
	createTrackbar("H", "thres", &H, 255, NULL);
	createTrackbar("S", "thres", &S, 255, NULL);
	createTrackbar("V", "thres", &V, 255, NULL);
}

void ir::tuning()
{
	gazebo_ipbot::tuning msg;
	msg.lkp.data = lkp;
	msg.lkd.data = lkd;
	msg.lki.data = lki;
	msg.vel.data = vel;
	pubTuning.publish(msg);
}

void ir::pidTrackbar()
{
	namedWindow("src");
	createTrackbar("vel", "src", &vel, 1000, NULL);
	createTrackbar("kp", "src", &lkp, 5000, NULL);
	createTrackbar("kd", "src", &lkd, 1000, NULL);
	createTrackbar("ki", "src", &lki, 1000, NULL);
}

void ir::perform()
{
	blur(src, blr, Size(10, 10));
	blur(src, src, Size(1, 1));
	threshold(gray, thresh, thresh_low, 255, THRESH_BINARY);

	dilate(thresh, thresh, Mat(), Point(-1,-1), 2);
	erode(thresh, thresh, Mat(), Point(-1,-1), 2);
	
	int input = 0;
	for (int i = 0; i < 6; i++)
	{
		Rect sensorRect(115 + 75 * i, 285, 40, 40);
		rectangle(src, sensorRect, Scalar(0,0,255), 2);

		int count = countNonZero(thres(sensorRect));
		cout<<count<<"\t";
		if (count < 700)
			input = input | 1 << i;
		else
			input = input | 0 << i;		
	}	
	
	int current[5] = {0b110011, 0b000111, 0, 0b111000, 0b001100};

	switch (input ^ current[index])
	{
		case 0b111111: 
			index = ((index - 2) * -1) + 2;	break;
		case 0b110100:
			index =  (2 / (index - 2)) + 2;	break;
		case 0b001011:
			index = (-2 / (index - 2)) + 2;	break;		
	}
	
	cout<<"\ninp "<<input<<"\tindx "<<index<<"\t";
	error_calc(input ^ current[index]);	
	
	tuning();
	show();
}

void ir::error_calc(int input)
{
	int left = input >> 3;
	int right = input ^ left << 3;

	//swapping 0th and 2nd position	
	int x = (right >> 0 & 1) ^ (right >> 2 & 1);
	x = (x << 0) | (x << 2); 
	right = right ^ x;

	int error = right * -1 + left;
	cout<<input<<"\t"<<error<<endl;

	std_msgs::Int16 msg;
	msg.data = error;
	pub.publish(msg);
}
