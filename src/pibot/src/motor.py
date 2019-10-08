import RPi.GPIO as io
import rospy
from std_msgs.msg import Int16 

EN = [12, 33]
IN = [16, 18, 29, 31]

io.setmode(io.BOARD)
io.setup(EN, io.OUT, initial=io.LOW)
io.setup(IN, io.OUT, initial=io.LOW)
io.output(IN, (io.HIGH, io.LOW, io.HIGH, io.LOW))

en1 = io.PWM(EN[0], 1000)
en1.start(0)	
en2 = io.PWM(EN[1], 1000)
en2.start(0)

def callback(data):
	pwm.ChangeDutyCycle(50 + data)
	pwm.ChangeDutyCycle(50 - data)

def listener():
	rospy.init_node('motor', anonymous = True)
	rospy.Subscriber('speed', Int16, callback)
	rospy.spin()

if __name__ == '__main__':
	try:
		listener()

	except KeyboardInterrupt:
		    en1.stop()
		    en2.stop()
		    io.output(EN, io.LOW)
		    io.output(IN, io.LOW)
		    io.cleanup()	
			


