/*[FILE NAME]   : adc.h
 *[AUTHOR]      : AHMED IBRAHIM
 *[DATE CREATED]: Oct 11, 2021
 *[DESCRIPTION] : this file contain the header of the adc in the ATMEGA16
 */
#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

typedef enum{
	AREF,AVCC,INTERNAL_VOLTAGE_REFERNENCE=3
}ADC_ReferenceVolatge;

typedef enum{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/* ATMEGA16 adc resolution is 10 bits so we put 1023 in the ADC_MAXIMUN_VALUE
 * in this project we will use the internal voltage which is 2.56
 * */
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*
 * Description :
 * Function responsible for initializing the ADC driver by the dynamic configuration based on the user choice.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for reading the adc channel and returning the digital value of the adc.
 */
uint16 ADC_readChannel(uint8 a_channelNumber);



#endif /* ADC_H_ */
