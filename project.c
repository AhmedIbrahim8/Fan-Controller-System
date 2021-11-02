/*
 * Project Description : Fan control System Based on the temperature reading
 * Notes :
 *       1- Application layer can't call the Micro-controller abstraction layer(MCAL), it can only call the init function
 *         only once.
 *       2- Application layer can call the hardware abstraction layer which has the external drivers inside it.
 *       3- MCAL is called by the hardware abstraction layer(HAL)
 * Sequence of operation :
 *  1- Application will call the sensor to get the temperature.
 *  2- Sensor Driver will call the ADC to get the digital reading
 *  3- ADC driver will read the digital value and return the digital reading of the sensor based on the physical signal
 *  4- Sensor Driver will make the scaling on the digital reading based on the : ( Scaling Equation )
 *     a) Max. volt of the sensor
 *     b) Reference volt of the ADC
 *     c) Precision of the ADC (10-Bits so 1023)
 *     d) Digital reading
 *  5- Sensor Driver will return the temperature after the scaling to the application layer
 *  6- Based on the temperature, the application will make some decisions..
 *  7- Application will call the dc motor driver and send to him the duty cycle and the rotation direction of
 *     the motor based on the temperature.
 *  8- Motor Driver will call the GPIO Driver to set the direction of rotation
 *  9- GPIO Driver will return void
 *  10-Motor driver will call the pwm driver and send the duty cycle to it.
 *  11-PWM driver will output the desired pwm
 *  12-pwm will return void to the motor then motor will return void to the application
 *  13-Also, based on the temperature reading, application will call the lcd to display the fan state in the screen
 *
 * */

#include"lcd.h"
#include"std_types.h"
#include"adc.h"
#include"lm35_sensor.h"
#include"dcmotor.h"
int main(){
	/*variable for the temperature value*/
	uint32 temp;
	/*Structure of the adc to initialize it*/
	ADC_ConfigType Adc_Config={INTERNAL_VOLTAGE_REFERNENCE,F_CPU_8};
	/*sending the structure by address to the adc to initialize itself*/
	ADC_init(&Adc_Config);
	/*initialize the lcd*/
	LCD_init();
	/*initialize the DC MOTOR*/
	DcMotor_Init();
	LCD_displayStringRowColumn(0,3,(uint8 *)"Fan is ");
	LCD_displayStringRowColumn(1,3,(uint8 *)"Temp = ");
	LCD_moveCursor(1,13);
	LCD_displayCharacter('C');
	while(1){
		/*application call the sensor asking for the remperature */
		temp = LM35_getTemperature();
		/*displaying the temperature value in the lcd*/
		LCD_moveCursor(1,10);
		LCD_intgerToString(temp);
		/*application makes some decisions based on the temperature value*/
		/*display the state of the motor on the lcd*/
		/*application sends the motor state and duty cycle to the dc motor driver*/
		if(temp>=120){
			LCD_displayStringRowColumn(0,10,(uint8 *)"ON ");
			DcMotor_Rotate(MOTOR_CW,100);
		}
		else if(temp>=90){
			LCD_displayStringRowColumn(0,10,(uint8 *)"ON ");
			DcMotor_Rotate(MOTOR_CW,75);
			/*This condition is made to display correctly on the LCD*/
			if(temp<100){
				LCD_moveCursor(1,12);
				LCD_displayCharacter(' ');
			}
		}
		else if(temp>=60){
			LCD_displayStringRowColumn(0,10,(uint8 *)"ON ");
			DcMotor_Rotate(MOTOR_CW,50);
			LCD_moveCursor(1,12);
			LCD_displayCharacter(' ');
		}
		else if(temp>=30){
			LCD_displayStringRowColumn(0,10,(uint8 *)"ON ");
			DcMotor_Rotate(MOTOR_CW,25);
			LCD_moveCursor(1,12);
			LCD_displayCharacter(' ');
		}
		else if(temp <30){
			LCD_displayStringRowColumn(0,10,(uint8 *)"OFF");
			DcMotor_Rotate(MOTOR_OFF,0);
			LCD_moveCursor(1,12);
			LCD_displayCharacter(' ');
			/*This condition is made to display correctly on the LCD*/
			if(temp<10){
				LCD_moveCursor(1,11);
				LCD_displayCharacter(' ');
			}
		}


	}
}
