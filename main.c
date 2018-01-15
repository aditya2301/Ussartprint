/*
 * main.c
 *
 *  Created on: Apr 30, 2017
 *      Author: gc
 */

#include"uart.h"
extern uint8_t rxbyte;    //rxbyte as check for data to send
int main()
{
	//setup
	uart_init();           //initialize uart
	//LOOP


	while(1)
	{

		if(rxbyte=='O')         // 'O' to send a particular sequence
		{
			//uart_send('K');
			_delay_ms(1000);
			uart_send_string("Adi!");  // string to be sent in "___"
          // rxbyte=0;
		}
		//uart_send('K');
		_delay_ms(1000);
		//while(UCSR0A & (1<<TXC0)==0);
		//CLEAR THE FLAG
		//UCSR0A |=(1<<TXC0);
	}
}
