#include "lane_hl/lane_hl.h"

void lane::hough()
{
	vector<Vec4i> lines;
	HoughLinesP(canny, lines, 1, CV_PI/180, 10, 8, 4);
	size_t n = lines.size();
	
	int slope[n][2];
	
	for (size_t i = 0; i < lines.size(); i++ )
	{
		Vec4i l = lines[i];
		slope[i][0] = float(l[3] - l[1]) / float(l[2] - l[0]);
		line(src, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,0,0), 1);
	}
	
	int max;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++)
	{	
		if (visited[i] == true)
				continue;
				
		int count = 1;	
		for (int j = i + 1; j < n; j++)
		{
			if (slope[i][0] == slope[j][0])
			{
				visited[j] = true;
				count++;
			}
		}
		slope[i][1] = count;
		
		if (count > max)
			max = count;	
	}
	cout<<max<<endl;
	for (int i = 0; i < n; i++)
	{
		slope[i][1] /= 2;
		if (slope[i][1] > 1)
		{
			Vec4i l = lines[i];
			line(src, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3);
		}
	}			
}

