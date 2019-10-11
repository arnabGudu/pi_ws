#ifndef CAM
#define CAM

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class cam
{
public:
	cam();
	int process();
	
private:
	Mat src, gray, thresh;
	VideoCapture cap;

	void show();
	void perform();
	
	int thres_low, area, ht, canny_thresh, error;
};

#endif
