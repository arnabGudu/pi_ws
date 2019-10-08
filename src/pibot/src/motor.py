import RPi.GPIO as io
import time

EN = [12, 33]
IN = [16, 18, 29, 31]

io.setmode(io.BOARD)

io.setup(EN, io.OUT, initial=io.LOW)
io.setup(IN, io.OUT, initial=io.LOW)

pwm = io.PWM(EN, 1000)		# set Frequece to 1KHz

pwm.start(0)				# Start PWM output, Duty Cycle = 0

io.output(IN, (io.HIGH, io.LOW, io.HIGH, io.LOW))

try:
        while True:
                for dc in range(0, 101, 5):   # Increase duty cycle: 0~100
                        pwm.ChangeDutyCycle(dc)     # Change duty cycle
                        time.sleep(0.05)
                time.sleep(1)
                for dc in range(100, -1, -5): # Decrease duty cycle: 100~0
                        pwm.ChangeDutyCycle(dc)
                        time.sleep(0.05)
                time.sleep(1)

except KeyboardInterrupt:
        p.stop()
        io.output(EN, io.LOW)
        io.output(IN, io.LOW)
        io.cleanup()

