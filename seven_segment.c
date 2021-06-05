#include "stdint.h"
#include "math.h"
#include "tm4c123gh6pm.h"
#include "initial.h"
void SystemInit(){}
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
		
	test=hundreds << 5;
  GPIO_PORTA_DATA_R |= test  ; // hudreds :limit 700 A5 ->A7
	test=tens << 1;
	GPIO_PORTE_DATA_R |= test;//tens E1->EE4
	GPIO_PORTD_DATA_R |=  units;//units  D0->D3
	//a2a3a4a5a6a7
	//e4e5e3e2e1
  //GPIO_PORTE_DATA_R =  test;
//	GPIO_PORTF_DATA_R = GPIO_PORTD_DATA_R;
	//
	
	//''test = tens ; 
	//''test = test << 4 ;
	//''test = test | units ;
	
	}
	
  //''GPIO_PORTD_DATA_R = test ; 
  //''GPIO_PORTE_DATA_R = hundreds;
	
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

