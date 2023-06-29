/**
 ​ ​*​ ​@file​ ​timer.h
 ​ ​*​ ​@brief​ ​This file is the header file for timer module. It has functions prototype
  * of all the functions used in the timer module. This header file acts as file to expose the timer
  * interface to the rest of the project.
 ​ *
 ​ * ​@author​ Suraj Ajjampur
 ​ ​*​ ​@date​ April 25 2023
 ​ ​*/

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

/**
 ​ ​*​ ​@brief​ This function initializes and configures Timer 2 on a microcontroller. It enables the clock for Timer 2, 
  * sets up the prescaler and auto-reload registers to generate the desired update event frequency. 
  * It also enables the update interrupt and configures the NVIC to handle it. Finally, it turns on the Timer 2 counter.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void BM_TIM2_Init(void);

/**
 ​ ​*​ ​@brief​ This function resets the timer_2_counter variable to 0 and starts the timer 2 counter. 
  * The timer is started by setting the counter enable bit of the Timer 2 control register.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void Start_Timer(void);

/**
 ​ ​*​ ​@brief​ The function get_timer_Count returns the value of the global variable timer_2_counter. 
  * This variable is likely incremented by an interrupt service routine that is triggered by a timer, such as TIM2. 
  * Therefore, the value returned by this function represents the number of times the timer has expired since it was started.
 ​ ​*
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ int return the current timer count
 ​ ​*/
int get_timer_Count(void);


#endif /* INC_TIMER_H_ */
