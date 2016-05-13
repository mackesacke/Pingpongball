/*
 * lockLED.h
 *
 * Created: 2015-12-16 19:54:17
 * Author: Daniel Petersén and Marcus Sandberg
 */ 

#ifndef Matlab_H_
#define Matlab_H_
#define TASK_STACK_MATLAB_SIZE			(2048/sizeof(portSTACK_TYPE))
#define TASK_MATLAB_STACK_PRIORITY		(1)

void task_Matlab(void *pvParameters);
void sendParameters(uint16_t errorValue, uint16_t currentValue);
#endif /* Matlab_H_ */