#include "stdint.h"
#include "T:/asu/3rd CSE/Second-term/Microprocessor/Project/GPS-microprocessor/tm4c123gh6pm.h"
// function 
void ledlight(double distance)
{
	
	// calcDistance();
	if (distance >=100)
	{
		GPIO_PORTF_DATA_R = 0x02; // turn led on
	} 
}