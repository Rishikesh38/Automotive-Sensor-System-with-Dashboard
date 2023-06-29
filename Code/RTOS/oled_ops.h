/**
 ​ ​*​ ​@file​ ​oled_ops.h
 ​ ​*​ ​@brief​ ​This file is the header file for OLED module. It has functions prototype
  * of all the function used in the OLED module. This header file acts as file to expose the OLED
  * interface to the rest of the project.
 ​ *
  *
 ​ * ​@author​ Suraj Ajjampur
 ​ ​*​ ​@date​ April 25 2023
 ​ ​*/
#ifndef INC_OLED_OPS_H_
#define INC_OLED_OPS_H_

#include "ssd1306.h"
#include "fonts.h"
#include "rtc.h"
#include "adc.h"
#include "main.h"

/**
 ​ ​*​ ​@brief​ The function Time_Update updates the time, date, and temperature displayed on an SSD1306 OLED display.
  *  It retrieves the current time, date, and temperature values, calculates the ones and tens place digits for each value,
  * and prints them to the appropriate positions on the display using different font sizes. It also starts a new ADC conversion to update the temperature value.
  * 
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void Time_Update(void);

#endif /* INC_OLED_OPS_H_ */
