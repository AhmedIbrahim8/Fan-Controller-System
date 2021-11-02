/*[FILE NAME]   : lcd.h
 *[AUTHOR]      : AHMED IBRAHIM
 *[DATE CREATED]: Sep 29, 2021
 *[DESCRIPTION] : this file contain the header file of the LCD driver
*/
#ifndef LCD_H_
#define LCD_H_
#include"std_types.h"
/*to make the driver configurable, it must support all behaviors of modes incase of 4bits mode or 8bits mode*/
#define LCD_DATA_BITS_MODE 8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Data bits modes should be 4 or 8" /* incase u enter a different number not 4 or not 8 */

#endif

#if(LCD_DATA_BITS_MODE == 4)

  #define LCD_LAST_PORT_PINS

  #ifdef LCD_LAST_PORT_PINS

   #define LCD_FIRST_DATA_PIN_ID PIN4_ID

  #else

   #define LCD_FIRST_DATA_PIN_ID PIN0_ID

#endif
#endif

/*
 * To make the driver configurable we must make the #define because the connection of the lcd may vary
 * By meaning ---> rs,rw and enable pins can be connected to any port as u like */
#define LCD_DATA_PORT_ID PORTC_ID

#define LCD_RS_PORT_ID PORTD_ID
#define LCD_RS_PIN_ID PIN0_ID

#define LCD_RW_PORT_ID PORTD_ID
#define LCD_RW_PIN_ID PIN1_ID

#define LCD_ENABLE_PORT_ID PORTD_ID
#define LCD_ENABLE_PIN_ID  PIN2_ID

/*
 * To make the driver readable we shouldn't write any numbers in the code that's why we made the #s below*/
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80


/*
 * lcd memory address
 * */
#define FIRST_ROW_ADDRESS 0x00
#define SECOND_ROW_ADDRESS 0x40
#define THIRD_ROW_ADDRESS 0x10
#define FOURTH_ROW_ADDRESS 0x50

/*
 * Description :
 * Function responsible for sending a command to the lcd
 */
void LCD_sendCommand(uint8 a_command);

/*
 * Description :
 * Function responsible for initializing the lcd
 */
void LCD_init(void);
/*
 * Description :
 * Function responsible for displaying a character to the lcd
 */
void LCD_displayCharacter(uint8 a_character);
/*
 * Description :
 * Function responsible for displaying a string to the lcd
 */
void LCD_displayString(const uint8 *string);
/*
 * Description :
 * Function responsible for clearing the lcd
 */
void LCD_clearScreen(void);
/*
 * Description :
 * Function responsible for moving the cursor of the lcd
 */
void LCD_moveCursor(uint8 a_row,uint8 a_col);
/*
 * Description :
 * Function responsible for displaying a string to the lcd at any row and column
 */
void LCD_displayStringRowColumn(uint8 a_row,uint8 a_col,uint8 *string);
/*
 * Description :
 * Function responsible for displaying an intger to the lcd
 */
void LCD_intgerToString(int a_data);




#endif /* LCD_H_ */
