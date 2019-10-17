#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int y1 = 240, y2 = 330;
int x1 = 260, x2 = 400, x3 = 115, x4 = 590;

void plot()
{
	src_vertices[0] = Point(x1, y1);
	src_vertices[1] = Point(x2, y1);
	src_vertices[2] = Point(x4, y2);
	src_vertices[3] = Point(x3, y2);

	dst_vertices[0] = Point(0, 0);
	dst_vertices[1] = Point(640, 0);
	dst_vertices[2] = Point(640, 480);
	dst_vertices[3] = Point(0, 480);

	line(src, Point(x1, y1), Point(x2, y1), Scalar(0,0,255), 2);
	line(src, Point(x3, y2), Point(x4, y2), Scalar(0,0,255), 2);
	line(src, Point(x1, y1), Point(x3, y2), Scalar(0,0,255), 2);
	line(src, Point(x2, y1), Point(x4, y2), Scalar(0,0,255), 2);
	circle(src, Point(x1, y1), 1, Scalar(0, 255, 0), 2);
	circle(src, Point(x2, y1), 1, Scalar(0, 255, 0), 2);
	circle(src, Point(x3, y2), 1, Scalar(0, 255, 0), 2);
	circle(src, Point(x4, y2), 1, Scalar(0, 255, 0), 2);
}

void trackbar(Mat src)
{
	namedWindow("src");
	createTrackbar("y1", "src", &y1, src.size().height, NULL);
	createTrackbar("y2", "src", &y2, src.size().height, NULL);

	createTrackbar("x1", "src", &x1, src.size().width, NULL);
	createTrackbar("x2", "src", &x2, src.size().width, NULL);
	createTrackbar("x3", "src", &x3, src.size().width, NULL);
	createTrackbar("x4", "src", &x4, src.size().width, NULL);
}

int main(int argc, char ** argv)
{
    Mat src;

    VideoCapture cap(argv[1]);
    cap >> src;
    trackbar(src);
        
    while (cap.isOpened())
    {
    	cap >> src;
		resize(src, src, Size(), .5, .5, CV_INTER_AREA);
		Point2f src_vertices[4], dst_vertices[4];
		
		plot();
		
		Mat M = getPerspectiveTransform(src_vertices, dst_vertices);
		Mat dst(480, 640, CV_8UC3);
		warpPerspective(src, dst, M, dst.size(), INTER_LINEAR, BORDER_CONSTANT);

		imshow("src", src);
		imshow("dst", dst);
		waitKey(10);
   }
}
