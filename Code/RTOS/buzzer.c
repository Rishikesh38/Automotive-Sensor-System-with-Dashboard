/**
 ​ ​*​ ​@file​ ​buzzer.c
 ​ ​*​ ​@brief​ ​This file has implementation of buzzer module using a gpio pin. It will
  * turn on and turn off the buzzer.
 ​ *
  *
 ​ * ​@author​ ​Rishikesh Goud Sundaragiri
 ​ ​*​ ​@date​ April 25 2023
 ​ ​*/

#include "buzzer.h"

/*
 * Preprocessor macros
 */
#define PA5_SET 5
#define PA5_CLEAR 21

void turn_on_buzzer()
{
	GPIOA->BSRR |= MASK(ENABLE_, PA5_SET); //Set the buzzer
}

void turn_off_buzzer()
{
	GPIOA->BSRR |= MASK(ENABLE_, PA5_CLEAR); //Clear the buzzer
}
