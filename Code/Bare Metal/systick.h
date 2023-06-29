/**
 ​ ​*​ ​@file​ ​systick.h
 ​ ​*​ ​@brief​ ​This file is the header file for systick module.It has functions prototype
  * of all the functions used in the systick module. This header file acts as file to expose the systick
  * interface to the rest of the project.
 ​ *
  *
 ​ * ​@author​ Suraj Ajjampur
 ​ ​*​ ​@date​ April 30 2023
 ​ ​*/

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "stm32f4xx.h"

/**
 ​ ​*​ ​@brief​ This function initializes the SysTick timer to generate interrupts every 1 millisecond 
  * using an alternate clock source. It sets the interrupt priority and enables the interrupt and the timer. 
  * The function also initializes a variable to keep track of the milliseconds since system startup.
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void Init_Systick(void);

/**
 ​ ​*​ ​@brief​ This function implements a blocking delay for the specified number of milliseconds using the SysTick timer. 
  * It first initializes two variables, timeout and Systick_count, and then enters a loop that runs until Systick_count 
  * reaches the specified number of milliseconds. Inside the loop, it does nothing (;), allowing the SysTick interrupt to 
  * increment Systick_count every millisecond. Once the delay is complete, it sets the timeout flag to 1.
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void Delay(volatile float time_del);


/** ​@brief​  This function is a simple getter function that returns the value of the global variable "timeout", 
  * which appears to be a flag indicating whether a timeout has occurred during a previous function call.
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ int will return the timeout flag
 ​ ​*/
int get_timeout_flag(void);

/** ​@brief​  The function get_Systick_Count returns the value of a global variable Systick_count, 
  * which is presumably incremented by a SysTick interrupt handler. The variable represents the number of milliseconds 
  * that have elapsed since the last reset of Systick_count. This function can be used to obtain the current value of 
  * Systick_count from other parts of the program.
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ int will return the systick count
 ​ ​*/
int get_Systick_Count(void);

/** ​@brief​  The Start_Systick_Count function initializes the Systick_count variable to zero, 
 * which is used to count the number of milliseconds passed since the start of the system.
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void Start_Systick_Count(void);

#endif /* INC_SYSTICK_H_ */
