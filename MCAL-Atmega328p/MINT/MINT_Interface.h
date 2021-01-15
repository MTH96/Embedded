/*
 * MInterrupt_Interface.h
 *
 * Created: 16/11/2018 01:53:22 م
 *  Author: Saeed Eltohamy
 */ 


#ifndef MINTERRUPT_INTERFACE_H_
#define MINTERRUPT_INTERFACE_H_


#define  LOW_LEVEL		0
#define  CHANGE_LEVEL	1
#define  FALLING_EDGE	2
#define  RISING_EDGE	3


#define INT_0	0
#define INT_1	1
/*
void MINT_ConfigureExternalInterrupt(u8 InterruptID ,u8 TriggerMode);
void MINT_EnableExternalInterrupt(u8 InterruptID) ;
void MINT_EnableAllExternalInterrupt(void);
void MINT_DiableExternalInterrupt(u8 InterruptID);
void MINT_EnableSREGInterruptBit(void);
*/
/* External interrupt configuration */
void MINT_SetExtTrigger(u8 int_no ,u8 trigger);
/* Enable All Interrupts */
void MINT_EnableAllInt(void);
/* Disable All Interrupts */
void MINT_DisableAllInt(void) ;
/* Enable external interrupt */
void MINT_enable(u8 int_no,u8 trigger);
/* Disable external interrupt */
void MINT_disable(u8 int_no);
/*make interrupt pin as float input*/
//void MINT_IntPin(u8 int_no);




#endif /* MINTERRUPT_INTERFACE_H_ */
