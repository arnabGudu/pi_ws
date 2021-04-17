import serial
import time
import rospy

from std_msgs.msg import Int16

ser = serial.Serial('/dev/ttyUSB0', 115200)

def callback(data):
    ser.write(str(data.data))
    
def listener():
    rospy.init_node('motor', anonymous=True)
    rospy.Subscriber("speed", Int16, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
