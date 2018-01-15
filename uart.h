/*
 * uart.h
 *
 *  Created on: Apr 30, 2017
 *      Author: gc
 */
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#ifndef UART_H_
#define UART_H_
#define BR 9600
#define BPS ((F_CPU/(BR*16UL))-1)  // setting baud rate registers
void uart_init();
void uart_send(uint8_t senddata);
uint8_t uart_receive();
void uart_send_string(uint8_t *pstr);


#endif /* UART_H_ */
