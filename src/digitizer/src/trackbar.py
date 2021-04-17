import cv2 as cv
import numpy

h = 0
s = 0
v = 0
H = 255
S = 255
V = 255

def change(x):
	pass
	
cv.namedWindow('thresh')
cv.createTrackbar('h', 'thresh', 0, 255, change)
cv.createTrackbar('s', 'thresh', 0, 255, change)
cv.createTrackbar('v', 'thresh', 0, 255, change)
cv.createTrackbar('H', 'thresh', 255, 255, change)
cv.createTrackbar('S', 'thresh', 255, 255, change)
cv.createTrackbar('V', 'thresh', 255, 255, change)


cap = cv.VideoCapture(0)

while True:
	ret, src = cap.read()
	if src is None:
		break
		
	h = cv.getTrackbarPos('h', 'thresh')
	s = cv.getTrackbarPos('s', 'thresh')
	v = cv.getTrackbarPos('v', 'thresh')
	H = cv.getTrackbarPos('H', 'thresh')
	S = cv.getTrackbarPos('S', 'thresh')
	V = cv.getTrackbarPos('V', 'thresh')
	
	thresh = cv.inRange(src, (h,s,v), (H,S,V))
	cv.imshow('src', src)
	cv.imshow('thresh', thresh)
	cv.waitKey(10)
