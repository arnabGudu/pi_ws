import cv2 as cv
import imutils
import sort
import math
import april
import box


def show():
	cv.imshow("img", img)
	#cv.imshow("thresh", thresh)
	key = cv.waitKey(0)

def change(x):
	pass
	
cv.namedWindow('thresh')
cv.createTrackbar('h', 'thresh', 0, 255, change)
cv.createTrackbar('s', 'thresh', 89, 255, change)
cv.createTrackbar('v', 'thresh', 72, 255, change)
cv.createTrackbar('H', 'thresh', 255, 255, change)
cv.createTrackbar('S', 'thresh', 255, 255, change)
cv.createTrackbar('V', 'thresh', 255, 255, change)

#while True:
img = cv.imread("img1.png", cv.IMREAD_COLOR)

scale_percent = 25 # percent of original size
width = int(img.shape[1] * scale_percent / 100)
height = int(img.shape[0] * scale_percent / 100)
dim = (width, height)
img = cv.resize(img, dim, interpolation = cv.INTER_AREA)
 
blur = cv.GaussianBlur(img, (5,5), 0)

h = cv.getTrackbarPos('h', 'thresh')
s = cv.getTrackbarPos('s', 'thresh')
v = cv.getTrackbarPos('v', 'thresh')
H = cv.getTrackbarPos('H', 'thresh')
S = cv.getTrackbarPos('S', 'thresh')
V = cv.getTrackbarPos('V', 'thresh')

hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
thresh = cv.inRange(hsv, (h,s,v), (H,S,V))
#whites = cv.inRange(hsv, (0,0,v), (H,S,V))
#cv.imshow('whites', whites ^ thresh)

order = sort.shorted(img, thresh)

pt1 = order[0][2]
print 'point 1:', pt1

mid_box = box.box(img)

for i in range(1, len(order)):
	pt2 = order[i][2]
	mid = ((pt2[0] + pt1[0])/2, (pt2[1] + pt1[1])/2)
	angle = math.atan2(pt2[1] - pt1[1], pt2[0] - pt1[0])
	dist = []
	for pts in mid_box:
		dist.append(math.hypot(mid[0] - pts[0], mid[1] - pts[1]))
	
	min_dist = min(dist)
	j = dist.index(min_dist)
	
	#april_ang, april_center = april.april(img)
	
	#theta = angle - april_ang
	
	#while theta <= 10 and april_center :
		#theta = angle - april.april(img)
		#pid.pid(theta)
	
	cv.circle(img, mid, 2, (0,0,255), 2)
	cv.line(img, pt2, pt1, (255, 0, 0), 2)
	pt1 = pt2
	show()


