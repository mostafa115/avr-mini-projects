/***********************************************************************/
/***********************************************************************/
/****************************     Author : Mostafa Gamal    ************/
/****************************     Layer  : HAL              ************/
/****************************     swc    : KEYPAD           ************/
/****************************     Version: 1.00             ************/
/***********************************************************************/
/***********************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KPD_PORT      					DIO_u8PORTD

#define KPD_COLUMN0_PIN                 DIO_u8PIN3
#define KPD_COLUMN1_PIN                 DIO_u8PIN2
#define KPD_COLUMN2_PIN                 DIO_u8PIN1
#define KPD_COLUMN3_PIN                 DIO_u8PIN0


#define KPD_ROW0_PIN                 DIO_u8PIN4
#define KPD_ROW1_PIN                 DIO_u8PIN5
#define KPD_ROW2_PIN                 DIO_u8PIN6
#define KPD_ROW3_PIN                 DIO_u8PIN7


#define KPD_No_Pressed_Key       			 0xff
#define Left                                 10
#define Right                                11
#define Enter                                12
#define Start                                13

#define KPD_ARR_VAL              { {Left,Right,Enter,Start},{0,1,2,3},{4,5,6,7},{8,9,15,16} }

#endif
