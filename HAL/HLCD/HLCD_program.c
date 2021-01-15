#include "LUTILS.h"
#include "LSTDTYPES.h"
#include "MDIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"

#define F_CPU  16000000UL
#include <util/delay.h>

void HLCD_init(void)
{
	MDIO_pinStatus(HLCD_RS,OUTPUT);
	MDIO_pinStatus(HLCD_RW,OUTPUT);
	MDIO_pinStatus(HLCD_EN,OUTPUT);
	MDIO_pinStatus(HLCD_D0,OUTPUT);
	MDIO_pinStatus(HLCD_D1,OUTPUT);
	MDIO_pinStatus(HLCD_D2,OUTPUT);
	MDIO_pinStatus(HLCD_D3,OUTPUT);
	MDIO_pinStatus(HLCD_D4,OUTPUT);
	MDIO_pinStatus(HLCD_D5,OUTPUT);
	MDIO_pinStatus(HLCD_D6,OUTPUT);
	MDIO_pinStatus(HLCD_D7,OUTPUT);
	
	_delay_ms(50);
	HLCD_WriteCommand(0b00111100);
	_delay_ms(2);
	HLCD_WriteCommand(0b00001111);
	_delay_ms(2);
	HLCD_WriteCommand(1);
	_delay_ms(5);
	HLCD_WriteCommand(0b00000110);
	
	return;	
}
void HLCD_WriteCommand(u8 command)
{
	MDIO_SetPinValue(HLCD_RS,LOW);
	MDIO_SetPinValue(HLCD_RW,LOW);
	
	MDIO_SetPinValue(HLCD_D0,GET_BIT(command,0));
	MDIO_SetPinValue(HLCD_D1,GET_BIT(command,1));
	MDIO_SetPinValue(HLCD_D2,GET_BIT(command,2));
	MDIO_SetPinValue(HLCD_D3,GET_BIT(command,3));
	MDIO_SetPinValue(HLCD_D4,GET_BIT(command,4));
	MDIO_SetPinValue(HLCD_D5,GET_BIT(command,5));
	MDIO_SetPinValue(HLCD_D6,GET_BIT(command,6));
	MDIO_SetPinValue(HLCD_D7,GET_BIT(command,7));
	
	
	MDIO_SetPinValue(HLCD_EN,HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(HLCD_EN,LOW);
	return;
}
void HLCD_WriteChar(u8 data)
{
	MDIO_SetPinValue(HLCD_RS,HIGH);
	MDIO_SetPinValue(HLCD_RW,LOW);
		
	MDIO_SetPinValue(HLCD_D0,GET_BIT(data,0));
	MDIO_SetPinValue(HLCD_D1,GET_BIT(data,1));
	MDIO_SetPinValue(HLCD_D2,GET_BIT(data,2));
	MDIO_SetPinValue(HLCD_D3,GET_BIT(data,3));
	MDIO_SetPinValue(HLCD_D4,GET_BIT(data,4));
	MDIO_SetPinValue(HLCD_D5,GET_BIT(data,5));
	MDIO_SetPinValue(HLCD_D6,GET_BIT(data,6));
	MDIO_SetPinValue(HLCD_D7,GET_BIT(data,7));
				
	MDIO_SetPinValue(HLCD_EN,HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(HLCD_EN,LOW);
	return;
}
void HLCD_WriteString(u8* ptr)
{
	return;
}
