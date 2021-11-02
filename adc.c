/*[FILE NAME]   : adc.c
 *[AUTHOR]      : AHMED IBRAHIM
 *[DATE CREATED]: Oct 11, 2021
 *[DESCRIPTION] : this file contain the source of the adc in the ATMEGA16
 */

#include"adc.h"
#include<avr/io.h>
#include"common_macros.h"

void ADC_init(const ADC_ConfigType *Config_Ptr){
	/*initial value of the ADMUX register
	 * This instruction will :
	 * --> Set the reference voltage based on the structure given on the last 2 bits (REFS1 & REFS0) in
	 * the register ADMUX.
	 *   why shift left by 6 ?
	 *       |---> because the bits used to determine the reference volt start from bit 6
	 * --> Clear the ADLAR bit (bit5) to put the digital value in the first 10 bits of the ADC register
	 * --> Clear the first 5bits just initial value (those bits will change in the read channel function)
	 * */

	ADMUX=(Config_Ptr->ref_volt)<<6;
	/*To enable the ADC module, we need to put logic 1 in this bit(bit7) in ADCSRA register
	 * but this instruction will :
	 * -->>Disable the start conversion bit
	 * -->>Disable the ADC Auto Trigger Bit
	 * -->>Disable the ADC Interrupt because we are using the polling method
	 * */

	ADCSRA=(1<<ADEN);
	/*We need to save the last 5 bits value and clear the first 3 bits so that we can be done by the
	 * mask 0xF8 and to put the new value of the prescaler we need to make the or operation*/
	ADCSRA=(ADCSRA & 0xF8 )|Config_Ptr->prescaler;
}

uint16 ADC_readChannel(uint8 a_channelNumber){
	/*We need to save the last 3 bits value and clear the first 5 bits so that we can be done by the
	 * mask 0xF8 and to put the new value of the prescaler we need to make the or operation*/
	ADMUX = (ADMUX & 0xE0) | (a_channelNumber & 0x07);
	/*To start conversion*/
	ADCSRA|=(1<<ADSC);
	/*if the conversion is done the ADIF will be 1 so the condition will be false so the code will go out the while
	 * loop but if the conversion is not done the flag will be zero and the code will be inside the while loop*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/*Here, there is no interrupt so the flag will always be 1 after the conversion so we must clear the flag and
	 * this is done by writing logic one by ADIF bit that's why we used this macro*/
	SET_BIT(ADCSRA,ADIF);
	/*returning the digital value*/
	return ADC;
}
