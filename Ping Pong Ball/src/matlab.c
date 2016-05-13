/*
 * lockLED.c
 *
 * Created: 2015-12-16 19:53:42
 * Author: Daniel Petersén and Marcus Sandberg
 */ 
#include <asf.h>
#include "matlab.h"
#include "PID.h"
#include "io_uart.h"
#define com_target 11
#define com_Kp 22
#define com_Ti 33
#define com_Td 44
#define com_dT 55
#define com_errorValue 66
#define com_currentValue 77

static uint16_t target;
static uint16_t Kp;
static uint16_t Ti;
static uint16_t Td;
static uint16_t dT;
static uint16_t received;

void task_Matlab(void *pvParameters)
{
    portTickType xLastWakeTime;
    const portTickType xTimeIncrement = 100;
    xLastWakeTime = xTaskGetTickCount(); /* Initialise the xLastWakeTime variable with the current time. */
    while (1) 
	{
		//Recieve value from matlab via serial communication.
		received = (uint16_t)uart_receive_char();
		
		//Controll information recieved.
		if(received == com_target)
		{
			target = (uint16_t)uart_receive_char();
		}else if(received == com_Kp)
		{
			Kp = (uint16_t)uart_receive_char();
		}else if(received == com_Ti)
		{
			Ti = (uint16_t)uart_receive_char();
		}else if(received == com_Td)
		{
			Td = (uint16_t)uart_receive_char();
		}else if(received == com_dT)
		{
			dT = (uint16_t)uart_receive_char();
		}
		setParameters(target, Kp, Ti, Td, dT);
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement); /* Wait for the next cycle. */
    }
}

void sendParameters(uint16_t errorValue, uint16_t currentValue)
{
	fprintf("%d\n", com_errorValue);
	fprintf("%d\n", errorValue);
	fprintf("%d\n", com_currentValue);
	fprintf("%d\n", currentValue);
}


