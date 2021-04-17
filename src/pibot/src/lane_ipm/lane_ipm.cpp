#include "lane_ipm/lane_ipm.h"

ipm::ipm(int argc, char** argv)
{
	h = 0; s = 0; v = 0;
	H = 255; S = 255; V = 255;
	ht = 40;
	flag = 1;	//not req
	blur_size = 1;
	canny_ratio = 3;
	canny_low = 50;
	size_factor = 25;

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
			cap.open(1);
	}		
}

ipm::~ipm()
{
	cap.release();
	destroyAllWindows();
}

int ipm::process()
{
	if (cap.isOpened())
	{
		float f = size_factor * 0.01;
		cap >> src;
		resize(src, src, Size(), f, f, CV_INTER_AREA);
		Rect r(0, ht, src.cols, src.rows - ht);
		src = src(r);
		
		perform();
		show();
	}
	return error;
}

void ipm::perform()
{
	//Mat hsv;
	//cvtColor(src, hsv, CV_BGR2HSV);
	//blur(hsv, hsv, Size(blur_size, blur_size));
	
	//inRange(hsv, Scalar(h, s, v), Scalar(H, S, V), thresh);	
	
	//Canny(thresh, canny, canny_low, canny_low * canny_ratio);
		
	plot();
	Mat M = getPerspectiveTransform(src_vert, dst_vert);
	dst = Mat(480, 640, CV_8UC3);
	warpPerspective(src, dst, M, dst.size(), INTER_LINEAR, BORDER_CONSTANT);
}

void ipm::trackbar()
{
	namedWindow("src");
	createTrackbar("ht", "src", &ht, 255, NULL);
	createTrackbar("size", "src", &size_factor, 100, NULL);
	
	namedWindow("thresh");
	createTrackbar("h", "thresh", &h, 255, NULL);
	createTrackbar("s", "thresh", &s, 255, NULL);
	createTrackbar("v", "thresh", &v, 255, NULL);
	createTrackbar("H", "thresh", &H, 255, NULL);
	createTrackbar("S", "thresh", &S, 255, NULL);
	createTrackbar("V", "thresh", &V, 255, NULL);
	createTrackbar("blr", "thresh", &blur_size, 5, NULL);
	
	namedWindow("canny");
	createTrackbar("canny_low", "canny", &canny_low, 255, NULL);
	createTrackbar("canny_ratio", "canny", &canny_ratio, 5, NULL);
}

void ipm::plot()
{
	src_vert[0] = Point(x1, y1);
	src_vert[1] = Point(x2, y1);
	src_vert[2] = Point(x4, y2);
	src_vert[3] = Point(x3, y2);

	dst_vert[0] = Point(0, 0);
	dst_vert[1] = Point(640, 0);
	dst_vert[2] = Point(640, 480);
	dst_vert[3] = Point(0, 480);

	line(src, Point(x1, y1), Point(x2, y1), Scalar(0,0,255), 2);
	line(src, Point(x3, y2), Point(x4, y2), Scalar(0,0,255), 2);
	line(src, Point(x1, y1), Point(x3, y2), Scalar(0,0,255), 2);
	line(src, Point(x2, y1), Point(x4, y2), Scalar(0,0,255), 2);
	circle(src, Point(x1, y1), 1, Scalar(0, 255, 0), 2);
	circle(src, Point(x2, y1), 1, Scalar(0, 255, 0), 2);
	circle(src, Point(x3, y2), 1, Scalar(0, 255, 0), 2);
	circle(src, Point(x4, y2), 1, Scalar(0, 255, 0), 2);
}	

void ipm::show()
{
	if (flag & 1)
		imshow("src", src);
	
	if (flag & 8)
		imshow("dst", dst);
		
	waitKey(10);
}


