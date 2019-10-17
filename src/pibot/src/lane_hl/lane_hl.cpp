#include "lane_hl/lane_hl.h"

lane::lane(int argc, char** argv)
{
	h = 0; s = 0; v = 162;
	H = 42; S = 255; V = 255;
	ht = 40;
	flag = 1;
	blur_size = 1;
	canny_ratio = 3;
	canny_low = 50;
	size_factor = 25;

	int cap_flag = -1;
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
			cap_flag = i;
	}		
	if (cap_flag != -1)
		cap.open(argv[cap_flag]);
	else
		cap.open(0);
}

lane::~lane()
{
	cap.release();
	destroyAllWindows();
}

int lane::process()
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

void lane::perform()
{
	Mat hsv;
	cvtColor(src, hsv, CV_BGR2HSV);
	blur(hsv, hsv, Size(blur_size, blur_size));
	
	inRange(hsv, Scalar(h, s, v), Scalar(H, S, V), thresh);	
	
	Canny(thresh, canny, canny_low, canny_low * canny_ratio);
		
	hough();
}

void lane::trackbar()
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
	
void lane::show()
{
	if (flag & 1)
		imshow("src", src);
	if (flag & 2)
		imshow("thresh", thresh);
	if (flag & 4)
		imshow("canny", canny);
	waitKey(10);
}


