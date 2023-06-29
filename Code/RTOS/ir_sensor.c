/**
 ​ ​*​ ​@file​ ​ir_sensor.c
 ​ ​*​ ​@brief​ ​This file is the implementation IR module. It has functions prototype
  * of all the functions used in the IR module. This file has a lookup table for
  * different animations, initialisation of GPIO's for IR sensor and the IR sensor
  * detection logic to check which side the vehicle approched. And functions to
  * return the status of IR sensors.
 ​ *
  *
 ​ * ​@author​ ​Rishikesh Goud Sundaragiri
 ​ ​*​ ​@date​ April 20 2023
 ​ ​*/

#include "ir_sensor.h"

/*
 * Preprocessor macros
 */
#define GPIOA_EN 0
#define PA7_MODER 14
#define PA2_MODER 4
#define PA7 7
#define PA2 2
#define INPUT_MODE 3
#define PUPD_PA7 15
#define PUPD_PA2 5
#define PA5 10
#define GPIOA_EN 0
#define PA5_SET 5
#define PA5_CLEAR 21

static bool vehicle_leftside = false;
static bool vehicle_rightside = false;
static bool vechile_bothside = false;

void ir_init()
{
	RCC->AHB1ENR |= MASK(ENABLE_, GPIOA_EN);		// Enable the Clock for GPIO A
	GPIOA->MODER &= ~(MASK(INPUT_MODE, PA7_MODER)); // Set the mode to GPIO Input for PA7
	GPIOA->PUPDR |= MASK(ENABLE_, PUPD_PA7);		// Configure a Pull down resistor to PA7
	GPIOA->MODER &= ~(MASK(INPUT_MODE, PA2_MODER)); // Set the mode to GPIO Input for PA2
	GPIOA->PUPDR |= MASK(ENABLE_, PUPD_PA2);		// Configure a Pull down resistor to PA2
	GPIOA->MODER &= ~(MASK(INPUT_MODE, PA5));		// Set the mode to GPIO Input for PA7
	GPIOA->MODER |= MASK(ENABLE_, PA5);				// Set output mode to GPIO5 for buzzer
	GPIOA->OTYPER &= ~MASK(ENABLE_, PA5_SET);		// output type register push - pull
	GPIOA->PUPDR |= MASK(ENABLE_, PA5);				// pull up for buzzer
}

void check_ir_sensor()
{
	if(GPIOA->IDR & MASK(ENABLE_, PA7) && (!(GPIOA->IDR & MASK(ENABLE_, PA2))))
	{
		Start_Timer(); // if the left side IR sensor is detecting an object but not the right side, start the timer
		vehicle_leftside = true; // set the vehicle_leftside flag to true
	}
	else
	{
		vehicle_leftside = false; // if the left side IR sensor is not detecting any object, set the vehicle_leftside flag to false
	}
	if(GPIOA->IDR & MASK(ENABLE_, PA2) && (!(GPIOA->IDR & MASK(ENABLE_, PA7))))
	{
		vehicle_rightside = true; // if the right side IR sensor is detecting an object but not the left side, set the vehicle_rightside flag to true
	}
	else
	{
		vehicle_rightside = false; // if the right side IR sensor is not detecting any object, set the vehicle_rightside flag to false
	}
	if(GPIOA->IDR & MASK(ENABLE_, PA7) && GPIOA->IDR & MASK(ENABLE_, PA2))
	{
		vechile_bothside = true; // if both the left and right side IR sensors are detecting an object, set the vehicle_bothside flag to true
	}
	else
	{
		vechile_bothside = false; // if neither left nor right side IR sensors are detecting any object, set the vehicle_bothside flag to false
	}
}


bool return_right_status()
{
	return vehicle_rightside;
}

bool return_left_status()
{
	return vehicle_leftside;
}

bool return_both_status()
{
	return vechile_bothside;
}
