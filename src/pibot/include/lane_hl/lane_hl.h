#ifndef HL
#define HL

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class lane					//**inheritance of cam class as public
{							//i.e., cam.public = lane_hl.public
public:						//and cam.protected = lane_hl.protected**
	lane(int, char**);
	~lane();
	int process();
	
private:
	void hough();	
	void trackbar();
	void show();	 
	void perform();			//**inherited function overloading**
							//perform() performs geometrical
							//merphological transformations
	Mat thresh, canny, src;
	int h, s, v, H, S, V, ht;
	int blur_size, canny_ratio, canny_low, kernel_size, size_factor;
	int error, flag;
	VideoCapture cap;
};	
#endif
