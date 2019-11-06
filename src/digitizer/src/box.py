import cv2 as cv
import imutils
import numpy as np

def show():
	cv.imshow('img', img)
	#cv.imshow('tracks', tracks)
	cv.waitKey(0)

def box(img):
	hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
	thresh = cv.inRange(hsv, (0,89,72), (255,255,255))
	whites = cv.inRange(hsv, (0,0,72), (255,255,255))
	tracks = whites ^ thresh

	kernel = np.ones((5,5), np.uint8)
	tracks = cv.erode(tracks, kernel, iterations=1)

	cnts = cv.findContours(tracks, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
	cnts = imutils.grab_contours(cnts) 

	center = []
	for c in cnts:
		cv.drawContours(img, [c], -1, (0, 255, 0), 2)
		M = cv.moments(c)
	
		if M["m00"] != 0:
			cX = int(M["m10"] / M["m00"])
			cY = int(M["m01"] / M["m00"])
			center.append((cX, cY))
			cv.circle(img, (cX, cY), 1, (255, 0, 0), 2)
	return center
	
if __name__ == '__main__':
	img = cv.imread('img1.png', cv.IMREAD_COLOR)
	print box(img)
	show()
		
