/***********************************************************************/
/***********************************************************************/
/****************************     Author : Mostafa Gamal    ************/
/****************************     Layer  : MCAL             ************/
/****************************     swc    : EXTI             ************/
/****************************     Version: 1.00             ************/
/***********************************************************************/
/***********************************************************************/


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


#define GICR                           *((volatile u8*)0X5B)
#define GICR_INT1                      7
#define GICR_INT0                      6
#define GICR_INT2                      5

#define GIFR                           *((volatile u8*)0X5A)
#define MCUCR                          *((volatile u8*)0X55)
#define MCUCR_ISC11                    3
#define MCUCR_ISC10                    2
#define MCUCR_ISC01                    1
#define MCUCR_ISC00                    0

#define MCUCSR                         *((volatile u8*)0X54)
#define MCUCSR_INT2                    6

#define EICRA                          *((volatile u8*)0X6A)
#define EICRA_ISC31                    7
#define EICRA_ISC30                    6
#define EICRA_ISC21                    5
#define EICRA_ISC20                    4
#define EICRA_ISC11                    3
#define EICRA_ISC10                    2
#define EICRA_ISC01                    1
#define EICRA_ISC00                    0

#define EIMSK                          *((volatile u8*)0X59)
#define EIMSK_INT7                     7
#define EIMSK_INT6                     6
#define EIMSK_INT5                     5
#define EIMSK_INT4                     4
#define EIMSK_INT3                     3
#define EIMSK_INT2                     2
#define EIMSK_INT1                     1
#define EIMSK_INT0                     0



#endif
