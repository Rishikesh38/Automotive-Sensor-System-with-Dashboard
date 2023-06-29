/**
 ​ ​*​ ​@file​ ​adc.c
 ​ ​*​ ​@brief​ ​This file has implementation of ADC module using interrupt. It will initialise ADC
  * and read ADC values using interrupt handler. Then it will calculate the values of temperature using a lookup
  * table and a generic formula. This file also has a function to get the temperature value and return it.
 ​ *
  *
 ​ * ​@author​ ​Rishikesh Goud Sundaragiri
 ​ ​*​ ​@date​ May 1 2023
 ​ ​*/

#include "adc.h"

/*
 * Preprocessor macros
 */
#define ADC_CLOCK 8
#define GPIOA_CLOCK 0
#define PA0 0
#define ADC_RESOLUTION 24
#define ANALOG_MODE 3
#define ADC_ENABLE 0
#define INTERRUPT_EOC 5
#define EOC 1
#define START_CONVERSION 30
#define PRIORITY 2
#define MULTIPLY_FACTOR 3
#define DIVISION_FACTOR 1023
#define DIVISION_SCALE 10000
#define TEMPERATURE_1 2
#define TEMPERATURE_2 3
#define TEMPERATURE_3 4
#define TEMPERATURE_4 5
#define TEMPERATURE_5 6
#define TEMPERATURE_6 7
#define TEMPERATURE_7 8
#define TEMPERATURE_8 9
#define TEMPERATURE_9 10
#define TEMPERATURE_10 11
#define TEMPERATURE_11 12
#define TEMPERATURE_12 13
#define TEMPERATURE_13 14
#define TEMPERATURE_14 15
#define TEMPERATURE_15 17
#define TEMPERATURE_16 19
#define TEMPERATURE_17 20
#define TEMPERATURE_18 22
#define TEMPERATURE_19 23
#define TEMPERATURE_20 25
#define TEMPERATURE_21 28
#define TEMPERATURE_22 33
#define TEMPERATURE_23 35
#define TEMPERATURE_24 40
#define TEMPERATURE_25 45
#define TEMPERATURE_26 50
#define TEMPERATURE_27 55
#define TEMPERATURE_28 75
#define TEMPERATURE_29 95

/*
 * Initialize the static global variable to 0
 */
float static volatile adc_value = 0;
static int temperature = 0;

const int lookupTable[] = {
	1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000,
	11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000,
	21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000};

void adc_init(void)
{
	RCC->AHB1ENR |= MASK(ENABLE_, GPIOA_CLOCK); // Enable clock source for PORT A
	GPIOA->MODER |= MASK(ANALOG_MODE, PA0);		// PA0 pin is Analog Mode
	RCC->APB2ENR |= MASK(ENABLE_, ADC_CLOCK);	// Enable clock source for ADC1
	ADC1->CR1 |= MASK(ENABLE_, ADC_RESOLUTION); //  set ADC resolution to 10bit i.e. max is 1023
	ADC1->CR2 &= ~MASK(ENABLE_, ADC_ENABLE);	//  ADC disable
	ADC1->SQR3 |= 0;							// Enable ADC 0th Channel
	ADC1->CR1 |= MASK(ENABLE_, INTERRUPT_EOC);	// end of conversion interrupt
	ADC1->CR2 |= MASK(ENABLE_, ADC_ENABLE);		// ADC ON
	NVIC_EnableIRQ(ADC_IRQn);
	NVIC_SetPriority(ADC_IRQn, PRIORITY);
	ADC1->CR2 |= MASK(ENABLE_, START_CONVERSION); // Start  ADC conversion
}

void ADC_IRQHandler()
{
	// store the DR register contents in a variable,
	// no need to clear the EOC as its cleared when you read the DR register
	if (ADC1->SR & MASK(ENABLE_, EOC))
	{
		adc_value = ADC1->DR;
	}
}

