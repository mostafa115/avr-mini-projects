/***********************************************************************/
/***********************************************************************/
/****************************     Author : Mostafa Gamal    ************/
/****************************     Layer  : MCAL             ************/
/****************************     swc    : EXTI             ************/
/****************************     Version: 1.00             ************/
/***********************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

/* Global Pointers To Function To Hold INT0,INT1,INT2 ISR Address */

void (*EXIT_pvInt0Fun)(void) = NULL ;
void (*EXIT_pvInt1Fun)(void) = NULL ;
void (*EXIT_pvInt2Fun)(void) = NULL ;

void EXTI_voidInt0Init(void){


	/* FOR ATMEGA 32 */
#if Target == Atmega32
	/* Check sense control */
#if INT0_SENSE  == LOW_LEVEL

	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE  == ON_CHANGE

	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE  == FALLING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE  == RISING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#else
#error "Wrong INT0_SENSE Configuration Option  "
#endif

	/* Chech Perepheral Interrupt Enable INITIAL STATE  */

#if INT0_INITIAL_STATE == ENABLED

	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_SENSE Configuration option "
#endif


	/* fOR ATMEGA128 */
#elif Target == Atmega128

	/* Check sense control */
#if INT0_SENSE  == LOW_LEVEL

	CLR_BIT(EICRA,EICRA_ISC01);
	CLR_BIT(EICRA,EICRA_ISC00);

#elif INT0_SENSE  == FALLING_EDGE

	SET_BIT(EICRA,EICRA_ISC01);
	CLR_BIT(EICRA,EICRA_ISC00);

#elif INT0_SENSE  == RISING_EDGE

	SET_BIT(EICRA,EICRA_ISC01);
	SET_BIT(EICRA,EICRA_ISC00);


#else
#error "Wrong INT0_SENSE Configuration Option  "
#endif


	/* Chech Perepheral Interrupt Enable INITIAL STATE  */

#if INT0_INITIAL_STATE == ENABLED

	SET_BIT(EIMSK,EIMSK_INT0);

#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(EIMSK,EIMSK_INT0);
#else
#error "Wrong INT0_SENSE Configuration option "
#endif
#endif

}

void EXTI_voidInt1Init(void){
	/* FOR ATMEGA 32 */
#if Target == Atmega32
	/* Check sense control */
#if INT1_SENSE  == LOW_LEVEL

	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE  == ON_CHANGE

	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE  == FALLING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE  == RISING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#else
#error "Wrong INT1_SENSE Configuration Option"
#endif

	/* Chech Perepheral Interrupt Enable INITIAL STATE  */

#if INT1_INITIAL_STATE == ENABLED

	SET_BIT(GICR,GICR_INT1);

#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1_SENSE Configuration option "
#endif


	/* fOR ATMEGA128 */
#elif Target == Atmega128

	/* Check sense control */
#if INT1_SENSE  == LOW_LEVEL

	CLR_BIT(EICRA,EICRA_ISC11);
	CLR_BIT(EICRA,EICRA_ISC10);

#elif INT1_SENSE  == FALLING_EDGE

	SET_BIT(EICRA,EICRA_ISC11);
	CLR_BIT(EICRA,EICRA_ISC10);

#elif INT1_SENSE  == RISING_EDGE

	SET_BIT(EICRA,EICRA_ISC11);
	SET_BIT(EICRA,EICRA_ISC10);


#else
#error "Wrong INT1_SENSE Configuration Option  "
#endif


	/* Chech Perepheral Interrupt Enable INITIAL STATE  */

#if INT1_INITIAL_STATE == ENABLED

	SET_BIT(EIMSK,EIMSK_INT1);

#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(EIMSK,EIMSK_INT1);
#else
#error "Wrong INT1_SENSE Configuration option "
#endif
#endif
}

