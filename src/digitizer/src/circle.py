import cv2
import numpy as np

def detect_circle(img):
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	gray_blurred = cv2.blur(gray, (3, 3))
	detected_circles = cv2.HoughCircles(gray_blurred,
               cv2.HOUGH_GRADIENT, 1, 20, param1 = 50,
           param2 = 30, minRadius = 1) #, maxRadius = 100) 

	if detected_circles is not None:
		detected_circles = np.uint16(np.around(detected_circles))

	return detected_circles
