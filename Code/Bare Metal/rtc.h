/**
 ​ ​*​ ​@file​ ​rtc.h
 ​ ​*​ ​@brief​ ​This file is the header file for RTC module. It has functions prototype
  * of all the functions used in the RTC module. This header file acts as file to expose the RTC
  * interface to the rest of the project.
 ​ *
  *
 ​ * ​@author​ ​Rishikesh Goud Sundaragiri
 ​ ​*​ ​@date​ April 15 2023
 ​ ​*/


#ifndef __RTC_H__
#define __RTC_H__

#include "main.h"

/**
 ​ ​*​ ​@brief​ This code initializes the RTC (Real Time Clock) module by configuring clock source,
  *  prescalar, date and time values, and enabling the clock. It also unlocks and relocks the write protect 
  * feature for the RTC module to allow write access to its registers during initialization.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void rtc_init();

/**
 ​ ​*​ ​@brief​ The function RTC_calculate_time extracts the hours, minutes, and seconds from 
  * the RTC_TR register of the RTC module and calculates their respective values in decimal format. 
  * The calculated values are stored in the global variables Hours, Minutes, and Seconds.
 ​ ​*
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void RTC_calculate_time(void);

/**
 ​ ​*​ ​@brief​ This function extracts the date from the RTC_DR (Date Register) of the RTC (Real-Time Clock) 
  * module and calculates the day, month, and year. It stores the day, month, and year values in the global 
  * variables Day, Month, and Year, respectively.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void RTC_calculate_date(void);

/**
 ​ ​*​ ​@brief​ This function returns the value of the variable Minutes, 
  * which is likely storing the current minute value obtained from the RTC (Real-Time Clock) module in the microcontroller.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ uint8_t will return the minutes 
 ​ ​*/
uint8_t get_minutes();

/**
 ​ ​*​ ​@brief​ This function returns the value of the variable hours, 
  * which is likely storing the current hours value obtained from the RTC (Real-Time Clock) module in the microcontroller.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ uint8_t will return the hours 
 ​ ​*/
uint8_t get_hours();

/**
 ​ ​*​ ​@brief​ This function returns the value of the variable year, 
  * which is likely storing the current years value obtained from the RTC (Real-Time Clock) module in the microcontroller.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ uint8_t will return the year 
 ​ ​*/
uint8_t get_year();

/**
 ​ ​*​ ​@brief​ This function returns the value of the variable month, 
  * which is likely storing the current month value obtained from the RTC (Real-Time Clock) module in the microcontroller.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ uint8_t will return the month 
 ​ ​*/
uint8_t get_month();

/**
 ​ ​*​ ​@brief​ This function returns the value of the variable day, 
  * which is likely storing the current day value obtained from the RTC (Real-Time Clock) module in the microcontroller.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ uint8_t will return the day 
 ​ ​*/
uint8_t get_day();

#endif /*__RTC_H__*/
