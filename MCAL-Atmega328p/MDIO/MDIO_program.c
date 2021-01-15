#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

void MDIO_PinStatus(u8 pin, u8 status) {
	u8 portletter = pin / 8; /*0:PORTD  1:PORTB  2:PORTC*/
	u8 portpin = pin % 8; /*Determines the number of the bit in the addressed register*/
	switch (portletter) {
	/*PORTD*/
	case PD:
		switch (status) {
		case OUTPUT:
			SET_BIT(MDIO_DDRD, portpin);
			break;

		case INPUT_FLOAT:
			CLEAR_BIT(MDIO_DDRD, portpin);
			break;

		case INPUT_PULLUP:
			CLEAR_BIT(MDIO_DDRD, portpin);
			SET_BIT(MDIO_PORTD, portpin);
			break;
		}
		break;

		/*PORTB*/
	case PB:
		switch (status) {
		case OUTPUT:
			SET_BIT(MDIO_DDRB, portpin);
			break;

		case INPUT_FLOAT:
			CLEAR_BIT(MDIO_DDRB, portpin);
			break;

		case INPUT_PULLUP:
			CLEAR_BIT(MDIO_DDRB, portpin);
			SET_BIT(MDIO_PORTB, portpin);
			break;
		}
		break;

		/*PORTC*/
	case PC:
		switch (status) {
		case OUTPUT:
			SET_BIT(MDIO_DDRC, portpin);
			break;

		case INPUT_FLOAT:
			CLEAR_BIT(MDIO_DDRC, portpin);
			break;

		case INPUT_PULLUP:
			CLEAR_BIT(MDIO_DDRC, portpin);
			SET_BIT(MDIO_PORTC, portpin);
			break;
		}
		break;

	}
	return;
}

void MDIO_SetPinValue(u8 pin, u8 value) {
	u8 portletter = pin / 8; /*0:PORTD  1:PORTB  2:PORTC*/
	u8 portpin = pin % 8; /*Determines the number of the bit in the addressed register*/

	switch (portletter) {
	/*PORTD*/
	case PD:
		switch (value) {
		case HIGH:
			SET_BIT(MDIO_PORTD, portpin);
			break;

		case LOW:
			CLEAR_BIT(MDIO_PORTD, portpin);
			break;
		}
		break;

		/*PORTB*/
	case PB:
		switch (value) {
		case HIGH:
			SET_BIT(MDIO_PORTB, portpin);
			break;

		case LOW:
			CLEAR_BIT(MDIO_PORTB, portpin);
			break;
		}
		break;

		/*PORTC*/
	case PC:
		switch (value) {
		case HIGH:
			SET_BIT(MDIO_PORTC, portpin);
			break;

		case LOW:
			CLEAR_BIT(MDIO_PORTC, portpin);
			break;
		}
		break;
	}
	return;
}

u8 MDIO_GetPinValue(u8 pin) {
	u8 portletter = pin / 8; /*0:PORTD  1:PORTB  2:PORTC*/
	u8 portpin = pin % 8; /*Determines the number of the bit in the addressed register*/
	u8 value = 0;

	switch (portletter) {
	/*PORTD*/
	case PD:
		value = GET_BIT(MDIO_PIND, portpin);
		break;

		/*PORTB*/
	case PB:
		value = GET_BIT(MDIO_PINB, portpin);
		break;

		/*PORTC*/
	case PC:
		value = GET_BIT(MDIO_PINC, portpin);
		break;
	}
	return value;

}

void MDIO_TogglePinValue(u8 pin) {
	u8 portletter = pin / 8; /*0:PORTD  1:PORTB  2:PORTC*/
	u8 portpin = pin % 8; /*Determines the number of the bit in the addressed register*/

	switch (portletter) {
	/*PORTD*/
	case PD:
		TOGGLE_BIT(MDIO_PORTD, portpin);
		break;

		/*PORTB*/
	case PB:
		TOGGLE_BIT(MDIO_PORTB, portpin);
		break;

		/*PORTC*/
	case PC:
		TOGGLE_BIT(MDIO_PORTC, portpin);
		break;
	}
	return;
}
//////////////////////////////////////////
/*Initialization of DIO */
void MDIO_PortStatus(u8 port, u8 status)
{
	switch (port) {
	/*PORTD*/
	case PD:
		switch (status)
		{
		case PORT_OUTPUT:
		case INPUT_FLOAT:
			MDIO_DDRD = status;
			break;

		case INPUT_PULLUP:
			MDIO_DDRD=0x00;
			MDIO_PORTD=0xff;
			break;
		}
		break;

		/*PORTB*/
	case PB:
		switch (status)
				{
				case PORT_OUTPUT:
				case INPUT_FLOAT:
					MDIO_DDRB = status;
					break;

				case INPUT_PULLUP:
					MDIO_DDRB=0x00;
					MDIO_PORTB=0xff;
					break;
				}
				break;

		/*PORTC*/
	case PC:
		switch (status)
		{
		case PORT_OUTPUT:
		case INPUT_FLOAT:
			MDIO_DDRC = status;
			break;

		case INPUT_PULLUP:
			MDIO_DDRC=0x00;
			MDIO_PORTC=0xff;
			break;
		}
		break;
	}
	return;
}

/*Reading status of the pin*/
u8 MDIO_GetPortValue(u8 port)
{
	switch (port) {
		/*PORTD*/
		case PD:
			return MDIO_PIND;
			break;

			/*PORTB*/
		case PB:
			return MDIO_PINB;
			break;

			/*PORTC*/
		case PC:
			return MDIO_PINC;
			break;
		}
		return 0;
}

/*Setting pin value by HIGH or LOW*/
void MDIO_SetPortValue(u8 port, u8 value)
{
	switch (port) {
		/*PORTD*/
		case PD:
			MDIO_PORTD=value;
			break;

			/*PORTB*/
		case PB:
			MDIO_PORTB=value;
			break;

			/*PORTC*/
		case PC:
			MDIO_PORTC=value;
			break;
		}
	return ;
}

void MDIO_TogglePortValue(u8 port)
{
	switch (port) {
		/*PORTD*/
		case PD:
			MDIO_PORTD ^= 0xff;
			break;

			/*PORTB*/
		case PB:
			MDIO_PORTB ^= 0xff;
			break;

			/*PORTC*/
		case PC:
			MDIO_PORTC ^= 0xff;
			break;
		}
	return ;
}
