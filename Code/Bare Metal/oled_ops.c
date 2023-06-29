/**
 ​ ​*​ ​@file​ ​oled_ops.c
 ​ ​*​ ​@brief​ ​This file has implementation of OLED module using I2C. It will print the time, date and temperature in
  * normal operation. This file will call functions from temperature module and rtc module to get the current
  * time, date and temperature. Then it will print them at respective address.
 ​ *
 ​ * ​@author​ Suraj Ajjampur
 ​ ​*​ ​@date​ April 25 2023
 ​ ​*/

#include "oled_ops.h"

/*
 * Preprocessor macros
 */
#define TIME_ROW 35
#define DATE_ROW 0
#define TEMP_ROW 0
#define START_CONVERSION 30
#define HOURS_TENS_POSITION 30
#define HOURS_ONES_POSITION 44
#define MIN_TENS_POSITION 72
#define MIN_ONES_POSITION 86
#define COLON_POSITION 58
#define DATE_COLUMN 0
#define TEMP_COLUMN 96
#define ASCII_CONVERT(x) x + 48
#define DIVISION_FACTOR 10

/*
 * Initialize the static global variable to 0 or '\0'
 */
static uint8_t prev_min_val = 0;
static uint8_t prev_hour_val = 0;
static char min_ones = '\0';
static char min_tens = '\0';
static char hours_ones = '\0';
static char hours_tens = '\0';
static uint8_t date_val = 0;
static uint8_t month_val = 0;
static uint8_t year_val = 0;
static char date_ones = '\0';
static char date_tens = '\0';
static char month_ones = '\0';
static char month_tens = '\0';
static char year_ones = '\0';
static char year_tens = '\0';
static uint8_t temp_val = 0;

static char temp_tens = '\0';
static char temp_ones = '\0';

static char date_string[] = {'0', '4', '/', '3', '0', '/', '2', '3', '\0'};
static char temp_string[] = {'2', '7', 'C', '\0'};

void Time_Update(void)
{
	// Set the cursor position to the colon in the time display
	SSD1306_GotoXY(COLON_POSITION, TIME_ROW);
	// Print a colon character using the 16x26 font
	SSD1306_Putc(':', &Font_16x26, 1);

	// Retrieve the current minutes value
	prev_min_val = get_minutes();
	// Calculate the ones and tens place digits for the minutes
	min_ones = (prev_min_val % DIVISION_FACTOR) + '0';
	min_tens = (prev_min_val / DIVISION_FACTOR) + '0';
	// Set the cursor position to the tens place digit of the minutes display
	SSD1306_GotoXY(MIN_TENS_POSITION, TIME_ROW);
	// Print the tens place digit using the 16x26 font
	SSD1306_Putc(min_tens, &Font_16x26, 1);
	// Set the cursor position to the ones place digit of the minutes display
	SSD1306_GotoXY(MIN_ONES_POSITION, TIME_ROW);
	// Print the ones place digit using the 16x26 font
	SSD1306_Putc(min_ones, &Font_16x26, 1);

	// Retrieve the current hours value
	prev_hour_val = get_hours();
	// Calculate the ones and tens place digits for the hours
	hours_ones = (prev_hour_val % DIVISION_FACTOR) + '0';
	hours_tens = (prev_hour_val / DIVISION_FACTOR) + '0';
	// Set the cursor position to the tens place digit of the hours display
	SSD1306_GotoXY(HOURS_TENS_POSITION, TIME_ROW);
	// Print the tens place digit using the 16x26 font
	SSD1306_Putc(hours_tens, &Font_16x26, 1);
	// Set the cursor position to the ones place digit of the hours display
	SSD1306_GotoXY(HOURS_ONES_POSITION, TIME_ROW);
	// Print the ones place digit using the 16x26 font
	SSD1306_Putc(hours_ones, &Font_16x26, 1);

	// Retrieve the current month value
	month_val = get_month();
	// Calculate the tens and ones place digits for the month
	month_tens = (month_val / DIVISION_FACTOR) + '0';
	date_string[0] = month_tens;
	month_ones = (month_val % DIVISION_FACTOR) + '0';
	date_string[1] = month_ones;
	// Retrieve the current day value
	date_val = get_day();
	// Calculate the tens and ones place digits for the day
	date_tens = (date_val / DIVISION_FACTOR) + '0';
	date_string[3] = date_tens;
	date_ones = (date_val % DIVISION_FACTOR) + '0';
	date_string[4] = date_ones;
	// Retrieve the current year value
	year_val = get_year();
	// Calculate the tens and ones place digits for the year
	year_tens = (year_val / DIVISION_FACTOR) + '0';
	date_string[6] = year_tens;
	year_ones = (year_val % DIVISION_FACTOR) + '0';
	date_string[7] = year_ones;
	// Set the cursor position to the date display
	SSD1306_GotoXY(DATE_COLUMN, DATE_ROW);
	// Print the date string using the 7x10 font
	SSD1306_GotoXY(DATE_COLUMN, DATE_ROW);
	SSD1306_Puts(date_string, &Font_7x10, 1);
	temp_val = get_temp();
	temp_tens = (temp_val / DIVISION_FACTOR) + '0';
	temp_string[0] = temp_tens;
	temp_ones = (temp_val % DIVISION_FACTOR) + '0';
	temp_string[1] = temp_ones;
	SSD1306_GotoXY(TEMP_COLUMN, TEMP_ROW);
	SSD1306_Puts(temp_string, &Font_7x10, 1);
	SSD1306_UpdateScreen();
	ADC1->CR2 |= MASK(ENABLE_, START_CONVERSION); // Start the next conversion
}
