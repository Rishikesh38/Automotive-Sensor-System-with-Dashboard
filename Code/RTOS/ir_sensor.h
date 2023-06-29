/**
 ​ ​*​ ​@file​ ​ir_sensor.h
 ​ ​*​ ​@brief​ ​This file is the header file for IR module. It has functions prototype
  * of all the functions used in the IR module. This header file acts as file to expose the IR
  * interface to the rest of the project.
 ​ *
  *
 ​ * ​@author​ ​Rishikesh Goud Sundaragiri
 ​ ​*​ ​@date​ April 20 2023
 ​ ​*/

#ifndef __IR_SENSOR__
#define __IR_SENSOR__

/*
 * Headers required in this module
 */
#include "main.h"
#include "ssd1306.h"
#include "stdbool.h"
#include "timer.h"

/**
 ​ ​*​ ​@brief​ The  function is initializing some GPIO pins on the STM32 microcontroller.
 ​ ​* This code sets up three GPIO pins for input and output operations,
  * with appropriate pull-up and pull-down resistors as required for two IR sensors and a buzzer
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void ir_init();

/**
 ​ ​*​ ​@brief​ function checks the status of the IR sensors and determines if a vehicle is present on either side of the system.
  * If a vehicle is detected on one side, the system starts a timer and activates the buzzer and OLED display to display an alert.
  * If a vehicle is detected on both sides, the system activates the buzzer and OLED display to display a different alert.
  * The function also includes logic to clear the display and reset the timer once the vehicle has passed the sensors.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ None
 ​ ​*/
void check_ir_sensor();

/**
 ​ ​*​ ​@brief​ This function returns the boolean value of the variable vehicle_rightside.
  * It is used to check whether a vehicle has been detected on the right side of the sensor.
  * If the value is true, it means a vehicle is detected on the right side; otherwise, there is no vehicle detected on the right side.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ bool will return true or false depending on IR detection
 ​ ​*/
bool return_right_status();

/**
 ​ ​*​ ​@brief​ This is a function that returns the status of the left side vehicle detection.
  * It returns a boolean value true if a vehicle is detected on the left side and false
  * if no vehicle is detected on the left side.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ bool will return true or false depending on IR detection
 ​ ​*/
bool return_left_status();

/**
 ​ ​*​ ​@brief​ This function returns the status of whether a vehicle is detected on both sides of the parking spot.
  * It simply returns the value of the vechile_bothside variable, which is set to true if a vehicle is detected
   * on both the left and right sides of the parking spot. If there is no vehicle detected on both sides, it returns false.
  *
 ​ ​*​ ​@param​ None
 ​ ​*
 ​ ​*​ ​@return​ bool will return true or false depending on IR detection
 ​ ​*/
bool return_both_status();

#endif /* __IR_SENSOR__ */

