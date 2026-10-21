/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: mosta
 */

#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "util/delay.h"
#include "DIO_interface.h"

#define Left                                 10
#define Right                                11
#define Enter                                12
#define Start                                13
void main(void){

	u8 arrow[8] = {0b00000100,0b00001110,0b00011111,0b00000100,0b00000100,0b00000100,0b00000100,0b00000000};
	static u8 Local_u8KeyValue = 0xff , Loal_u8HourDigit1 = 0 , Loal_u8HourDigit2 = 0 , Loal_u8MinuteDigit1 = 0 , Loal_u8MinuteDigit2 = 0  , Loal_u8SecondDigit1 = 0, Loal_u8SecondDigit2 = 0 , Local_u8DigitNumber = 0 ;
	PORT_voidInt();
	CLCD_voidInit();
	while(1){

		while(Local_u8KeyValue != Enter){
			CLCD_voidClearLCD();
			CLCD_voidWriteNumber(Loal_u8HourDigit1,0,0);
			CLCD_voidWriteNumber(Loal_u8HourDigit2,0,1);
			CLCD_voidGoToXY(0,2);
			CLCD_voidSendData(':');
			CLCD_voidWriteNumber(Loal_u8MinuteDigit1,0,3);
			CLCD_voidWriteNumber(Loal_u8MinuteDigit2,0,4);
			CLCD_voidGoToXY(0,5);
			CLCD_voidSendData(':');
			CLCD_voidWriteNumber(Loal_u8SecondDigit1,0,6);
			CLCD_voidWriteNumber(Loal_u8SecondDigit2,0,7);
			CLCD_voidWriteSpecialCharacter(arrow,0,1,Local_u8DigitNumber);

			/* Read first button change Number or Moving digits */

			do {
				Local_u8KeyValue = 	KPD_u8GetPressedKey();

			}while(Local_u8KeyValue == 0xff );

			/* loop to take the time of the stop watch */

			if( (Local_u8KeyValue == Left ) && (Local_u8DigitNumber == 0)){
				Local_u8DigitNumber = 7 ;
			}
			else if( (Local_u8KeyValue == Right ) && (Local_u8DigitNumber == 7)){
				Local_u8DigitNumber = 0 ;
			}
			else if( (Local_u8KeyValue == Left ) ){
				Local_u8DigitNumber -= 1 ;
			}
			else if( (Local_u8KeyValue == Right ) ){
				Local_u8DigitNumber += 1 ;
			}
			else if ((Local_u8KeyValue >= 0 ) && (Local_u8KeyValue <= 9 ) ){
				/* Change  numbers of stop watch  */
				switch(Local_u8DigitNumber){
				case 0 : Loal_u8HourDigit1 = Local_u8KeyValue ; break ;
				case 1 : Loal_u8HourDigit2 = Local_u8KeyValue ; break ;
				case 3 : Loal_u8MinuteDigit1 = Local_u8KeyValue ; break ;
				case 4 : Loal_u8MinuteDigit2 = Local_u8KeyValue ; break ;
				case 6 : Loal_u8SecondDigit1 = Local_u8KeyValue ; break ;
				case 7 : Loal_u8SecondDigit2 = Local_u8KeyValue ; break ;
				default : break ;
				}
			}

			_delay_ms(200);
		}

		_delay_ms(200);
		CLCD_voidClearLCD();
		CLCD_voidWriteNumber(Loal_u8HourDigit1,0,0);
		CLCD_voidWriteNumber(Loal_u8HourDigit2,0,1);
		CLCD_voidGoToXY(0,2);
		CLCD_voidSendData(':');
		CLCD_voidWriteNumber(Loal_u8MinuteDigit1,0,3);
		CLCD_voidWriteNumber(Loal_u8MinuteDigit2,0,4);
		CLCD_voidGoToXY(0,5);
		CLCD_voidSendData(':');
		CLCD_voidWriteNumber(Loal_u8SecondDigit1,0,6);
		CLCD_voidWriteNumber(Loal_u8SecondDigit2,0,7);

		/* waiting for starting the stop watch */

		do{
			Local_u8KeyValue = KPD_u8GetPressedKey();
		}while(Local_u8KeyValue == 0xff);

		/* managing time */
		if(Local_u8KeyValue == Start ){
			while( (Loal_u8SecondDigit1 != 0) || (Loal_u8SecondDigit2 != 0) || (Loal_u8MinuteDigit1 != 0) || (Loal_u8MinuteDigit2 != 0)  || (Loal_u8HourDigit1 != 0) || (Loal_u8HourDigit2 != 0)){

				while( (Loal_u8SecondDigit1 != 0) || (Loal_u8SecondDigit2 != 0) || (Loal_u8MinuteDigit1 != 0) || (Loal_u8MinuteDigit2 != 0)){


					while((Loal_u8SecondDigit1 != 0) || (Loal_u8SecondDigit2 != 0)){

						/* Manage Seconds Part */
						CLCD_voidWriteNumber(Loal_u8MinuteDigit1,0,3);
						CLCD_voidWriteNumber(Loal_u8MinuteDigit2,0,4);
						if(Loal_u8SecondDigit2 == 0 ){
							if(Loal_u8SecondDigit1 == 0 ){
								break ;
							}
							else{
								Loal_u8SecondDigit1 -= 1 ;
								Loal_u8SecondDigit2 = 9 ;
								_delay_ms(1000);
								CLCD_voidWriteNumber(Loal_u8SecondDigit2,0,7);
								CLCD_voidWriteNumber(Loal_u8SecondDigit1,0,6);
							}
						}
						else {
							Loal_u8SecondDigit2 -= 1 ;
							_delay_ms(1000);
							CLCD_voidWriteNumber(Loal_u8SecondDigit2,0,7);
							CLCD_voidWriteNumber(Loal_u8SecondDigit1,0,6);
						}

					}

					/* Manage Minutes Part */


					if(Loal_u8MinuteDigit2 == 0 ){

						if(Loal_u8MinuteDigit1 == 0 ){
							break ;
						}
						else{
							Loal_u8MinuteDigit1 -= 1 ;
							Loal_u8MinuteDigit2 = 9 ;
							CLCD_voidWriteNumber(Loal_u8MinuteDigit2,0,7);
							CLCD_voidWriteNumber(Loal_u8MinuteDigit1,0,6);
							Loal_u8SecondDigit1 = 6 ;
						}
					}
					else {
						Loal_u8MinuteDigit2 -= 1 ;
						CLCD_voidWriteNumber(Loal_u8MinuteDigit2,0,4);
						CLCD_voidWriteNumber(Loal_u8MinuteDigit1,0,3);
						Loal_u8SecondDigit1 = 6 ;
					}


				}

				/* Manage Hours Part */


				if(Loal_u8HourDigit2 == 0 ){

					if(Loal_u8HourDigit1 == 0 ){
						break ;
					}
					else{
						Loal_u8HourDigit1 -= 1 ;
						Loal_u8HourDigit2 = 9 ;
						CLCD_voidWriteNumber(Loal_u8HourDigit2,0,1);
						CLCD_voidWriteNumber(Loal_u8HourDigit1,0,0);
						Loal_u8MinuteDigit1 = 6 ;
					}
				}
				else {
					Loal_u8HourDigit2 -= 1 ;
					CLCD_voidWriteNumber(Loal_u8HourDigit2,0,1);
					CLCD_voidWriteNumber(Loal_u8HourDigit1,0,0);
					Loal_u8MinuteDigit1 = 6 ;
				}

			}

			do{

				CLCD_voidClearLCD();
				CLCD_voidGoToXY(0,3);
				CLCD_voidSendString("Jimmy");
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendData('-');
				CLCD_voidSendData('>');
				CLCD_voidSendString("It is Time");
				CLCD_voidSendData('<');
				CLCD_voidSendData('-');
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
				_delay_ms(500);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_LOW);
				Local_u8KeyValue = KPD_u8GetPressedKey();
				_delay_ms(500);
						}while(Local_u8KeyValue == 0xff);


		}
	}
}
