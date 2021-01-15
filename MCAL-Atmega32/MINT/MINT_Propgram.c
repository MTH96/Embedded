/*
 * MINT_Propgram.c
 *
 * Created: 14/04/2019 04:54:14 م
 *  Author: Mahmoud Hashem
 */
#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "MINT_Private.h"
#include "MINT_Interface.h"
#include "MDIO_interface.h"



void MINT_SetExtTrigger(u8 int_no, u8 trigger) 
{
	switch (int_no) {
	case INT_0:
		switch (trigger)
		 {
		case LOW_LEVEL:
			CLEAR_BIT(MINT_MCUCR, ISC01);
			CLEAR_BIT(MINT_MCUCR, ISC00);
			break;
		case CHANGE_LEVEL:
			CLEAR_BIT(MINT_MCUCR, ISC01);
			SET_BIT(MINT_MCUCR, ISC00);
			break;
		case FALLING_EDGE:
			SET_BIT(MINT_MCUCR, ISC01);
			CLEAR_BIT(MINT_MCUCR, ISC00);
			break;
		case RISING_EDGE:
			SET_BIT(MINT_MCUCR, ISC01);
			SET_BIT(MINT_MCUCR, ISC00);
			break;
		}
		break;

	case INT_1:
		switch (trigger) 
		{
		case LOW_LEVEL:
			CLEAR_BIT(MINT_MCUCR, ISC11);
			CLEAR_BIT(MINT_MCUCR, ISC10);
			break;
		case CHANGE_LEVEL:
			CLEAR_BIT(MINT_MCUCR, ISC11);
			SET_BIT(MINT_MCUCR, ISC10);
			break;
		case FALLING_EDGE:
			SET_BIT(MINT_MCUCR, ISC11);
			CLEAR_BIT(MINT_MCUCR, ISC10);
			break;
		case RISING_EDGE:
			SET_BIT(MINT_MCUCR, ISC11);
			SET_BIT(MINT_MCUCR, ISC10);
			break;
		}
		break;
		
	case INT_2:
				switch (trigger) 
		{
		case FALLING_EDGE:
			SET_BIT(MINT_MCUCSR, ISC2);
			break;
		case RISING_EDGE:
			SET_BIT(MINT_MCUCSR, ISC2);
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
	SET_BIT(MINT_GICR, int_no);
	MINT_SetExtTrigger(int_no, trigger);
	
}
void MINT_disable(u8 int_no) {
	CLEAR_BIT(MINT_GICR, int_no);
}

