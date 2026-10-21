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

void main(void){

	u8 operators[4][8] = {{0,0b00000100,0b00000100,0b00011111,0b00000100,0b00000100,0b00000100,0},{0,0,0,0b00011111,0,0,0,0},{0,0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0,0},{0,0b00010001,0b00001010,0b00000100,0b00001010,0b00010001,0,0}} , Local_u8OperatorCounter = 0 ;
	u8 Local_u8KeyValue  ;
	static u8 Local_u8OperandCounter = 0 , Local_u8Operand_2_Counter = 0 ,Local_u8ReminderOperandCounter  = 0 , Local_u8ReminderOpernadCouner2 = 0 ;
	u32 Local_u32Operand1 = 0 , Local_u32Opernd2 = 0 , Local_u32ReminderOpernad1 = 0 , Local_u32ReminderOpernad2 = 0 , Local_u32CalculatorResult = 0 , Local_u32ReminderResult = 0;
	u16 Local_u16ReminderOfDivision = 0;
	_delay_ms(1000);
	PORT_voidInt();
	CLCD_voidInit();
	while(1){
		Local_u8OperandCounter = 0 , Local_u8Operand_2_Counter = 0 ,Local_u8ReminderOperandCounter  = 0 , Local_u8ReminderOpernadCouner2 = 0 ;
		Local_u32Operand1 = 0 , Local_u32Opernd2 = 0 , Local_u32ReminderOpernad1 = 0 , Local_u32ReminderOpernad2 = 0 , Local_u32CalculatorResult = 0 , Local_u32ReminderResult = 0 ;
		Local_u16ReminderOfDivision = 0;
		/***********************************************************************/
		/***********************************************************************/

		/* First Operand */

		do {
			Local_u8KeyValue = 	KPD_u8GetPressedKey();

		}while(Local_u8KeyValue == 0xff );

		while( ( Local_u8KeyValue <= 9 ) &&  ( Local_u8KeyValue >= 0 ) ){

			Local_u32Operand1 = ( Local_u32Operand1 *  10 ) + Local_u8KeyValue ;
			CLCD_voidWriteNumber(Local_u32Operand1,0,0);

			_delay_ms(300);

			Local_u8OperandCounter ++ ;

			do {
				Local_u8KeyValue = 	KPD_u8GetPressedKey();

			}while(Local_u8KeyValue == 0xff );


		}

		/* Floating of first Opernad */

		if(Local_u8KeyValue == '.' )  {
			CLCD_voidGoToXY(0,Local_u8OperandCounter);
			CLCD_voidSendData('.');

			Local_u8OperandCounter++ ;
			_delay_ms(300);
			do {
				Local_u8KeyValue = 	KPD_u8GetPressedKey();

			}while(Local_u8KeyValue == 0xff );

			while( ( Local_u8KeyValue <= 9 ) &&  ( Local_u8KeyValue >= 0 ) ){

				Local_u32ReminderOpernad1 = ( Local_u32ReminderOpernad1 *  10 ) + Local_u8KeyValue ;
				CLCD_voidWriteNumber(Local_u32ReminderOpernad1,0,Local_u8OperandCounter);

				_delay_ms(300);

				Local_u8ReminderOperandCounter ++ ;

				do {
					Local_u8KeyValue = 	KPD_u8GetPressedKey();

				}while(Local_u8KeyValue == 0xff );


			}

			if(Local_u32ReminderOpernad1 < 10 ){
				Local_u32ReminderOpernad1 *= 100 ;
			}
			else if(Local_u32ReminderOpernad1 < 100 ){
				Local_u32ReminderOpernad1 *= 10 ;
			}
		}

		/***********************************************************************/
		/***********************************************************************/

		/* The Operator*/

		while( (Local_u8KeyValue ==  '+' ) ||(Local_u8KeyValue ==  '-' ) ||(Local_u8KeyValue ==  '*'  || (Local_u8KeyValue ==  '/' )) ){

			switch(Local_u8KeyValue){

			case '+' : 	Local_u8OperatorCounter = 0 ;
			CLCD_voidWriteSpecialCharacter(operators[Local_u8OperatorCounter],Local_u8OperatorCounter,0, (Local_u8OperandCounter + Local_u8ReminderOperandCounter) );

			break ;

			case '-' :
				Local_u8OperatorCounter = 1 ;
				CLCD_voidWriteSpecialCharacter(operators[Local_u8OperatorCounter],Local_u8OperatorCounter,0,(Local_u8OperandCounter + Local_u8ReminderOperandCounter) );
				break ;

			case '/' :
				Local_u8OperatorCounter = 2 ;
				CLCD_voidWriteSpecialCharacter(operators[Local_u8OperatorCounter],Local_u8OperatorCounter,0,(Local_u8OperandCounter + Local_u8ReminderOperandCounter));
				break ;


			case '*' :
				Local_u8OperatorCounter = 3 ;
				CLCD_voidWriteSpecialCharacter(operators[Local_u8OperatorCounter],Local_u8OperatorCounter,0,(Local_u8OperandCounter + Local_u8ReminderOperandCounter));
				break ;

			default : break ;
			}

			_delay_ms(300);
			do {
				Local_u8KeyValue = 	KPD_u8GetPressedKey();

			}while(Local_u8KeyValue == 0xff );

		}

		Local_u8OperandCounter ++ ;

		/***********************************************************************/
		/***********************************************************************/

		/* Second Operand */


		while( ( Local_u8KeyValue <= 9 ) &&  ( Local_u8KeyValue >= 0 ) ){

			Local_u32Opernd2 = ( Local_u32Opernd2 *  10 ) + Local_u8KeyValue ;
			CLCD_voidWriteNumber(Local_u32Opernd2,0,(Local_u8OperandCounter + Local_u8ReminderOperandCounter ) );

			_delay_ms(300);

			Local_u8Operand_2_Counter ++ ;

			do {
				Local_u8KeyValue = 	KPD_u8GetPressedKey();

			}while(Local_u8KeyValue == 0xff );
		}

		/* Floating of Second Opernad */

		if(Local_u8KeyValue == '.' )  {
			Local_u8OperandCounter += Local_u8ReminderOperandCounter ;
			CLCD_voidGoToXY(0,Local_u8OperandCounter + Local_u8Operand_2_Counter);
			CLCD_voidSendData('.');
			Local_u8OperandCounter++;
			_delay_ms(300);
			do {
				Local_u8KeyValue = 	KPD_u8GetPressedKey();

			}while(Local_u8KeyValue == 0xff );

			while( ( Local_u8KeyValue <= 9 ) &&  ( Local_u8KeyValue >= 0 ) ){

				Local_u32ReminderOpernad2 = ( Local_u32ReminderOpernad2 *  10 ) + Local_u8KeyValue ;
				CLCD_voidWriteNumber(Local_u32ReminderOpernad2,0,Local_u8OperandCounter + Local_u8Operand_2_Counter);

				_delay_ms(300);

				Local_u8ReminderOpernadCouner2 ++ ;

				do {
					Local_u8KeyValue = 	KPD_u8GetPressedKey();

				}while(Local_u8KeyValue == 0xff );


			}
			if(Local_u32ReminderOpernad2 < 10 ){
				Local_u32ReminderOpernad2 *= 100 ;
			}
			else if(Local_u32ReminderOpernad2 < 100 ){
				Local_u32ReminderOpernad2 *= 10 ;
			}
		}


		/***********************************************************************/
		/***********************************************************************/

		/* Result */

		CLCD_voidGoToXY(0,Local_u8OperandCounter+Local_u8Operand_2_Counter + Local_u8ReminderOpernadCouner2 );
		CLCD_voidSendString(" = ");
		Local_u8OperandCounter +=  Local_u8ReminderOpernadCouner2 + 2 ;

		/* Switch the operator */
		switch(Local_u8OperatorCounter){

		/* if the operater is Adding two numbers */

		case 0 : Local_u32CalculatorResult = Local_u32Operand1 + Local_u32Opernd2 ;
		Local_u32ReminderResult = Local_u32ReminderOpernad1 + Local_u32ReminderOpernad2 ;
		if(Local_u32ReminderResult > 1000 ){
			Local_u32CalculatorResult += 1 ;
			Local_u32ReminderResult -= 1000 ;

		}
		if(( Local_u8OperandCounter + Local_u8Operand_2_Counter) > 10 ){
			CLCD_voidWriteNumber(Local_u32CalculatorResult ,1, 0 );
			Local_u8OperandCounter = 0 ;
			while(Local_u32CalculatorResult != 0){
				Local_u32CalculatorResult /= 10 ;
				Local_u8OperandCounter +=1 ;
			}
			if( (Local_u32ReminderOpernad1 != 0) ||  (Local_u32ReminderOpernad2 != 0)){
				CLCD_voidGoToXY(1,(Local_u8OperandCounter ));
				CLCD_voidSendData('.');
				Local_u8OperandCounter ++ ;
				if( Local_u32ReminderResult < 10){
					CLCD_voidWriteNumber( 0 ,1, ( Local_u8OperandCounter ) );
					CLCD_voidWriteNumber( 0 ,1, ( Local_u8OperandCounter + 1 ) );
					Local_u8OperandCounter += 2 ;
				}
				else if(Local_u32ReminderResult < 100){
					CLCD_voidWriteNumber( 0 ,1, ( Local_u8OperandCounter ) );
					Local_u8OperandCounter += 1 ;
				}
				CLCD_voidWriteNumber(Local_u32ReminderResult ,1, ( Local_u8OperandCounter ) );
			}
		}
		else {
			CLCD_voidWriteNumber(Local_u32CalculatorResult ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter) );
			while(Local_u32CalculatorResult != 0){
				Local_u32CalculatorResult /= 10 ;
				Local_u8OperandCounter +=1 ;
			}
			if( (Local_u32ReminderOpernad1 != 0) ||  (Local_u32ReminderOpernad2 != 0)){
				CLCD_voidGoToXY(0,(Local_u8OperandCounter + Local_u8Operand_2_Counter ));
				CLCD_voidSendData('.');
				Local_u8OperandCounter ++ ;
				if(Local_u32ReminderResult < 10){
					CLCD_voidWriteNumber( 0 ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter ) );
					CLCD_voidWriteNumber( 0 ,0, ( Local_u8OperandCounter  + Local_u8Operand_2_Counter + 1) );
					Local_u8OperandCounter += 2 ;
				}
				else if( Local_u32ReminderResult < 100){
					CLCD_voidWriteNumber( 0 ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter ) );
					Local_u8OperandCounter += 1 ;
				}
				CLCD_voidWriteNumber(Local_u32ReminderResult ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter) );
			}
		}
		break ;

		/* if The operator is substracting two numbers */
		/**************************************************************/
		/**************************************************************/

		case 1 : if(Local_u32Opernd2 > Local_u32Operand1 ){
			CLCD_voidGoToXY(0,Local_u8OperandCounter + 1);
			CLCD_voidSendData('-');
			Local_u8OperandCounter++ ;
			Local_u32CalculatorResult = Local_u32Opernd2 - Local_u32Operand1 ;

			if( Local_u32ReminderOpernad1 < Local_u32ReminderOpernad2 ){
				Local_u32Opernd2 = Local_u32ReminderOpernad2 ;
				Local_u32ReminderOpernad2 = Local_u32ReminderOpernad1  ;
				Local_u32ReminderOpernad1 = Local_u32Opernd2 ;

			}

			Local_u32ReminderResult = Local_u32ReminderOpernad1 - Local_u32ReminderOpernad2 ;
			/*-----------------*/

		}
		else {
			Local_u32CalculatorResult = Local_u32Operand1 - Local_u32Opernd2 ;
			if( (Local_u32ReminderOpernad2 > Local_u32ReminderOpernad1) && (Local_u32Opernd2 == Local_u32Operand1 ) ){
				CLCD_voidGoToXY(0,Local_u8OperandCounter + 2);
							CLCD_voidSendData('-');
							Local_u8OperandCounter++ ;
							Local_u32CalculatorResult = Local_u32ReminderOpernad2 ;
							Local_u32ReminderOpernad2 = Local_u32ReminderOpernad1 ;
							Local_u32ReminderOpernad1 = Local_u32CalculatorResult ;
							Local_u32CalculatorResult = 0 ;

			}
			else if( Local_u32ReminderOpernad1 < Local_u32ReminderOpernad2 ){
				Local_u32CalculatorResult -= 1 ;
				Local_u32ReminderOpernad1 += 1000 ;
			}
			Local_u32ReminderResult = Local_u32ReminderOpernad1 - Local_u32ReminderOpernad2 ;
		}
		if(( Local_u8OperandCounter + Local_u8Operand_2_Counter) > 12 ){
						CLCD_voidWriteNumber(Local_u32CalculatorResult ,1, 0 );
						Local_u8OperandCounter = 0 ;
						if(Local_u32CalculatorResult == 0){
							Local_u8OperandCounter ++ ;
						}
						while(Local_u32CalculatorResult != 0){
							Local_u32CalculatorResult /= 10 ;
							Local_u8OperandCounter +=1 ;
						}
						if( (Local_u32ReminderOpernad1 != 0) ||  (Local_u32ReminderOpernad2 != 0)){
							CLCD_voidGoToXY(1,(Local_u8OperandCounter ));
							CLCD_voidSendData('.');
							Local_u8OperandCounter ++ ;
							if( Local_u32ReminderResult < 10){
								CLCD_voidWriteNumber( 0 ,1, ( Local_u8OperandCounter ) );
								CLCD_voidWriteNumber( 0 ,1, ( Local_u8OperandCounter + 1 ) );
								Local_u8OperandCounter += 2 ;
							}
							else if( Local_u32ReminderResult < 100){
								CLCD_voidWriteNumber( 0 ,1, ( Local_u8OperandCounter ) );
								Local_u8OperandCounter += 1 ;
							}
							CLCD_voidWriteNumber(Local_u32ReminderResult ,1, ( Local_u8OperandCounter ) );
						}
					}
					else {
						CLCD_voidWriteNumber(Local_u32CalculatorResult ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter) );
						while(Local_u32CalculatorResult != 0){
							Local_u32CalculatorResult /= 10 ;
							Local_u8OperandCounter +=1 ;
						}
						if( (Local_u32ReminderOpernad1 != 0) ||  (Local_u32ReminderOpernad2 != 0)){
							CLCD_voidGoToXY(0,(Local_u8OperandCounter + Local_u8Operand_2_Counter ));
							CLCD_voidSendData('.');
							Local_u8OperandCounter ++ ;
							if( Local_u32ReminderResult < 10){
								CLCD_voidWriteNumber( 0 ,0, ( Local_u8OperandCounter ) );
								CLCD_voidWriteNumber( 0 ,0, ( Local_u8OperandCounter ) );
								Local_u8OperandCounter += 2 ;
							}
							else if( Local_u32ReminderResult < 100){
								CLCD_voidWriteNumber( 0 ,0, ( Local_u8OperandCounter ) );
								Local_u8OperandCounter += 1 ;
							}
							CLCD_voidWriteNumber(Local_u32ReminderResult ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter) );
						}
					}
		break ;
		case 2 : Local_u32CalculatorResult = Local_u32Operand1 / Local_u32Opernd2 ;
		if(( Local_u8OperandCounter + Local_u8Operand_2_Counter) > 12 ){
								CLCD_voidWriteNumber(Local_u32CalculatorResult ,1, 0 );
		}
		else {
			CLCD_voidWriteNumber(Local_u32CalculatorResult ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter) );
		}
		break ;
		case 3 :Local_u32CalculatorResult = Local_u32Operand1 * Local_u32Opernd2 ;
		if(( Local_u8OperandCounter + Local_u8Operand_2_Counter) > 12 ){
										CLCD_voidWriteNumber(Local_u32CalculatorResult ,1, 0 );
				}
				else {
					CLCD_voidWriteNumber(Local_u32CalculatorResult ,0, ( Local_u8OperandCounter + Local_u8Operand_2_Counter) );
				}
		break ;
		}



		if( (Local_u8OperatorCounter == 2 ) && ( ( Local_u32Operand1 ) % ( Local_u32Opernd2) != 0 )){

			if(Local_u32Operand1 < Local_u32Opernd2 ){
				Local_u8OperandCounter += 1 ;
			}

			while(Local_u32CalculatorResult != 0){
				Local_u32CalculatorResult /= 10 ;
				Local_u8OperandCounter +=1 ;
			}

			Local_u16ReminderOfDivision = ( ( ( Local_u32Operand1 ) % ( Local_u32Opernd2) ) * 1000 ) / (Local_u32Opernd2) ;
			CLCD_voidSendData('.');
			Local_u8OperandCounter += 1 ;
			CLCD_voidWriteNumber(Local_u16ReminderOfDivision,0,Local_u8OperandCounter + Local_u8Operand_2_Counter );

		}
		_delay_ms(250);

		do {
			Local_u8KeyValue = 	KPD_u8GetPressedKey();

		}while(Local_u8KeyValue == 0xff );
		if(Local_u8KeyValue == '='){
			CLCD_voidClearLCD();
		}
		Local_u8OperandCounter = Local_u8Operand_2_Counter = Local_u32Operand1 = Local_u32Opernd2 = 0 ;
		_delay_ms(250);
	}
}

