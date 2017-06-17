/*
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
*/
#include "Arduino.h"

HardwareSerial::HardwareSerial(UART_TypeDef *pUartConsole) {
	UartConsole = pUartConsole;
}

void HardwareSerial::begin(uint32_t baud)
{
	begin(baud, SERIAL_8N1);
}

void HardwareSerial::begin(uint32_t baud,uint32_t config)
{
	u8 UART_DRV_DATABITS = (u8) ((config >> 8) & 0xf);
	u8 UART_DRV_STOPBITS = (u8) (config & 0xf);
	u8 UART_DRV_PARITY = (u8) ((config >> 4) & 0xf);
	UART_DATA_t tUartData ={baud, \
		UART_DRV_DATABITS,UART_DRV_STOPBITS,UART_DRV_PARITY};
	UART_Init(UartConsole,&tUartData);
	UART_IsrInit(UartConsole);
}

void HardwareSerial::end()
{
	UART_DeInit(UartConsole);
}

int HardwareSerial::available(void)
{
  return uartDataCheck();
}

int HardwareSerial::read(void)
{
	if(available())
		return uartReadByte();
	return -1;
}

size_t HardwareSerial::write(uint8_t c)
{
	while(UartConsole->IIR & UART_IIR_TX_FULL);
	UartConsole->THR = c;
	return 1;
}
int HardwareSerial::peek(void)
{
	if(available())
		return uartPeekByte();
	return -1;
}
void HardwareSerial::flush()
{
    uartFlush(UartConsole);
}
