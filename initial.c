#include "stdint.h"
#include "tm4c123gh6pm.h"


	
void systick_int(){

NVIC_ST_CTRL_R =0 ;    
NVIC_ST_RELOAD_R =1600-1; 
NVIC_ST_CURRENT_R =0;
NVIC_ST_CTRL_R =5 ;
}
void One_Second_Delay(uint32_t time)
{ while (time){
    NVIC_ST_CTRL_R = 0;            /* disable SysTick during setup */
    NVIC_ST_RELOAD_R = 15999999;    /* Reload Value goes here */
    NVIC_ST_CTRL_R |= 0x5;          /* enable SysTick with core clock */
    while( (NVIC_ST_CTRL_R & (1<<16) ) == 0)
        ;                           /* Monitoring bit 16 to be set */
    NVIC_ST_CTRL_R = 0;             /* Disabling SysTick Timer */
time -- ; 

}}


void init()
{
	volatile unsigned long delay;
			// PORT A initial
		SYSCTL_RCGCGPIO_R |= 0x01; // port A select
	//delay = 1;
	while((SYSCTL_PRGPIO_R & 0x01) == 0){}; //delay until the portA is granted
	GPIO_PORTA_AFSEL_R = 0xFF; // alternate function select to GPIO
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTA_AMSEL_R = 0; // no analog
	GPIO_PORTA_DIR_R  = 0xFF; // UART
	GPIO_PORTA_DEN_R = 0xFF; // all pins are digital enabled
	GPIO_PORTA_PUR_R = 0; // no pull up resistors are needed
	//GPIO_PORTA_LOCK_R = 0x4C4F434B; //  lock port A
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
	//GPIO_PORTB_LOCK_R = 0x4C4F434B; //  lock port B
	//GPIO_PORTB_CR_R |= 0xFF; // enable commiit to the 8 bins
		
		// initialize port D
	
	SYSCTL_RCGCGPIO_R |= 0x08; // port D select
	delay = 1;
	//while((SYSCTL_PRGPIO_R & 0x08) == 0){}; //delay until the portD is granted
	GPIO_PORTD_AFSEL_R = 0x00; // alternate function select to GPIO
	GPIO_PORTD_PCTL_R = 0;
	GPIO_PORTD_AMSEL_R = 0; // no analog
	GPIO_PORTD_DIR_R  = 0xFF; // all pins are output
	GPIO_PORTD_DEN_R = 0xFF; // all pins are digital output 
	GPIO_PORTD_PUR_R = 0; // no pull up resistors are needed
		
			// initialize port E
	
	SYSCTL_RCGCGPIO_R |= 0x10; // port E select
	//delay = 1;
	while((SYSCTL_PRGPIO_R & 0x09) == 0){}; //delay until the portE is granted
	GPIO_PORTE_AFSEL_R = 0; // alternate function select to GPIO
	GPIO_PORTE_PCTL_R = 0;
	GPIO_PORTE_AMSEL_R = 0; // no analog
	GPIO_PORTE_DIR_R  = 0xFF; // all pins are output
	GPIO_PORTE_DEN_R = 0xFF; // all pins are digital output 
	GPIO_PORTE_PUR_R = 0; // no pull up resistors are needed
	//GPIO_PORTE_LOCK_R = 0x4C4F434B; //  lock port E
	//GPIO_PORTE_CR_R |= 0xFF; // enable commiit to the 8 bins
			
		
		// PORT F initial
		SYSCTL_RCGCGPIO_R |= 0x20; // port B select
	//delay = 1;
	while((SYSCTL_PRGPIO_R & 0x20) == 0){}; //delay until the portF is granted
	GPIO_PORTF_AFSEL_R = 0; // alternate function select to GPIO
	GPIO_PORTF_PCTL_R = 0;
	GPIO_PORTF_AMSEL_R = 0; // no analog
	GPIO_PORTF_DIR_R  = 0x0E; // LED as output
	GPIO_PORTF_DEN_R = 0x1F; // all pins are digital output 
	GPIO_PORTF_PUR_R = 0x11; // no pull up resistors are needed
	GPIO_PORTF_LOCK_R = 0x4C4F434B; //  lock portf
	GPIO_PORTF_CR_R |= 0x1F; // enable commiit to the 8 bins
}



/// UART0 INITILIZATION 
void UART_Init(void){
 
	SYSCTL_RCGCUART_R |= 0x0001; // activate UART0
  SYSCTL_RCGCGPIO_R |= 0x0001; // activate port A
  UART0_CTL_R &= ~0x0001; // disable UART
  UART0_IBRD_R = 104; // IBRD=int(80000000/(16*9600)) = int(520.8333)
  UART0_FBRD_R = 11; // FBRD = int(0.8333 * 64 + 0.5)
  UART0_LCRH_R = 0x0070; // 8-bit word length, enable FIFO 001110000
  UART0_CTL_R = 0x0301; // enable RXE, TXE and UART 001100000001
	GPIO_PORTA_AFSEL_R |= 0x03; // enable alt function PA0 ,PA1
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011; 
  GPIO_PORTA_DEN_R |= 0x03; // enable digital I/O on PA0, PA1
  GPIO_PORTA_AMSEL_R &= ~0x03; // disable analog function on PA0, PA1


}



/// UART1 INITILIZATION 
void UART1_Init(void){
 
	SYSCTL_RCGCUART_R |= 0x00000002; // activate UART1
  SYSCTL_RCGCGPIO_R |= 0x00000002; // activate port B
  UART1_CTL_R &= ~0x00000001; // disable UART
  UART1_IBRD_R = 104; // IBRD=int(80000000/(16*9600)) = int(520.8333)
  UART1_FBRD_R = 11; // FBRD = int(0.8333 * 64 + 0.5)
  UART1_LCRH_R = 0x0070; // 8-bit word length, enable FIFO 001110000
  UART1_CTL_R = 0x0301; // enable RXE, TXE and UART 001100000001
	GPIO_PORTB_AFSEL_R |= 0x03; // enable alt function PB0 ,PB1
GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011; 
GPIO_PORTB_DEN_R |= 0x03; // enable digital I/O on PA0, PA1
GPIO_PORTB_AMSEL_R &= ~0x03; // disable analog function on PA0, PA1


}



uint8_t UART0_Available(void){
	return ((UART0_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART0_Read(void){
	while(UART0_Available() != 1);
	return (uint8_t)(UART0_DR_R&0xFF);
}

void UART0_Write(uint8_t data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
// check UART1_Available
uint8_t UART1_Available(void){
	return ((UART1_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

// check UART1_Read
uint8_t UART1_Read(void){
	while(UART1_Available() != 1);
	return (uint8_t)(UART1_DR_R&0xFF);
}




