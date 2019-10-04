import wiringpi
from time import sleep

wiringpi.wiringPiSetupGpio() 

wiringpi.pinMode(2, 1)      # sets GPIO 24 to output  

while True:
	wiringpi.digitalWrite(2, 0) # sets port 24 to 0 (0V, off)  
	print("1")
	sleep(.5)                    # wait 10s  
	wiringpi.digitalWrite(2, 1) # sets port 24 to 1 (3V3, on)  
	sleep(.5)  
	print("0")                  # wait 10s    
