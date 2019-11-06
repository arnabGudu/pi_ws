import cv2 as cv
import imutils
	
def detect_shape(contour):
	shape = "unknown"
	peri = cv.arcLength(contour, True)
	approx = cv.approxPolyDP(contour, 0.04 * peri, True)
	area = cv.contourArea(contour)

	M = cv.moments(contour)
	center = (0,0)
	if M["m00"] != 0:
		cX = int(M["m10"] / M["m00"])
		cY = int(M["m01"] / M["m00"])
		center = (cX, cY)

	side = len(approx)

	if side == 3:
		shape = "triangle"
	
	elif side == 4:
		(x, y, w, h) = cv.boundingRect(approx)
		ratio = w / float(h)
	
		if (ratio >= 0.95 and ratio <= 1.05):
			shape = "square"
		else:
			shape = "rectangle"

	else:
		shape = "circle"
	
	return side, area, center
		
def find_coord(thresh, img):
	cnts = cv.findContours(thresh.copy(), cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
	cnts = imutils.grab_contours(cnts)

	order = []
	for c in cnts:
		side, area, center = detect_shape(c)
		cv.circle(img, center, 2, (255, 255, 255), -1)
		cv.drawContours(img, [c], -1, (0, 255, 0), 2)

		order.append([side, area, center])
		#print side, area, center

	return order
		
#thresh = cv.threshold(blur, 60, 255, cv.THRESH_BINARY)[1]
