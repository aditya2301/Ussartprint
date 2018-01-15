/*
 * uart.c
 *
 *  Created on: Apr 30, 2017
 *      Author: gc
 */
#include"uart.h"

uint8_t rxbyte=0;
ISR(USART0_RX_vect)  //interrupt service routine for received byte
{
	rxbyte=UDR0;
}
void uart_init()
{
	    UBRR0H=(uint8_t)(BPS>>8);       //usart baud rate registers
		UBRR0L=(uint8_t)(BPS);
		//tx  AND RX
		UCSR0B |= (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);   //enable rx and tx and rx interrupt
		UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01);      //set data as 8 bit with one stop bit
		sei();   //cli(); for clearing interrupt
}
void uart_send(uint8_t senddata) //sending data character by character
{
	while((UCSR0A & (1<<UDRE0))==0);      //wait till data register is free
      UDR0=senddata;        //write data to be sent
}
void uart_send_string(uint8_t *pstr)  //character array to sent entire string of data
{
	   while(*pstr!='\0')
	     uart_send(*pstr++);
	   uart_send('\r');  // carriage return
	   uart_send('\n');
	   rxbyte=0; // stop sending
}
/*uint8_t uart_receive()  //polling method
{
	//RECEIVE IN PROGRESS
			while(UCSR0A &(1<<RXC0)==0);
		//	uint8_t rxbyt=UDR0;
            return UDR0;
}*/

