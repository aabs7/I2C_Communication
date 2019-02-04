/*
 * I2C Communication (Slave).cpp
 *
 * Created: 6/8/2018 10:58:21 AM
 * Author : Prakash Chaudhary
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TWI.h"
#include "uart.h"

int main(void)
{
	uint8_t buffer[10];
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
	I2C_Initialize();
	I2C_Assign_address(0x20);
	sei();
	/* Replace with your application code */
	while (1)
	{
		I2C_Slave_match();
		I2C_Read_byte_array(buffer,10);
		uart0_putint(buffer[0]);
		uart0_putc(' ');
		for (int i =1;i<10;i++)
		{
			if (buffer[i] != buffer[i-1])
			{
				uart0_putint(buffer[i]);
				uart0_putc(' ');
			}
		}
		uart0_puts("\r\n");
		for (int i =0;i<10;i++)
		{
			buffer[i] = 0;
		}
	}
}