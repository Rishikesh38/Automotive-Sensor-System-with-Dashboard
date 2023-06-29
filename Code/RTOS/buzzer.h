/**
 ​ ​*​ ​@file​ ​buzzer.h
 ​ ​*​ ​@brief​ ​This file is the header file for buzzer module. It has functions prototype
  * of all the functions used in the buzzer module. This header file acts as file to expose the buzzer
  * interface to the rest of the project.
 ​ *
  *
 ​ * ​@author​ ​Rishikesh Goud Sundaragiri
 ​ ​*​ ​@date​ April 25 2023
 ​ ​*/

#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "main.h"

/**
 ​ ​*​ ​@brief​ This function turns on the buzzer by setting the corresponding pin to HIGH. 
  * The pin is assumed to be connected to GPIOA Pin 5.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void turn_on_buzzer();

/**
 ​ ​*​ ​@brief​ This function turns off the buzzer by clearing the corresponding bit in the GPIOA_BSRR register. 
  * Specifically, it uses a bit set/reset register (BSRR) to set the 6th bit (corresponding to PA5) to 1, 
  * which clears the output bit in the GPIOA_ODR register, thereby turning off the buzzer.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void turn_off_buzzer();

#endif /* __BUZZER_H__ */
