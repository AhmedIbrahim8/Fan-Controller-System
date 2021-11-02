# Fan-Controller-System-
# Project Description
- The aim of this project is to design a temperature-controlled fan using ATmega16 microcontroller based on the layered architecture, in which the fan is automatically turned ON or OFF according to the temperature. Use ATmega16 Microcontroller with frequency 1Mhz.<br/>
- In this project, the LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it. This analog signal is given to the ADC, which converts the analog values to digital values.<br/>
- The digital output of the ADC is equivalent to sensed analog voltage. <br/>
- In order to get the temperature from the sensed analog voltage, we need to perform some calculations in the programming for the microcontroller. <br/>
- Once the calculations are done by the microcontroller according to the logic, the temperature is displayed on the LCD.<br/>
- The microcontroller will continuously monitor the temperature and based on the temperature value, the microcontroller will drive the fan like that:<br/>
 a. If the temperature is less than 30C turn off the fan. <br/>
 b. If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed. <br/>
 c. If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed.<br/>
 d. If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed.<br/>
 e. If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed.<br/>
- The main principle of the circuit is to switch on/off the fan connected to DC motor based on temperature value. The DC-Motor rotates in clock-wise direction or stopped based on the fan state.<br/> 
- The LCD should display the temperature value and the fan state continuously.<br/>
- Control the DC-Motor speed using PWM signal generated from Timer0.<br/>
# Video of the simulation
https://user-images.githubusercontent.com/91912492/137816324-2d9ae62d-7666-422a-8415-05971f967d1f.mp4
# SOFTWARE DRIVERS
 - ADC driver based on dynamic configuration
 - LCD driver
 - GPIO driver
 - DC-MOTOR driver
 - LM35 sensor driver
 - Pulse width modulation driver
![Capture](https://user-images.githubusercontent.com/91912492/137818076-db560e64-9cef-43f8-a6b3-7d94a72b5fd0.PNG)

