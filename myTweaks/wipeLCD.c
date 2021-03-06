/*
   Using the wiringPi (Gordon Henderson)  and PCD8544 (AdaFruit Industries Inc) libraries for Nokia LCD PCD8544 display.

   Author: Girish M


*/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "PCD8544.h"

// pin setup
int _din = 1;
int _sclk = 0;
int _dc = 2;
int _rst = 4;
int _cs = 3;
  
// lcd contrast 
int contrast = 70;
  
int main (void)
{
  // print infos
  printf("Wiping Raspberry Pi PCD8544 display\n");
  printf("========================================\n");
  
  // check wiringPi setup
  if (wiringPiSetup() == -1)
  {
	printf("wiringPi-Error\n");
    exit(1);
  }
  // init and clear lcd
  LCDInit(_sclk, _din, _dc, _cs, _rst, contrast);
  LCDclear();
  delay(1000);
  LCDdrawstring(0,0,"wiping...");
  delay(2000);
  LCDdisplay();
  return 0;
}
