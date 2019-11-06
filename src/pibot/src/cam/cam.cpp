#include "cam/cam.h"

cam::cam(int argc, char ** argv)
{	
	error = 0;
	thresh_low = 200;	//55 for black
	area = 100;
	ht = 40;
	
	if (argc == 1)
		cap.open(0);
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (argv[i][0] == 't')
				trackbar();
			
			if (argv[i][0] == 's')
				if (argv[i][1] != '\0')
					flag = argv[i][1] - '0';
				else
					flag = 7;
		
			if (argv[i][0] == '~' || argv[i][0] == '/')
				cap.open(argv[i]);
			else
				cap.open(0);
		}
	}
}

int cam::process()
{
	if (cap.isOpened())
	{
		cap >> src;
		resize(src, src, Size(), 0.25, 0.25, CV_INTER_AREA);
		Rect r(0, ht, src.cols, src.rows - ht);
		src = src(r);
		
		perform();
		show();
	}
	return error;
}

void cam::trackbar()
{	
	namedWindow("thresh");
	createTrackbar("low", "thresh", &thresh_low, 255, NULL);
}

void cam::perform()
{
	cvtColor(src, gray, CV_BGR2GRAY);
	blur(src, src, Size(1, 1));
	threshold(gray, thresh, thresh_low, 255, THRESH_BINARY);

	dilate(thresh, thresh, Mat(), Point(-1,-1), 2);
	erode(thresh, thresh, Mat(), Point(-1,-1), 2);
	
	vector< vector< Point > > contours;
	findContours(thresh, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
	
	int cnt_size = contours.size();
		
	vector <RotatedRect> min(cnt_size);
	float mid = 0, angle = 0;
	
	for (int i = 0; i < cnt_size; i++)
	{
		if (contourArea(contours[i]) < area)
			continue;
		
		min[i] = minAreaRect(contours[i]);
		
		Point2f rect_points[4];
		min[i].points(rect_points);
		for(int j = 0; j < 4; j++)
		{
			line(src, rect_points[j], rect_points[(j+1)%4], Scalar(0,0,255), 2);
		}

		if (min[i].size.width < min[i].size.height)
		{
			angle += (int)min[i].angle;
		}
		else 
		{
			angle += (int)min[i].angle + 90;
		}
		mid += min[i].center.x;
		
		circle(src, Point(min[i].center.x, min[i].center.y), 2, Scalar(0,0,255), 2);
		drawContours(src, contours, i, Scalar(0,255,0), 2);
	}
	
	mid /= cnt_size;
	
	error = src.cols/2 - mid;
	cout<<error<<endl;
	
	circle(src, Point(mid, src.rows/2), 2, Scalar(0,0,255), 2);
	line(src, Point(src.cols/2, 0), Point(src.cols/2, src.rows), Scalar(0, 0, 255), 2); 	
}

void cam::show()
{
	if (flag & 1)
		imshow("src", src);
	if (flag & 2)
		imshow("gray", gray);
	if (flag & 4)
		imshow("thresh", thresh);
	waitKey(10);
}

