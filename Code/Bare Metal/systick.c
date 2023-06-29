/**
 ​ ​*​ ​@file​ ​systick.c
 ​ ​*​ ​@brief​ ​This file has implementation of systick module using inbuilt systick. It will initialise systick
  * to provide a delay of 1ms. It has a function by which user can set desired milli sec delay. 
 ​ *
  *
 ​ * ​@author​ Suraj Ajjampur
 ​ ​*​ ​@date​ April 30 2023
 ​ ​*/

#include "systick.h"

#define ALTERNATE_CLOCK 30000000/16
#define ONE_MILLISEC	1000
#define PRIORITY 3

/******** GLOBAL VARIABLES ***********/
static int Systick_count=0;
int timeout;
int msec_since_startup;

void Init_Systick(void){
	SysTick->LOAD = (ALTERNATE_CLOCK/ONE_MILLISEC);	//Set reload to get 1ms interrupts
	NVIC_SetPriority(SysTick_IRQn, PRIORITY);			//Set interrupt priority
	SysTick->VAL = 0;							//Force load of reload value
	SysTick->CTRL = SysTick_CTRL_TICKINT_Msk | 	//Enable interrupt,alt.clocksource
					SysTick_CTRL_ENABLE_Msk;	//Enable SysTick timer
	msec_since_startup = 0;
}

void SysTick_Handler(void){
	Systick_count++;
	msec_since_startup ++;
}

void Delay(volatile float millisecounds) {
timeout=0;
Systick_count=0; // Reset Systick count
  while (Systick_count<millisecounds) {
	;
  }
  timeout=1; //Set timeout flag to 1
}

//Getter function for timeout flag
int get_timeout_flag(void) {
	return timeout; }

//Start the Systick Count
void Start_Systick_Count(void){
	Systick_count=0;
}
//Stop the Systick Count
int get_Systick_Count(void){
	return Systick_count;
}
