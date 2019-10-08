import RPi.GPIO as GPIO
import time

enA = 32
enB = 35

in1 = 12
in2 = 16
in3 = 18
in4 = 11
 
GPIO.setmode(GPIO.BOARD)       # Numbers pins by physical location

GPIO.setup(enA, GPIO.OUT)  
GPIO.setup(enB, GPIO.OUT)
GPIO.setup(in1, GPIO.OUT)
GPIO.setup(in2, GPIO.OUT)
GPIO.setup(in3, GPIO.OUT)
GPIO.setup(in4, GPIO.OUT)

GPIO.output(enA, GPIO.LOW) 
GPIO.output(enB, GPIO.LOW)
GPIO.output(in1, GPIO.HIGH)
GPIO.output(in2, GPIO.LOW)
GPIO.output(in3, GPIO.HIGH)
GPIO.output(in4, GPIO.LOW)

p = GPIO.PWM(enA, 1000)     # set Frequece to 1KHz
q = GPIO.PWM(enB, 1000)

q.start(0)
p.start(0)                     # Start PWM output, Duty Cycle = 0

try:
        while True:
                for dc in range(0, 101, 5):   # Increase duty cycle: 0~100
                        p.ChangeDutyCycle(dc)     # Change duty cycle
                        time.sleep(0.05)
                time.sleep(1)
                for dc in range(100, -1, -5): # Decrease duty cycle: 100~0
                        p.ChangeDutyCycle(dc)
                        time.sleep(0.05)
                time.sleep(1)

except KeyboardInterrupt:
        p.stop()
        GPIO.output(enA, GPIO.LOW)    # turn off all leds
	GPIO.output(enB, GPIO.LOW)
        GPIO.cleanup()

