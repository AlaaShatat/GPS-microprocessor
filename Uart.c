#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "math.h"



void UART0_Init(){
 
	SYSCTL_RCGCUART_R |= 0x00000001; // activate UART0
  SYSCTL_RCGCGPIO_R |= 0x00000001; // activate port A
  UART0_CTL_R &= ~0x00000001; // disable UART
  UART0_IBRD_R = 104; // IBRD=int(80000000/(16*9600)) = int(520.8333)
  UART0_FBRD_R = 11; // FBRD = int(0.8333 * 64 + 0.5)
  UART0_LCRH_R = 0x0070; // 8-bit word length, enable FIFO 001110000
  UART0_CTL_R = 0x0301; // enable RXE, TXE and UART 001100000001
	GPIO_PORTA_AFSEL_R |= 0x03; // enable alt function PA0 ,PA1
GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011; 
GPIO_PORTA_DEN_R |= 0x03; // enable digital I/O on PA0, PA1
GPIO_PORTA_AMSEL_R &= ~0x03; // disable analog function on PA0, PA1


}


void UART1_Init(){
 
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

uint32_t in ; 
uint32_t out ; 


	int main()
		{
			 
			UART0_Init();
  	UART1_Init();
  
		while( 1 ){
			
	
			
		
	
		in = UART0_Read();
		out = in ;
		UART0_Write(out);
		}
		}