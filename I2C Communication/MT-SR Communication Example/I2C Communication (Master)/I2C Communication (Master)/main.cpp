/*
 * I2C Communication (Master).cpp
 *
 * Created: 6/8/2018 10:48:28 AM
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
	uint8_t buffer[10]={21,22,23,24,25,26,27,28,29,30};
	uint8_t Func_err = 9;
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
	I2C_Initialize();
	sei();
	//i2c_init();    /* Replace with your application code */
	while (1)
	{
		I2C_Start(0x20);
		Func_err =I2C_Write_byte_array(buffer,10);
		
		I2C_Stop();
		uart0_putint(Func_err);
		uart0_putc(' ');
		//uart0_putc(_I2C_error_byte);
		uart0_puts("\r\n");
		_delay_ms(10);
		
	}
}


