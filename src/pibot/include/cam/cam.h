#ifndef CAM
#define CAM

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class cam
{
public:
	cam(int argc, char ** argv);
	int process(int flag = 1);
	
protected:
	void show(int);
	Mat src;
	VideoCapture cap;
	int ht, error;
	
private:
	Mat gray, thresh;
	void perform();
	void trackbar();
	int thresh_low, area, canny_thresh, flag;
};

#endif
