/*
 * codeLock.h
 *
 * Created: 2015-12-16 13:53:49
 * Author: Daniel Petersén and Marcus Sandberg
 */

#ifndef PID_H_
#define PID_H_
#define TASK_STACK_PID_SIZE			(2048/sizeof(portSTACK_TYPE))
#define TASK_PID_STACK_PRIORITY		(2)
	
void task_PID(void *pvParameters);
void setParameters(uint16_t setTarget, uint16_t setKp, uint16_t setTi, uint16_t setTd, uint16_t setdT);
int calculateDistance(void);

#endif /* PID_H_ */