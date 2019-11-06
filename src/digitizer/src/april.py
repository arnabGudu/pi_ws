import apriltag
import cv2 as cv
import numpy
import imutils
import math

def show():
	cv.imshow("img", img)
	cv.waitKey()
	
def points(center, corners):
	print center, corners
	
	cv.circle(img, (int(center[0]), int(center[1])), 1, (0, 0, 255), 2)

	i = 0
	for points in corners:
		i = i + 1
		cv.circle(img, (int(points[0]), int(points[1])), 1 + 2 * i, (255, 0, 0), 2)

	x1, y1 = corners[0][0], corners[0][1]
	x2, y2 = corners[3][0], corners[3][1]
	
	angle = math.atan2(y2 - y1, x2 - x1) * 180 / math.pi
	return angle

def operation(img):
	gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
	detector = apriltag.Detector()
	result = detector.detect(gray)
	angle = points(result[0].center, result[0].corners)
	print 'center', result[0].center
	
def angle():
	return angle

def center():
	return center
	
if __name__ == '__main__':
	img = cv.imread('apriltag_foto.png', cv.IMREAD_COLOR)
	operation(img)
	show()
