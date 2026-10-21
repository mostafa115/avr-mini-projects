/***********************************************************************/
/***********************************************************************/
/****************************     Author : Mostafa Gamal    ************/
/****************************     Layer  : MCAL             ************/
/****************************     swc    : EXTI             ************/
/****************************     Version: 1.00             ************/
/***********************************************************************/
/***********************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define  LOW_LEVEL		1
#define  ON_CHANGE      2
#define  FALLING_EDGE   3
#define  RISING_EDGE	4


void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

/* Description : A function to Set the required sense control of INT0 using Postbuild configuration
 input : Copy_u8Sense , Options are  1- LOW_LEVEL
  	  	  	  	  	  	  	  	  	 2- ON_CHANGE
  	  	  	  	  	  	  	  	  	 3- FALLING_EDGE
  	  	  	  	  	  	  	  	  	 4- RISING_EDGE
 ouput: Error status with type u8
  */

u8 EXIT_u8Int0SetSenseControl(u8 Copy_u8Sense);
u8 EXIT_u8Int1SetSenseControl(u8 Copy_u8Sense);
u8 EXIT_u8Int2SetSenseControl(u8 Copy_u8Sense);

/* Description : A function to Enable the interrupt
 * Input : number of interrupt , Options : 1- 0 For INT0
 * 										   2- 1 For INT1
 * 										   3- 2 For INT2
 * ouput: Error status with type u8
 */
u8 EXIT_u8IntEnable(u8 Copy_u8Int);
u8 EXIT_u8IntDisable(u8 Copy_u8Int);

u8 EXIT_u8Int0SetCallBack(void (*Copy_pvInt0Fun)(void));
u8 EXIT_u8Int1SetCallBack(void (*Copy_pvInt0Fun)(void));
u8 EXIT_u8Int2SetCallBack(void (*Copy_pvInt0Fun)(void));

#endif
