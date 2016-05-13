/*
 * codeLock.c
 *
 * Created: 2015-12-16 14:10:22
 * Author: Daniel Petersén and Marcus Sandberg
 *
 * Task for regulating controll signal via PID-regulation.
 *
 */ 
#include <asf.h>
#include "matlab.h"
#include "DAC.h"
#include "adcFunctions.h"
#include <inttypes.h>

//-------------------------------------------------------------
// Initialize variables
//-------------------------------------------------------------

static uint16_t target = 0;
static uint16_t Kp = 0;
static uint16_t Ti = 0;
static uint16_t Td = 0;
static uint16_t dT = 0;

static uint32_t distance, calculate_distance;
static uint32_t u, e;

//-------------------------------------------------------------
// Define volt/distance intervalls.
//-------------------------------------------------------------

#define distance5 0
#define distance10 0
#define distance15 0
#define distance20 0
#define distance25 0
#define distance30 0
#define distance35 0
#define distance40 0
#define distance45 0
#define distance50 0
#define distance55 0
#define distance60 0

void task_PID(void *pvParameters) 
{
	const portTickType xTimeIncrement = 100;
	
	//distance = calculateDistance();
	e = target - distance;
	
	u = Kp*e;
	dacc_write_conversion_data(DACC, u);
	sendParameters(e, distance);
	vTaskDelay(50);					// 50 millisecond delay
}

int calculateDistance()
{
	calculate_distance = analogRead(1);
	/*
	Calculate distance from analog input.
	*/
	
	
}

void setParameters(uint16_t setTarget, uint16_t setKp, uint16_t setTi, uint16_t setTd, uint16_t setdT)
{
	target = setTarget;
	Kp = setKp;
	Ti = setTi;
	Td = setTd;
	dT = setdT;
}