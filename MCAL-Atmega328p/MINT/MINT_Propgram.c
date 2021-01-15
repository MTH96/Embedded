/*
 * MInterrupt_Propgram.c
 *
 * Created: 16/11/2018 01:54:14 م
 *  Author: Saeed Eltohamy
 */
#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "MINT_Private.h"
#include "MINT_Interface.h"
#include "MDIO_interface.h"

/*
 void MINT_EnableAllExternalInterrupt(void){
 MINT_EIMSK |= (INT0 <<1 );
 MINT_EIMSK |= (INT1 <<1 );
 return ;
 }

 void MINT_EnableExternalInterrupt(u8 InterruptID){
 MINT_EIMSK |= (InterruptID << 1 );
 }

 void MINT_DiableExternalInterrupt(u8 InterruptID){
 MINT_EIMSK |= (InterruptID << 0 );
 }

 void MINT_ConfigureExternalInterrupt(u8 InterruptID ,u8 TriggerMode){
 if(InterruptID == INT0 ){
 MINT_EICRA |= (MINT_EICRA_INT0_MASK & TriggerMode);
 MINT_EICRA |= (MINT_EICRA_INT0_MASK & TriggerMode);
 }
 else if (InterruptID == INT1 ){
 MINT_EICRA |= (MINT_EICRA_INT1_MASK & TriggerMode);
 }
 }

 void MINT_EnableSREGInterruptBit(void){
 SET_BIT(SREG,7);
 }

 */
////////////////////////////////////////////////////////////////////////////////////
void MINT_SetExtTrigger(u8 int_no, u8 trigger) {
	switch (int_no) {
	case INT_0:

		switch (trigger) {
		case LOW_LEVEL:
			CLEAR_BIT(MINT_EICRA, ISC01);
			CLEAR_BIT(MINT_EICRA, ISC00);
			break;
		case CHANGE_LEVEL:
			CLEAR_BIT(MINT_EICRA, ISC01);
			SET_BIT(MINT_EICRA, ISC00);
			break;
		case FALLING_EDGE:
			SET_BIT(MINT_EICRA, ISC01);
			CLEAR_BIT(MINT_EICRA, ISC00);
			break;
		case RISING_EDGE:
			SET_BIT(MINT_EICRA, ISC01);
			SET_BIT(MINT_EICRA, ISC00);
			break;
		}
		break;

	case INT_1:
		switch (trigger) {
		case LOW_LEVEL:
			CLEAR_BIT(MINT_EICRA, ISC11);
			CLEAR_BIT(MINT_EICRA, ISC10);
			break;
		case CHANGE_LEVEL:
			CLEAR_BIT(MINT_EICRA, ISC11);
			SET_BIT(MINT_EICRA, ISC10);
			break;
		case FALLING_EDGE:
			SET_BIT(MINT_EICRA, ISC11);
			CLEAR_BIT(MINT_EICRA, ISC10);
			break;
		case RISING_EDGE:
			SET_BIT(MINT_EICRA, ISC11);
			SET_BIT(MINT_EICRA, ISC10);
			break;
		}
		break;
	}
}
void MINT_EnableAllInt(void) {
	/*set IE interrupt enable in status reg */
	SET_BIT(SREG, IE);
}
void MINT_DisableAllInt(void) {
	/*set IE interrupt enable in status reg */
	CLEAR_BIT(SREG, IE);
}
void MINT_enable(u8 int_no, u8 trigger) {
	SET_BIT(MINT_EIMSK, int_no);
	MINT_SetExtTrigger(int_no, trigger);
	//MINT_IntPin(int_no);
}
void MINT_disable(u8 int_no) {
	CLEAR_BIT(MINT_EIMSK, int_no);
}
/*
void MINT_IntPin(u8 int_no) {
	switch (int_no) {
	case INT_0:
		MDIO_PinStatus(PD_2, INPUT_FLOAT);
		break;
	case INT_1:
		MDIO_PinStatus(PD_3, INPUT_FLOAT);
		break;
	}
}

*/
