#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char **argv)
{
	VideoCapture cap(0);
	
	Mat src;
	
	while(cap.isOpened())
	{
		cap >> src;
		
		imshow("src", src);
		waitKey(10);
	}
	return 0;
}
