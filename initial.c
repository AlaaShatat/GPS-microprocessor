#include "stdint.h"
#include "T:/asu/3rd CSE/Second-term/Microprocessor/Project/GPS-microprocessor/tm4c123gh6pm.h"
void init()
{
	volatile unsigned long delay;
			// PORT A initial
		SYSCTL_RCGCGPIO_R |= 0x01; // port B select
	//delay = 1;
	while((SYSCTL_PRGPIO_R & 0x01) == 0){}; //delay until the portA is granted
	GPIO_PORTA_AFSEL_R = 0xFF; // alternate function select to GPIO
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTA_AMSEL_R = 0; // no analog
	GPIO_PORTA_DIR_R  = 0xFF; // UART
	GPIO_PORTA_DEN_R = 0xFF; // all pins are digital enabled
	GPIO_PORTA_PUR_R = 0; // no pull up resistors are needed
	//GPIO_PORTA_LOCK_R = 0x4C4F434B; //  lock port D
	GPIO_PORTA_CR_R |= 0xFF; // enable commiit to the 8 bins
		
		
		// PORT B initial
		SYSCTL_RCGCGPIO_R |= 0x02; // port B select
	//delay = 1;
	while((SYSCTL_PRGPIO_R & 0x02) == 0){}; //delay until the portB is granted
	GPIO_PORTB_AFSEL_R = 0x03; // alternate function select to UART and GPIO
	GPIO_PORTB_PCTL_R = 0;
	GPIO_PORTB_AMSEL_R = 0; // no analog
	GPIO_PORTB_DIR_R  = 0xFF; // all pins are output
	GPIO_PORTB_DEN_R = 0xFF; // all pins are digital output 
	GPIO_PORTB_PUR_R = 0; // no pull up resistors are needed
	//GPIO_PORTB_LOCK_R = 0x4C4F434B; //  lock port D
	GPIO_PORTB_CR_R |= 0xFF; // enable commiit to the 8 bins
}