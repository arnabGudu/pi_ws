#include "wiringPi.h"
#include "stdio.h"

using namespace wiringPi;

int main(int argc, char** argv)
{
	wiringPiSetupGpio();
	pinMode(2, OUTPUT);

	while(true)
	{
		digitalWrite(2, HIGH);
		delay(1000);
		digitalWrite(2, LOW);
		delay(1000);
	}
}
