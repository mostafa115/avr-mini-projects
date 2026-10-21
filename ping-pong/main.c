#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include <util/delay.h>

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

static u8 Global_u8Flag1 = 0 ;
static u8 Global_u8Flag2 = 0 ;
static u8 Global_u8check = 0 ;

void main(){

	u8 Local_u8MovementBall = 0 ;


	PORT_voidInt();
	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	EXTI_voidInt2Init();
	GIE_voidEnable();
	EXIT_u8Int0SetCallBack(&INT0_ISR);
	EXIT_u8Int1SetCallBack(&INT1_ISR);
	EXIT_u8Int2SetCallBack(&INT2_ISR);
	CLCD_voidInit();

	CLCD_voidGoToXY(0,4);
	CLCD_voidSendString("Ping Pong");
	CLCD_voidGoToXY(1,6);
	CLCD_voidSendString("Start");
	_delay_ms(3000);


	while(1){
		GIE_voidEnable();
		CLCD_voidClearLCD();
		for(Local_u8MovementBall = 1 ; Local_u8MovementBall < 16 ; Local_u8MovementBall ++){
			if((Global_u8Flag1 == 0) && (Global_u8Flag2 == 0) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(0,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}
			else if((Global_u8Flag1 == 0) && (Global_u8Flag2 == 1) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(1,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}
			else if((Global_u8Flag1 == 1) && (Global_u8Flag2 == 0) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(0,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}
			else if((Global_u8Flag1 == 1) && (Global_u8Flag2 == 1) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(1,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}
			if( (Local_u8MovementBall == 15) && (Global_u8Flag2 == 1) ){
				CLCD_voidClearLCD();
				GIE_voidDisable();
				_delay_ms(300);
				CLCD_voidSendString("Player 1 Win ");
				_delay_ms(5000);
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(0,4);
				CLCD_voidSendString("Ping Pong");
				CLCD_voidGoToXY(1,6);
				CLCD_voidSendString("Start");
				_delay_ms(3000);
			}

		}
		for(Local_u8MovementBall = 15 ; Local_u8MovementBall > 0 ; Local_u8MovementBall --){
			if((Global_u8Flag1 == 0) && (Global_u8Flag2 == 0) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(0,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}
			else if((Global_u8Flag1 == 0) && (Global_u8Flag2 == 1) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(1,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}
			else if((Global_u8Flag1 == 1) && (Global_u8Flag2 == 0) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(0,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}
			else if((Global_u8Flag1 == 1) && (Global_u8Flag2 == 1) ){
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendData('|');
				CLCD_voidGoToXY(0,Local_u8MovementBall);
				CLCD_voidSendData('o');
				CLCD_voidGoToXY(1,15);
				CLCD_voidSendData('|');
				_delay_ms(250);
			}

			if( (Local_u8MovementBall == 1) && (Global_u8Flag1 == 1) ){
				CLCD_voidClearLCD();
				GIE_voidDisable();
				_delay_ms(300);
				CLCD_voidSendString("Player 2 Win ");
				_delay_ms(5000);
				CLCD_voidClearLCD();
				CLCD_voidGoToXY(0,4);
				CLCD_voidSendString("Ping Pong");
				CLCD_voidGoToXY(1,6);
				CLCD_voidSendString("Start");
				_delay_ms(3000);
			}


		}
		_delay_ms(150);

	}

}

void INT0_ISR(void){
	GIE_voidDisable();
	if(Global_u8check == 0){
		Global_u8check =1 ;
		if(Global_u8Flag1 == 0 ){
			Global_u8Flag1 = 1 ;
		}
		else if(Global_u8Flag1 == 1 ){
			Global_u8Flag1 = 0 ;
		}
		_delay_ms(150);
	}
	GIE_voidEnable();
	_delay_ms(50);
	Global_u8check = 0 ;
}
void INT1_ISR(void){
	GIE_voidDisable();
		if(Global_u8check == 0){
			Global_u8check =1 ;
			if(Global_u8Flag2 == 0 ){
				Global_u8Flag2 = 1 ;
			}
			else if(Global_u8Flag2 == 1 ){
				Global_u8Flag2  = 0 ;
			}
			_delay_ms(150);
		}
		GIE_voidEnable();
		_delay_ms(50);
		Global_u8check = 0 ;
}

void INT2_ISR(void){
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_LOW);
}

