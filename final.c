#include "stdint.h"
#include "math.h"
#include "tm4c123gh6pm.h" // make sure to change file path
#include "delay.c"
#include "seven_segment.c"
#include "initial.c"
#include "TurnOnAfterDistance.c"
#include ""
//#define CPAC (*((volatile uint32_t*)0xE000ED88))
void SystemInit(){
   NVIC_CPAC_R |=0x00F00000;

//CPAC |=0x00F00000;

};
int main()
{
	init();
	
}
