/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: mosta
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "DC_MOTOR_interface.h"
#include "STEPPER_MOTOR_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"

void main(){

	u8 Local_u8KeyValue = 0xff ;
	static u16 Local_u16Angle = 0 ;
	PORT_voidInt();
	CLCD_voidInit();

	while(1){
		CLCD_voidSendString("Welcome to motor dashboard APP");
		CLCD_voidSendData(':');
		_delay_ms(2000);
		CLCD_voidClearLCD();

		/* Choosing the type of motor */

		CLCD_voidSendString("For DC Motor-> 2");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("For Stepper-> 3");
		do{
			Local_u8KeyValue = KPD_u8GetPressedKey();
		}while(Local_u8KeyValue == 0xff);
		CLCD_voidClearLCD();

		/* For DC_Motor */

		if(Local_u8KeyValue == 2){
			CLCD_voidSendString("Rotate CW -> 2");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("Rotate C.CW -> 3");
			_delay_ms(250);
			do{
				Local_u8KeyValue = KPD_u8GetPressedKey();
			}while(Local_u8KeyValue == 0xff);
			if(Local_u8KeyValue == 2){
				DCMOTOR_voidRotateClockWise();
				CLCD_voidClearLCD();
				_delay_ms(250);
				CLCD_voidSendString("To Stop Press   Any Key");
				do{
					Local_u8KeyValue = KPD_u8GetPressedKey();
				}while(Local_u8KeyValue == 0xff);
				DCMOTOR_voidStop();
			}
			else if(Local_u8KeyValue == 3){
				DCMOTOR_voidRotateUntiClockWise();
				CLCD_voidClearLCD();
				_delay_ms(250);
				CLCD_voidSendString("To Stop Press   Any Key");
				do{
					Local_u8KeyValue = KPD_u8GetPressedKey();
				}while(Local_u8KeyValue == 0xff);
				DCMOTOR_voidStop();
			}

		}

		/* For Stepper Motor */

		else if(Local_u8KeyValue == 3){
			_delay_ms(250);
			CLCD_voidClearLCD();
			CLCD_voidSendString("Select angle : ");
			do{
				Local_u8KeyValue = KPD_u8GetPressedKey();
			}while(Local_u8KeyValue == 0xff);

			while(Local_u8KeyValue != '='){
				Local_u16Angle = ( Local_u16Angle *  10 ) + (u16)Local_u8KeyValue ;
				CLCD_voidClearLCD();
				CLCD_voidWriteNumber((u32)Local_u16Angle,0,0);
				Local_u8KeyValue = 0xff ;
				_delay_ms(150);
				do{
					Local_u8KeyValue = KPD_u8GetPressedKey();
				}while(Local_u8KeyValue == 0xff);
			}
			CLCD_voidClearLCD();
			CLCD_voidSendString("Rotate CW -> 2");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("Rotate C.CW -> 3");
			do{
				Local_u8KeyValue = KPD_u8GetPressedKey();
			}while(Local_u8KeyValue == 0xff);
			if(Local_u8KeyValue == 2){
				StepperMotor_voidRotateCloclWise(Local_u16Angle);
			}
			else if(Local_u8KeyValue == 3){
				StepperMotor_voidRotateCounterCloclWise(Local_u16Angle);
			}
			CLCD_voidClearLCD();
			_delay_ms(1000);
			CLCD_voidSendString("> Angle reached <");
			_delay_ms(2000);
		}

		CLCD_voidClearLCD();
		Local_u16Angle = 0 ;
	}
}


