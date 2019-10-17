#ifndef IPM
#define IPM

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class ipm					//**inheritance of cam class as public
{							//i.e., cam.public = lane_hl.public
public:						//and cam.protected = lane_hl.protected**
	ipm(int, char**);
	~ipm();
	int process();
	
private:
	void trackbar();
	void show();	
	void plot(); 
	void perform();			//**inherited function overloading**
							//perform() performs geometrical
							//merphological transformations
	Mat thresh, canny, src, dst;
	int h, s, v, H, S, V, ht;
	int blur_size, canny_ratio, canny_low, kernel_size, size_factor;
	
	Point2f src_vert[4], dst_vert[4];
	int x1,x2,x3,x4,y1,y2;	
	
	int error, flag;
	VideoCapture cap;
};	
#endif
