#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int L = 55, H = 255, a = 100, ht = 40, canny_thresh;

int main(int argc, char **argv)
{ 
	VideoCapture cap(0);
	
	Mat src, gray, thresh, canny;
	
	namedWindow("thresh");
	namedWindow("src");
	createTrackbar("L", "thresh", &L, 255, NULL);
	createTrackbar("ht", "thresh", &ht, 255, NULL);
	createTrackbar("A", "thresh", &a, 255, NULL);
	createTrackbar("c", "thresh", &canny_thresh, 255, NULL);
	
	while(cap.isOpened())
	{
		cap >> src;
		
		resize(src, src, Size(), 0.5, 0.5, CV_INTER_AREA);
		
		Rect r(0, ht, src.cols, src.rows - ht);
		//rectangle(src, r, Scalar(255, 255, 0), 2);
		
		src = src(r);
		
		cvtColor(src, gray, CV_BGR2GRAY);
		blur(src, src, Size(1, 1));
		threshold(gray, thresh, L, 255, THRESH_BINARY_INV);

		dilate(thresh, thresh, Mat(), Point(-1,-1), 2);
		erode(thresh, thresh, Mat(), Point(-1,-1), 2);
		
		vector< vector< Point > > contours;
		findContours(thresh, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

		int cnt_size = contours.size();
		
		vector<Moments> mu(cnt_size);
		vector<Point2f> mc(cnt_size);
		Point2f mid = Point2f(0,0);
		
		for (int i = 0; i < cnt_size; i++)
		{
			if (contourArea(contours[i]) < a)
				continue;
			
			mu[i] = moments(contours[i], false);
			mc[i] = Point2f(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
			
			circle(src, mc[i], 2, Scalar(255,0,255), 2);
			
			mid.x += mc[i].x;
			mid.y += mc[i].y;
			
			drawContours(src, contours, i, Scalar(0,255,0), 2);
		}
		
		mid.x /= cnt_size;
		mid.y /= cnt_size;
		
		float error = src.cols/2 - mid.x;
		cout<<error<<endl;
		
		circle(src, mid, 2, Scalar(0,0,255), 2);
		line(src, Point(src.cols/2, 0), Point(src.cols/2, src.rows), Scalar(0, 0, 255), 2); 	

		imshow("thresh", thresh);
		imshow("src", src);
		waitKey(10);
	}
	return 0;
}
