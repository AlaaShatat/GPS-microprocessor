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
 uint32_t test = 0x0000  ;
 uint32_t hundreds = 0x0000;
uint32_t tens = 0x0000;
uint32_t units = 0x0000;	
uint32_t number= 0x0000;
float total_distance = 0x0000 ;
uint32_t i = 0x0000  ;
uint32_t j = 0x0000  ;
float earthRadiusKm;
float dLat;
float dLon;
float a;
float c;
float lat1;
float lat2;
float lon1;
float lon2;
uint8_t in ; 
uint8_t out ; 
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