void EXTI_voidInt2Init(void){

	/* FOR ATMEGA 32 */
#if Target == Atmega32
	/* Check sense control */
#if INT1_SENSE  == FALLING_EDGE

	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif INT1_SENSE  == RISING_EDGE

	CLR_BIT(MCUCSR,MCUCSR_INT2);

#else
#error "Wrong INT2_SENSE Configuration Option"
#endif

	/* Chech Perepheral Interrupt Enable INITIAL STATE  */

#if INT1_INITIAL_STATE == ENABLED

	SET_BIT(GICR,GICR_INT2);

#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INT2_SENSE Configuration option "
#endif


	/* fOR ATMEGA128 */
#elif Target == Atmega128

	/* Check sense control */
#if INT1_SENSE  == LOW_LEVEL

	CLR_BIT(EICRA,EICRA_ISC21);
	CLR_BIT(EICRA,EICRA_ISC20);

#elif INT1_SENSE  == FALLING_EDGE

	SET_BIT(EICRA,EICRA_ISC21);
	CLR_BIT(EICRA,EICRA_ISC20);

#elif INT1_SENSE  == RISING_EDGE

	SET_BIT(EICRA,EICRA_ISC21);
	SET_BIT(EICRA,EICRA_ISC20);


#else
#error "Wrong INT2_SENSE Configuration Option  "
#endif


	/* Chech Perepheral Interrupt Enable INITIAL STATE  */

#if INT2_INITIAL_STATE == ENABLED

	SET_BIT(EIMSK,EIMSK_INT2);

#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(EIMSK,EIMSK_INT2);
#else
#error "Wrong INT2_SENSE Configuration option "
#endif
#endif
}

u8 EXIT_u8Int0SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState = OK ;
#if Target == Atmega32
	switch (Copy_u8Sense) {
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case FALLING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;
	default: Local_u8ErrorState = NOK ;
	break;
	}

#elif Target == Atmega128
	switch (Copy_u8Sense) {
	case LOW_LEVEL:
		CLR_BIT(EICRA,EICRA_ISC01);
		CLR_BIT(EICRA,EICRA_ISC00);
		break;
	case FALLING_EDGE:
		SET_BIT(EICRA,EICRA_ISC01);
		CLR_BIT(EICRA,EICRA_ISC00);
		break;
	case RISING_EDGE:
		SET_BIT(EICRA,EICRA_ISC01);
		SET_BIT(EICRA,EICRA_ISC00);
		break;
	default: Local_u8ErrorState = NOK ;
	break;
	}
#else
#error "Wrong Control Sense Configuration option "
#endif
	return Local_u8ErrorState;
}

u8 EXIT_u8Int1SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState = OK ;
#if Target == Atmega32
	switch (Copy_u8Sense) {
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case FALLING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
		break;
	default: Local_u8ErrorState = NOK ;
	break;
	}

#elif Target == Atmega128
	switch (Copy_u8Sense) {
	case LOW_LEVEL:
		CLR_BIT(EICRA,EICRA_ISC11);
		CLR_BIT(EICRA,EICRA_ISC10);
		break;
	case FALLING_EDGE:
		SET_BIT(EICRA,EICRA_ISC11);
		CLR_BIT(EICRA,EICRA_ISC10);
		break;
	case RISING_EDGE:
		SET_BIT(EICRA,EICRA_ISC11);
		SET_BIT(EICRA,EICRA_ISC10);
		break;
	default: Local_u8ErrorState = NOK ;
	break;
	}
#else
#error "Wrong Control Sense Configuration option "
#endif
	return Local_u8ErrorState;
}

u8 EXIT_u8Int2SetSenseControl(u8 Copy_u8Sense){

	u8 Local_u8ErrorState = OK ;
#if Target == Atmega32
	switch (Copy_u8Sense) {
	case FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_INT2);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_INT2);
		break;
	default: Local_u8ErrorState = NOK ;
	break;
	}
#elif Target == Atmega128
	switch (Copy_u8Sense) {
	case LOW_LEVEL:
		CLR_BIT(EICRA,EICRA_ISC21);
		CLR_BIT(EICRA,EICRA_ISC20);
		break;
	case FALLING_EDGE:
		SET_BIT(EICRA,EICRA_ISC21);
		CLR_BIT(EICRA,EICRA_ISC20);
		break;
	case RISING_EDGE:
		SET_BIT(EICRA,EICRA_ISC21);
		SET_BIT(EICRA,EICRA_ISC20);
		break;
	default: Local_u8ErrorState = NOK ;
	break;
	}
