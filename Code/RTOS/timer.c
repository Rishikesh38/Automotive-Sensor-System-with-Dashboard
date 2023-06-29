/**
 ​ ​*​ ​@file​ ​timer.c
 ​ ​*​ ​@brief​ ​This file is used as timer module, it will be used to provide 
  * to provode delay or calculate time. In our case we use it to calculate
  * time for responce time.
  *
 ​ * ​@author​ Suraj Ajjampur
 ​ ​*​ ​@date​ April 25 2023
 ​ ​*/

#include "timer.h"

/*
 * Preprocessor macros
 */
#define PRESCALAR 				0x0001 //Value of 1
#define AUTO_RELOAD_REGISTER    0x1F3F //Value of 15,999 //0x3E7F
//Calculation - ARR = (timer_clock / (frequency * PSC)) - 1
#define TIM2_EN					0x01   //Set bits to enable timer 2
#define UPDATE_INTERRUPT_EN		0x01   //Update interrupt enable
#define CEN						0x01   //Counter Enable

/*
 * Initialize the static global variable to 0
 */
static int timer_2_counter = 0;


void BM_TIM2_Init(void){

	// Clock Enable
	RCC->APB1ENR |= TIM2_EN;
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	//Update interrupt enabled
	TIM2->DIER |= UPDATE_INTERRUPT_EN;

	// Update Event = TIM clk/((PSC+1)*(ARR+1))
	TIM2->PSC = PRESCALAR;
	TIM2->ARR = AUTO_RELOAD_REGISTER;

	//Enables a device specific interrupt in the NVIC interrupt controller for TIM2
	NVIC_EnableIRQ(TIM2_IRQn);

	//Turn On Timer
	//Setting Counter Enable Bit of Timer 2 control Register
	TIM2->CR1 |= CEN;
}


void TIM2_IRQHandler(void){

	// Clear TIM2 status register
	TIM2->SR &= ~(0x01);
	timer_2_counter++;
}

void Start_Timer(void){
	timer_2_counter = 0;
	//Restarts the counter
	TIM2->CR1 |= CEN;
}

// Gets the current timer count
int get_timer_Count(void){
	return timer_2_counter;
}
