#include "stdint.h"
#include "math.h"

void segment_output(float total_distance)
{
	number = ceil(total_distance);
	if(number!=0)
	{
  hundreds =floor(number/100);
	number = number %100; 
  tens = floor(number/10);
	number = number %10; 
	units = number;
		
	test=hundreds << 5;
	GPIO_PORTA_DATA_R = GPIO_PORTA_DATA_R &0x0F ;
  GPIO_PORTA_DATA_R |= test  ; // hudreds :limit 700 A5 ->A7
	test=tens << 1;
	GPIO_PORTE_DATA_R = test;//tens E1->EE4
	GPIO_PORTD_DATA_R =  units;//units  D0->D3

	
	}
	
	
}
