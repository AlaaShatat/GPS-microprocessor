#include "stdint.h"
//#include "D:/keil/New folder/clone m/tm4c123gh6pm.h" //aya path
#include "T:/asu\3rd CSE/Second-term/Microprocessor/Project\GPS-microprocessor/tm4c123gh6pm.h"
void SystemInit(){};
void init()
{
		// PORT F initial
		SYSCTL_RCGCGPIO_R |= 0x20; // port B select
	//delay = 1;
	while((SYSCTL_PRGPIO_R & 0x20) == 0){}; //delay until the portD is granted
	GPIO_PORTF_AFSEL_R = 0; // alternate function select to GPIO
	GPIO_PORTF_PCTL_R = 0;
	GPIO_PORTF_AMSEL_R = 0; // no analog
	GPIO_PORTF_DIR_R  = 0x0E; // LED as output
	GPIO_PORTF_DEN_R = 0x1F; // all pins are digital output 
	GPIO_PORTF_PUR_R = 0x11; // no pull up resistors are needed
	GPIO_PORTF_LOCK_R = 0x4C4F434B; //  lock port D
	GPIO_PORTF_CR_R |= 0x1F; // enable commiit to the 8 bins
}
uint32_t time = 500000;
int main()
{
	// call the initialization function
	init();
	// led-lightt in PORT F 
	while(1)
	{
		GPIO_PORTF_DATA_R = 0x04;
		
		while (time){  
		time -- ;
		}
			GPIO_PORTF_DATA_R = 0x02;
	
	



}