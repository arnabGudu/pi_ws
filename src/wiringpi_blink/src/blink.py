import RPi.GPIO as GPIO
import time

led = 35

GPIO.setmode(GPIO.BOARD)
GPIO.setup(led, GPIO.OUT)

try:
	while True:
		GPIO.output(led, GPIO.HIGH)
		time.sleep(1)
		GPIO.output(led, GPIO.LOW)
		time.sleep(1)
except KeyboardInterrupt:
	GPIO.output(led, GPIO.LOW)
	GPIO.cleanup()


