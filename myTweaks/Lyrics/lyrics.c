/*
   Using the wiringPi (Gordon Henderson)  and PCD8544 (AdaFruit Industries Inc) libraries for Nokia LCD PCD8544 display.

   Author: Girish M


*/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "PCD8544/PCD8544.h"

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
  printf("Your favorite lyrics...\n");
  printf("========================================\n");

  initLCDmodule();  
      
  while(writeLyrics() !=  0)

  return 0;
}

int initLCDmodule(){
  /// check wiringPi setup
  if (wiringPiSetup() == -1)
  {
	printf("wiringPi-Error\n");
    exit(1);
  }
  //init and clear lcd
  LCDInit(_sclk, _din, _dc, _cs, _rst, contrast);
  LCDclear();
  delay(1000);
  return 0;
}

int writeLyrics(){
   FILE* fptr;
   char* line = NULL;
   size_t len = 0;
   ssize_t read;
   
   fptr = fopen("lyrics.txt", "r");
   if(fptr == NULL)
	exit(EXIT_FAILURE);

   while((read=getline(&line, &len, fptr)) != -1)
   {
     delay(2000);
     printf("%s", line);
     LCDdrawstring(0,0,line);
     delay(2000);
     LCDdisplay();
     delay(2000);
     LCDclear();
   }
   delay(2000);
   free(line);
   fclose(fptr);
   return 0;
}





