/**
 ​ ​*​ ​@file​ ​adc.h
 ​ ​*​ ​@brief​ ​This file is the header file for ADC module. It has functions prototype
  * of all the functions used in the ADC module. This header file acts as file to expose the ADC
  * interface to the rest of the project.
 ​ *
  *
 ​ * ​@author​ ​Rishikesh Goud Sundaragiri
 ​ ​*​ ​@date​ April 20 2023
 ​ ​*/

#ifndef __ADC_H__
#define __ADC_H__

#include "main.h"

/**
 ​ ​*​ ​@brief​ The  function adc_init() initializes and configures the Analog-to-Digital Converter (ADC) module
  * in a microcontroller for single channel conversion. This function prepares the ADC module for reading the
  * analog voltage values from the selected channel and interrupts when the conversion is complete.
  * After initialization, the microcontroller can use the ADC to read the voltage from an analog sensor
  * or any other analog signal and convert it into a digital value for processing.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void adc_init(void);

/**
 ​ ​*​ ​@brief​ This code calculates the temperature based on an NTC (Negative Temperature Coefficient) thermistor's resistance.
 ​ ​* The function takes the value from an analog-to-digital converter (ADC), which is then used to calculate the analog voltage.
  * The resistance of the NTC thermistor is calculated using the analog voltage and known values for the voltage divider circuit (3V and 10kOhm).
  * The calculated NTC resistance is then compared to values in a lookup table to determine the corresponding temperature.
  * The function uses if-else statements to check the NTC resistance against the values in the lookup table in descending order.
  * If the resistance is within a certain range, the temperature value associated with that range is assigned to the temperature variable.
  * For example, if the NTC resistance is less than the value in lookupTable[28] and greater than or equal to the value in lookupTable[27],
  * the temperature variable is assigned a value of 3.
  * The final temperature value is stored in the temperature variable and can be used for further calculations or to display the temperature on a display, for example.
  * Note that the lookup table is not shown in the code snippet, but it contains the resistance values corresponding to different
  * temperatures for the particular NTC thermistor being used.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void calculate_temperature();

/**
 ​ ​*​ ​@brief​ The "get_temp" function returns the value of the "temperature" variable, which was set by the "calculate_temperature" function.
  * The "get_temp" function does not take any arguments and simply returns an integer value, which represents the temperature value calculated
  * by the "calculate_temperature" function.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ int returns the temperature value
 ​ ​*/
int get_temp(void);

#endif /* __ADC_H__ */
