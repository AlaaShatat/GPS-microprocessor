#include "stdint.h"
#include "math.h"
#include "D:\project\tm4c123gh6pm.h"


  int test = 0x0000  ;
  int hundreds = 0x00;
	int tens = 0x00;
	int units = 0x00  ;	
	long number= 0x00;
  long total_distance = 0x0000 ;
void segment_output(long total_distance)
{
	number = ceil(total_distance);
	if(number!=0)
	{
  hundreds =floor(number/100);
	number = number %100; 
  tens = floor(number/10);
	number = number %10; 
	units = number;
	
	test = tens ; 
	test = test << 4 ;
	test = test | units ;
	
	}
	
  GPIO_PORTD_DATA_R = test ; 
  GPIO_PORTE_DATA_R = hundreds;
	
}

int main ()
{
	while(1)
	{
	init();
	total_distance = 128;
  segment_output(total_distance);
	}
}

