/*[FILE NAME]   : lm35_sensor.h
 *[AUTHOR]      : AHMED IBRAHIM
 *[DATE CREATED]: OCT 9, 2021
 *[DESCRIPTION] : this file contain the source file of the lm35 sensor
 */

#include"lm35_sensor.h"
#include"adc.h" /*because the sensor is working by the adc*/

uint8 LM35_getTemperature(){
	/*
	 * uint8 --> because the maximum temp. of the sensor is 150 C*/
	uint8 temp_value;
	/*to receive the digital value
	 * uint16 --> because the adc register is 16 bit register*/
	uint16 adc_digital_value;
	/*here we call the adc read function and send the channel id that the sensor is connected to..
	 * This function will return the adc digital value*/
	adc_digital_value = ADC_readChannel(LM35_CHANNEL_ID);
	/*To understand this digital value we need to make the scaling to understand what is the equivalent
	 * temperature based on the adcdigital value*/
	temp_value = (uint8)(((uint32)adc_digital_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)\
	/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp_value;

}
