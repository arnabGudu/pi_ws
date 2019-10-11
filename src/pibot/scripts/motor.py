#!/usr/bin/env python
import RPi.GPIO as io
import rospy
from std_msgs.msg import Int16 

EN = [12, 33]
IN = [16, 18, 29, 31]

io.setmode(io.BOARD)
io.setwarnings(False)
io.setup(EN, io.OUT, initial=io.LOW)
io.setup(IN, io.OUT, initial=io.LOW)
io.output(IN, (io.LOW, io.HIGH, io.LOW, io.HIGH))

en1 = io.PWM(EN[0], 1000)
en1.start(50)	
en2 = io.PWM(EN[1], 1000)
en2.start(50)

def callback(data):
	bal = data.data;
	en1.ChangeDutyCycle(50 + bal)
	en2.ChangeDutyCycle(50 - bal)
	print 'error :', bal, 'left :', 50 + bal, 'right :', 50 - bal

def stop():
	en1.stop()
	en2.stop()
	io.output(EN, io.LOW)
	io.output(IN, io.LOW)
	io.cleanup()

def listener():
	rospy.init_node('motor', anonymous = True)
	rospy.Subscriber('speed', Int16, callback)
	rospy.spin()
	stop()

if __name__ == '__main__':
	listener()

	
			


