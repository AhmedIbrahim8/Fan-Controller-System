/*[FILE NAME]   : lm35_sensor.h
 *[AUTHOR]      : AHMED IBRAHIM
 *[DATE CREATED]: OCT 9, 2021
 *[DESCRIPTION] : this file contain the header file of the lm35 sensor
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include"std_types.h"

/*Sensor channel may change for each project so made this # for this*/
#define LM35_CHANNEL_ID            2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*
 * Description :
 * Function responsible for get the digital value from the adc and converting it the temperature reading
 */
uint8 LM35_getTemperature();

#endif /* LM35_SENSOR_H_ */