void calculate_temperature()
{
	float analog_voltage = 0;
	int ntc_resistance = 0;
	analog_voltage = (MULTIPLY_FACTOR * adc_value) / DIVISION_FACTOR;							// gets the analog voltage corresponding to adc output value
	ntc_resistance = ((-analog_voltage * DIVISION_SCALE) / (analog_voltage - MULTIPLY_FACTOR)); // 3 is vcc, 10k is nominal resistance
	if (ntc_resistance == lookupTable[28])
	{
		temperature = TEMPERATURE_1;
	}
	else if (ntc_resistance < lookupTable[28] && ntc_resistance >= lookupTable[27])
	{
		temperature = TEMPERATURE_2;
	}
	else if (ntc_resistance < lookupTable[27] && ntc_resistance >= lookupTable[26])
	{
		temperature = TEMPERATURE_3;
	}
	else if (ntc_resistance < lookupTable[26] && ntc_resistance >= lookupTable[25])
	{
		temperature = TEMPERATURE_4;
	}
	else if (ntc_resistance < lookupTable[25] && ntc_resistance >= lookupTable[24])
	{
		temperature = TEMPERATURE_5;
	}
	else if (ntc_resistance < lookupTable[24] && ntc_resistance >= lookupTable[23])
	{
		temperature = TEMPERATURE_6;
	}
	else if (ntc_resistance < lookupTable[23] && ntc_resistance >= lookupTable[22])
	{
		temperature = TEMPERATURE_7;
	}
	else if (ntc_resistance < lookupTable[22] && ntc_resistance >= lookupTable[21])
	{
		temperature = TEMPERATURE_8;
	}
	else if (ntc_resistance < lookupTable[21] && ntc_resistance >= lookupTable[20])
	{
		temperature = TEMPERATURE_9;
	}
	else if (ntc_resistance < lookupTable[20] && ntc_resistance >= lookupTable[19])
	{
		temperature = TEMPERATURE_10;
	}
	else if (ntc_resistance < lookupTable[19] && ntc_resistance >= lookupTable[18])
	{
		temperature = TEMPERATURE_11;
	}
	else if (ntc_resistance < lookupTable[18] && ntc_resistance >= lookupTable[17])
	{
		temperature = TEMPERATURE_12;
	}
	else if (ntc_resistance < lookupTable[17] && ntc_resistance >= lookupTable[16])
	{
		temperature = TEMPERATURE_13;
	}
	else if (ntc_resistance < lookupTable[16] && ntc_resistance >= lookupTable[15])
	{
		temperature = TEMPERATURE_14;
	}
	else if (ntc_resistance < lookupTable[15] && ntc_resistance >= lookupTable[14])
	{
		temperature = TEMPERATURE_15;
	}
	else if (ntc_resistance < lookupTable[14] && ntc_resistance >= lookupTable[13])
	{
		temperature = TEMPERATURE_16;
	}
	else if (ntc_resistance < lookupTable[13] && ntc_resistance >= lookupTable[12])
	{
		temperature = TEMPERATURE_17;
	}
	else if (ntc_resistance < lookupTable[12] && ntc_resistance >= lookupTable[11])
	{
		temperature = TEMPERATURE_18;
	}
	else if (ntc_resistance < lookupTable[11] && ntc_resistance >= lookupTable[10])
	{
		temperature = TEMPERATURE_19;
	}
	else if (ntc_resistance < lookupTable[10] && ntc_resistance >= lookupTable[9])
	{
		temperature = TEMPERATURE_20;
	}
	else if (ntc_resistance < lookupTable[9] && ntc_resistance >= lookupTable[8])
	{
		temperature = TEMPERATURE_21;
	}
	else if (ntc_resistance < lookupTable[8] && ntc_resistance >= lookupTable[7])
	{
		temperature = TEMPERATURE_22;
	}
	else if (ntc_resistance < lookupTable[7] && ntc_resistance >= lookupTable[6])
	{
		temperature = TEMPERATURE_23;
	}
	else if (ntc_resistance < lookupTable[6] && ntc_resistance >= lookupTable[5])
	{
		temperature = TEMPERATURE_24;
	}
	else if (ntc_resistance < lookupTable[5] && ntc_resistance >= lookupTable[4])
	{
		temperature = TEMPERATURE_25;
	}
	else if (ntc_resistance < lookupTable[4] && ntc_resistance >= lookupTable[3])
	{
		temperature = TEMPERATURE_26;
	}

	else if (ntc_resistance < lookupTable[3] && ntc_resistance >= lookupTable[2])
	{
		temperature = TEMPERATURE_27;
	}
	else if (ntc_resistance < lookupTable[2] && ntc_resistance >= lookupTable[1])
	{
		temperature = TEMPERATURE_28;
	}
	else if (ntc_resistance < lookupTable[1] && ntc_resistance >= lookupTable[0])
	{
		temperature = TEMPERATURE_29;
	}
}

int get_temp(void)
{
	return temperature;
}
