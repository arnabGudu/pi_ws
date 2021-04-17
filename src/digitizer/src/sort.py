import circle
import shape
import math

def shorted(img, thresh):
	circles = circle.detect_circle(img)
	order = shape.find_coord(thresh, img)

	#removes circles from the detected_shapes as it detects wrong no. of sides
	for c in circles[0, :]:
		(cx, cy) =  (c[0], c[1])

		i = 0
		for shapes in order:
			(sx, sy) = shapes[2]

			dist = math.sqrt((cy - sy)**2 + (cx - sx)**2)
			if dist < 10:
				del order[i]
			i = i + 1

	order.sort();
	return order
