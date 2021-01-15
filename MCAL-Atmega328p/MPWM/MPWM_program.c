/*
 * MPWM_program.c
 *
 * Created: 2/24/2019 12:07:09 PM
 *  Author: nadai
 */
#include "LUTILS.h"
#include "LSTDTYPES.h"
#include "MPWM_private.h"
#include "MPWM_interface.h"
#include "MDIO_interface.h"

/*timer 0/1*/
void MPWM_init() {
	/* set pins output */
	MDIO_PinStatus(PD_6, OUTPUT);
	MDIO_PinStatus(PD_5, OUTPUT);
	/* set pins output */
	MDIO_PinStatus(PB_1, OUTPUT);
	MDIO_PinStatus(PB_2, OUTPUT);

	/*fast PWM 8bit*/
	SET_BIT(MPWM_TCCR0A, WGM01);
	SET_BIT(MPWM_TCCR0A, WGM00);
	CLEAR_BIT(MPWM_TCCR0B, WGM02);
	/*fast PWM 8bit */
	SET_BIT(MPWM_TCCR1A, WGM10);
	CLEAR_BIT(MPWM_TCCR1A, WGM11);
	SET_BIT(MPWM_TCCR1B, WGM12);
	CLEAR_BIT(MPWM_TCCR1B, WGM13);

	/*non inverting */
	SET_BIT(MPWM_TCCR0A, COM0A1);
	CLEAR_BIT(MPWM_TCCR0A, COM0A0);
	CLEAR_BIT(MPWM_TCCR0A, COM0B0);
	SET_BIT(MPWM_TCCR0A, COM0B1);
	/*non inverting */
	SET_BIT(MPWM_TCCR1A, COM1A1);
	CLEAR_BIT(MPWM_TCCR1A, COM1A0);
	CLEAR_BIT(MPWM_TCCR1A, COM1B0);
	SET_BIT(MPWM_TCCR1A, COM1B1);

	/* clock select	no prescalling */
	SET_BIT(MPWM_TCCR0B, CS00);
	CLEAR_BIT(MPWM_TCCR0B, CS01);
	CLEAR_BIT(MPWM_TCCR0B, CS02);
	/* clock select	no prescalling */
	SET_BIT(MPWM_TCCR1B, CS10);
	CLEAR_BIT(MPWM_TCCR1B, CS11);
	CLEAR_BIT(MPWM_TCCR1B, CS12);

	MPWM_ICR1H = 0x00;
	MPWM_ICR1L = 0xff;

	MPWM_AnalogWrite(PD_6, 0);
	MPWM_AnalogWrite(PD_5, 0);
	MPWM_AnalogWrite(PB_1, 0);
	MPWM_AnalogWrite(PB_2, 0);

}
void MPWM_AnalogWrite_percent(u8 pin, u8 percent) {
	switch (pin) {
	case PD_6:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
		}
		{
			SET_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
			MPWM_OCR0A = (percent * 255) / 100;
		}
		break;
	case PD_5:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
		} else {
			SET_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
			MPWM_OCR0B = (percent * 255) / 100;
		}
		break;
	case PB_1:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);
		} else {
			SET_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);
			MPWM_OCR1AH = 0;
			MPWM_OCR1AL = (percent * 255) / 100;
		}
		break;
	case PB_2:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);

		} else {
			SET_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);
			MPWM_OCR1BH = 0;
			MPWM_OCR1BL = (percent * 255) / 100;
		}
		break;

	}
}
void MPWM_AnalogWrite(u8 pin, u8 value) {
	switch (pin) {
	case PD_6:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
		}
		{
			SET_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
			MPWM_OCR0A = value;
		}
		break;
	case PD_5:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
		} else {
			SET_BIT(MPWM_TCCR0B, CS00);
			CLEAR_BIT(MPWM_TCCR0B, CS01);
			CLEAR_BIT(MPWM_TCCR0B, CS02);
			MPWM_OCR0B = value;
		}
		break;
	case PB_1:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);
		} else {
			SET_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);
			MPWM_OCR1AH = 0;
			MPWM_OCR1AL = value;
		}
		break;
	case PB_2:
		if (percent == 0) {
			/* clock select	no prescalling */
			CLEAR_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);

		} else {
			SET_BIT(MPWM_TCCR1B, CS10);
			CLEAR_BIT(MPWM_TCCR1B, CS11);
			CLEAR_BIT(MPWM_TCCR1B, CS12);
			MPWM_OCR1BH = 0;
			MPWM_OCR1BL = value;
		}
		break;

	}
}