#else
#error "Wrong Control Sense Configuration option "
#endif
	return Local_u8ErrorState;
}
u8 EXIT_u8IntEnable(u8 Copy_u8Int){
	u8 Local_u8ErrorState = OK ;
#if Target == Atmega32
	switch(Copy_u8Int){
	case 0 : SET_BIT(GICR,GICR_INT0); break ;
	case 1 : SET_BIT(GICR,GICR_INT1); break ;
	case 2 : SET_BIT(GICR,GICR_INT2); break ;
	default : Local_u8ErrorState = NOK ;
	break ;
	}
#elif Target == Atmega128
	switch(Copy_u8Int){
	case 0 : SET_BIT(EIMSK,EIMSK_INT0); break ;
	case 1 : SET_BIT(EIMSK,EIMSK_INT1); break ;
	case 2 : SET_BIT(EIMSK,EIMSK_INT2); break ;
	default : Local_u8ErrorState = NOK ; break ;
	}
#else
#error "Wrong Interrupt status Configuration option "
#endif
	return Local_u8ErrorState ;
}

u8 EXIT_u8IntDisable(u8 Copy_u8Int){
	u8 Local_u8ErrorState = OK ;
#if Target == Atmega32
	switch(Copy_u8Int){
	case 0 : CLR_BIT(GICR,GICR_INT0); break ;
	case 1 : CLR_BIT(GICR,GICR_INT1); break ;
	case 2 : CLR_BIT(GICR,GICR_INT2); break ;
	default : Local_u8ErrorState = NOK ;
	break ;
	}
#elif Target == Atmega128
	switch(Copy_u8Int){
	case 0 : CLR_BIT(EIMSK,EIMSK_INT0); break ;
	case 1 : CLR_BIT(EIMSK,EIMSK_INT1); break ;
	case 2 : CLR_BIT(EIMSK,EIMSK_INT2); break ;
	default : Local_u8ErrorState = NOK ;
	break ;
	}
#else
#error "Wrong Interrupt status Configuration option "
#endif
	return Local_u8ErrorState ;
}

u8 EXIT_u8Int0SetCallBack(void (*Copy_pvInt0Fun)(void)){
	u8 Local_u8ErrorStatus = OK ;

	if(Copy_pvInt0Fun != NULL ){
		EXIT_pvInt0Fun = Copy_pvInt0Fun ;
	}
	else {
		Local_u8ErrorStatus = NULL_POINTER ;
	}

	return Local_u8ErrorStatus ;
}

u8 EXIT_u8Int1SetCallBack(void (*Copy_pvInt1Fun)(void)){
	u8 Local_u8ErrorStatus = OK ;

	if(Copy_pvInt1Fun != NULL ){
		EXIT_pvInt1Fun = Copy_pvInt1Fun ;
	}
	else {
		Local_u8ErrorStatus = NULL_POINTER ;
	}

	return Local_u8ErrorStatus ;
}
u8 EXIT_u8Int2SetCallBack(void (*Copy_pvInt2Fun)(void)){
	u8 Local_u8ErrorStatus = OK ;

	if(Copy_pvInt2Fun != NULL ){
		EXIT_pvInt2Fun = Copy_pvInt2Fun ;
	}
	else {
		Local_u8ErrorStatus = NULL_POINTER ;
	}

	return Local_u8ErrorStatus ;
}


/* ISR of INT0 */

void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
	if(EXIT_pvInt0Fun != NULL ){
		EXIT_pvInt0Fun() ;
	}
	else{
		/* Do Nothing */
	}

}

/* ISR of INT1 */

void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
	if(EXIT_pvInt1Fun != NULL ){
		EXIT_pvInt1Fun() ;
	}
	else{
		/* Do Nothing */
	}

}

/* ISR of INT2 */

void __vector_3(void)   __attribute__((signal));
void __vector_3(void)
{
	if(EXIT_pvInt2Fun != NULL ){
		EXIT_pvInt2Fun() ;
	}
	else{
		/* Do Nothing */
	}

}

