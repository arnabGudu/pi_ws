#include <wiringPi.h>

int main()
{
  wiringPiSetup();              // Setup required by wiringPi
  pinMode (1, PWM_OUTPUT);      // 
  pwmSetMode(PWM_MODE_MS);      // Mark/Space mode
 
  int i;
 
  while(1)
  {
    for (i = 255; i > -1; i--)
    {
      pwmWrite(1, i);
      delay(10);
    } 

    for (i = 0; i < 256; i++)
    {
      pwmWrite(1, i);
      delay(10);
    }
  }
}

