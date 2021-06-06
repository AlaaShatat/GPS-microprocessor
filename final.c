#include "stdint.h"
#include "math.h"
#include "tm4c123gh6pm.h" // make sure to change file path
#include "initial.c"
#include "delay.c"
#include "seven_segment.c"
#include "TurnOnAfterDistance.c"
//#define CPAC (*((volatile uint32_t*)0xE000ED88))
void SystemInit(){
   NVIC_CPAC_R |=0x00F00000;

//CPAC |=0x00F00000;

};
int main()
{
	init();
	
total_distance=0;
while(1)
{
while(total_distance<=799)
{
total_distance+=distanceInMeters(lat1,lon1,lat2,lon2);
ledlight(total _distance);
segment_output(total_distance);
Delay(5000);
}
	
}
