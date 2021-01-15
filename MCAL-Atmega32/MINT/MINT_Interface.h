/*
 * MINT_Interface.h
 *
 * Created: 14/04/2019 04:54:14 م
 *  Author: Mahmoud Hashem
 */

#ifndef MINTERRUPT_INTERFACE_H_
#define MINTERRUPT_INTERFACE_H_

/*modes of operation */
#define  LOW_LEVEL		0
#define  CHANGE_LEVEL	1
#define  FALLING_EDGE	2
#define  RISING_EDGE	3
/************************************************************************/
/* INT_0 &INT_1 support all the forth mode								*/
/* but INT_2 support only (FALLING_EDGE,  RISING_EDGE)                  */
/************************************************************************/

#define INT_0	6
#define INT_1	7
#define INT_2	5
/************************************************************************/
/* APIs functions									                    */
/************************************************************************/

/* Enable All Interrupts */
void MINT_EnableAllInt(void);

/* Disable All Interrupts */
void MINT_DisableAllInt(void) ;

/* Enable external interrupt */
void MINT_enable(u8 int_no,u8 trigger);

/* Disable external interrupt */
void MINT_disable(u8 int_no);


/************************************************************************/
/* supporting functions                                                 */
/************************************************************************/

/* External interrupt configuration */
void MINT_SetExtTrigger(u8 int_no ,u8 trigger);





#endif /* MINTERRUPT_INTERFACE_H_ */
