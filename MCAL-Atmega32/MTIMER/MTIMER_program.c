#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"
#include "MTIMER_private.h"
#include <avr/interrupt.h>

void MTIMER_Mode(u8 timer, u8 mode)
{
	switch (timer)
	{
	case TIMER0:
		switch (mode)
		{
		case PWM:
			MPWM_init_OC0();
			break;
		case NORMAL:
			MTIMER_init(TIMER0);
			break;
		}
		break;
	case TIMER1:
		switch (mode)
		{
		case PWM:
			MPWM_init_OC1A();
			MPWM_init_OC1B();
			break;
		case NORMAL:
			MTIMER_init(TIMER1);
			break;
		}
		break;
	case TIMER2:
		switch (mode)
		{
		case PWM:
			MPWM_init_OC2();
			break;
		case NORMAL:
			MTIMER_init(TIMER2);
			break;
		}
		break;
	}
}

void MTIMER_init(u8 timer)
{
	switch (timer)
	{
	case TIMER0:
		/*set Normal mode*/
		CLEAR_BIT(MTIMER_TCCR0, WGM20);
		CLEAR_BIT(MTIMER_TCCR0, WGM21);
		/*Normal port operation*/
		CLEAR_BIT(MTIMER_TCCR0, COM21);
		CLEAR_BIT(MTIMER_TCCR0, COM20);
		/*timer 2 overflow interrupt */
		SET_BIT(SREG, IE);
		SET_BIT(MTIMER_TIMSK, TOIE0);
		/*clear timer counter */
		MTIMER_SetPrescaler(TIMER0, stop);
		MTIMER_TCNT0 = 0;

		break;
	case TIMER1:
		/*set Normal mode*/
		CLEAR_BIT(MTIMER_TCCR1A, WGM10);
		CLEAR_BIT(MTIMER_TCCR1A, WGM11);
		CLEAR_BIT(MTIMER_TCCR1B, WGM12);
		CLEAR_BIT(MTIMER_TCCR1B, WGM13);
		/*Normal port operation*/
		CLEAR_BIT(MTIMER_TCCR1A, COM1A1);
		CLEAR_BIT(MTIMER_TCCR1A, COM1A0);
		CLEAR_BIT(MTIMER_TCCR1A, COM1B1);
		CLEAR_BIT(MTIMER_TCCR1A, COM1B0);
		MTIMER_SetPrescaler(TIMER1, stop);

		/*clear timer counter */
		MTIMER_SetPrescaler(TIMER1, stop);
		MTIMER_TCNT1L = 0;
		MTIMER_TCNT1H = 0;
		break;
	case TIMER2:
		/*set Normal mode*/
		CLEAR_BIT(MTIMER_TCCR2, WGM20);
		CLEAR_BIT(MTIMER_TCCR2, WGM21);
		/*Normal port operation*/
		CLEAR_BIT(MTIMER_TCCR2, COM21);
		CLEAR_BIT(MTIMER_TCCR2, COM20);
		/*timer 2 overflow interrupt */
		SET_BIT(SREG, IE);
		SET_BIT(MTIMER_TIMSK, TOIE2);
		/*clear timer counter */
		MTIMER_SetPrescaler(TIMER2, stop);
		MTIMER_TCNT2 = 0;

		break;
	}

}
//enter prescaler =2^pre
void MTIMER_SetPrescaler(u8 timer, u8 pre)
{
	switch (timer)
	{
	case TIMER0:
		switch (pre)
		{
		case stop:

			CLEAR_BIT(MTIMER_TCCR0, CS02);
			CLEAR_BIT(MTIMER_TCCR0, CS01);
			CLEAR_BIT(MTIMER_TCCR0, CS00);
			break;
		case 0:

			CLEAR_BIT(MTIMER_TCCR0, CS02);
			CLEAR_BIT(MTIMER_TCCR0, CS01);
			SET_BIT(MTIMER_TCCR0, CS00);
			break;
		case 3:

			CLEAR_BIT(MTIMER_TCCR0, CS02);
			SET_BIT(MTIMER_TCCR0, CS01);
			CLEAR_BIT(MTIMER_TCCR0, CS00);
			break;
		case 6:

			CLEAR_BIT(MTIMER_TCCR0, CS02);
			SET_BIT(MTIMER_TCCR0, CS01);
			SET_BIT(MTIMER_TCCR0, CS00);
			break;
		case 8:

			SET_BIT(MTIMER_TCCR0, CS02);
			CLEAR_BIT(MTIMER_TCCR0, CS01);
			CLEAR_BIT(MTIMER_TCCR0, CS00);
			break;
		case 10:

			SET_BIT(MTIMER_TCCR0, CS02);
			CLEAR_BIT(MTIMER_TCCR0, CS01);
			SET_BIT(MTIMER_TCCR0, CS00);
			break;

		}

		break;
	case TIMER1:
		switch (pre)
		{
		case stop:

			CLEAR_BIT(MTIMER_TCCR1B, CS12);
			CLEAR_BIT(MTIMER_TCCR1B, CS11);
			CLEAR_BIT(MTIMER_TCCR1B, CS10);
			break;
		case 0:

			CLEAR_BIT(MTIMER_TCCR1B, CS12);
			CLEAR_BIT(MTIMER_TCCR1B, CS11);
			SET_BIT(MTIMER_TCCR1B, CS10);
			break;
		case 3:

			CLEAR_BIT(MTIMER_TCCR1B, CS12);
			SET_BIT(MTIMER_TCCR1B, CS11);
			CLEAR_BIT(MTIMER_TCCR1B, CS10);
			break;
		case 6:

			CLEAR_BIT(MTIMER_TCCR1B, CS12);
			SET_BIT(MTIMER_TCCR1B, CS11);
			SET_BIT(MTIMER_TCCR1B, CS10);
			break;
		case 8:

			SET_BIT(MTIMER_TCCR1B, CS12);
			CLEAR_BIT(MTIMER_TCCR1B, CS11);
			CLEAR_BIT(MTIMER_TCCR1B, CS10);
			break;
		case 10:

			SET_BIT(MTIMER_TCCR1B, CS12);
			CLEAR_BIT(MTIMER_TCCR1B, CS11);
			SET_BIT(MTIMER_TCCR1B, CS10);
			break;

		}

		break;
	case TIMER2:
		switch (pre)
		{
		case stop:

			CLEAR_BIT(MTIMER_TCCR2, CS22);
			CLEAR_BIT(MTIMER_TCCR2, CS21);
			CLEAR_BIT(MTIMER_TCCR2, CS20);
			break;
		case 0:

			CLEAR_BIT(MTIMER_TCCR2, CS22);
			CLEAR_BIT(MTIMER_TCCR2, CS21);
			SET_BIT(MTIMER_TCCR2, CS20);
			break;
		case 3:

			CLEAR_BIT(MTIMER_TCCR2, CS22);
			SET_BIT(MTIMER_TCCR2, CS21);
			CLEAR_BIT(MTIMER_TCCR2, CS20);
			break;
		case 6:

			CLEAR_BIT(MTIMER_TCCR2, CS22);
			SET_BIT(MTIMER_TCCR2, CS21);
			SET_BIT(MTIMER_TCCR2, CS20);
			break;
		case 8:

			SET_BIT(MTIMER_TCCR2, CS22);
			CLEAR_BIT(MTIMER_TCCR2, CS21);
			CLEAR_BIT(MTIMER_TCCR2, CS20);
			break;
		case 10:

			SET_BIT(MTIMER_TCCR2, CS22);
			CLEAR_BIT(MTIMER_TCCR2, CS21);
			SET_BIT(MTIMER_TCCR2, CS20);
			break;

		}

		break;
	}

}
void MTIMER_Status(u8 timer, u8 status)
{
	extern volatile u16 TIMER0_counter;
	extern volatile u8 TIMER0_OV;

	extern volatile u16 TIMER1_counter;

	extern volatile u16 TIMER2_counter;
	extern volatile u8 TIMER2_OV;

	switch (timer)
	{
	case TIMER0:
		switch (status)
		{
		case start:
			MTIMER_TCNT0 = 0;
			TIMER0_counter = 0;
			TIMER0_OV = 0;
			MTIMER_SetPrescaler(TIMER0, PRE);
			break;
		case stop:
			MTIMER_SetPrescaler(TIMER0, stop);
			break;
		}
		break;

	case TIMER1:
		switch (status)
		{
		case start:
			MTIMER_TCNT1L = 0;
			MTIMER_TCNT1H = 0;
			TIMER1_counter = 0;
			MTIMER_SetPrescaler(TIMER1, PRE);
			break;
		case stop:
			MTIMER_SetPrescaler(TIMER1, stop);
			break;

		}
		break;

	case TIMER2:
		switch (status)
		{
		case start:
			MTIMER_TCNT2 = 0;
			TIMER2_counter = 0;
			TIMER2_OV = 0;
			MTIMER_SetPrescaler(TIMER2, PRE);
			break;
		case stop:
			MTIMER_SetPrescaler(TIMER2, stop);
			break;
		}
		break;
	}
}
u16 MTIMER_GetValue(u8 timer)
{
	extern volatile u16 TIMER0_counter;
	extern volatile u8 TIMER0_OV;

	extern volatile u16 TIMER1_counter;

	extern volatile u16 TIMER2_counter;
	extern volatile u8 TIMER2_OV;

	switch (timer)
	{
	case TIMER0:
		TIMER0_counter = MTIMER_TCNT0 + (TIMER0_OV << 8);
		return TIMER0_counter;
		break;

	case TIMER1:
		TIMER1_counter = MTIMER_TCNT1H << 8;
		TIMER1_counter |= MTIMER_TCNT1L;
		return TIMER1_counter;
		break;

	case TIMER2:
		TIMER2_counter = MTIMER_TCNT2 + (TIMER2_OV << 8);
		return TIMER2_counter;
		break;
	default:
		return 0;
		break;
	}

}
ISR( TIMER0_OVF_vect)
{
	extern volatile u8 TIMER0_OV;
	TIMER0_OV++;
}
ISR( TIMER2_OVF_vect)
{
	extern volatile u8 TIMER2_OV;
	TIMER2_OV++;
}

void MPWM_init_OC0()
{
	MDIO_PinStatus(PB_3, OUTPUT);
	/*set Fast PWM*/
	SET_BIT(MTIMER_TCCR0, WGM01);
	SET_BIT(MTIMER_TCCR0, WGM00);

	/*non-inverting mode*/
	SET_BIT(MTIMER_TCCR0, COM01);
	CLEAR_BIT(MTIMER_TCCR0, COM00);

	/*Clock Select (No prescaling) */
	MTIMER_SetPrescaler(TIMER0, stop);

	MPWM_AnalogWrite_percent(PB_3, 0);
}

void MPWM_init_OC1A()
{
	MDIO_PinStatus(PD_5, OUTPUT); //OC1A
	/*set Fast PWM*/
	SET_BIT(MTIMER_TCCR1A, WGM10);
	CLEAR_BIT(MTIMER_TCCR1A, WGM11);
	SET_BIT(MTIMER_TCCR1B, WGM12);
	CLEAR_BIT(MTIMER_TCCR1B, WGM13);
	/*non-inverting mode*/
	SET_BIT(MTIMER_TCCR1A, COM1A1);
	CLEAR_BIT(MTIMER_TCCR1A, COM1A0);

	/*Clock Select (No prescaling) */
	MTIMER_SetPrescaler(TIMER1, stop);

	MPWM_AnalogWrite_percent(PD_5, 0);
}

void MPWM_init_OC1B()
{
	MDIO_PinStatus(PD_4, OUTPUT); //OC1B
	/*set Fast PWM*/
	SET_BIT(MTIMER_TCCR1A, WGM10);
	CLEAR_BIT(MTIMER_TCCR1A, WGM11);
	SET_BIT(MTIMER_TCCR1B, WGM12);
	CLEAR_BIT(MTIMER_TCCR1B, WGM13);
	/*non-inverting mode*/
	SET_BIT(MTIMER_TCCR1A, COM1B1);
	CLEAR_BIT(MTIMER_TCCR1A, COM1B0);

	/*Clock Select (No prescaling) */
	MTIMER_SetPrescaler(TIMER1, stop);

	MPWM_AnalogWrite_percent(PD_4, 0);
}

void MPWM_init_OC2()
{
	MDIO_PinStatus(PD_7, OUTPUT);
	/*set Fast PWM*/
	SET_BIT(MTIMER_TCCR2, WGM21);
	SET_BIT(MTIMER_TCCR2, WGM20);

	/*non-inverting mode*/
	SET_BIT(MTIMER_TCCR2, COM21);
	CLEAR_BIT(MTIMER_TCCR2, COM20);

	/*Clock Select (No prescaling) */
	MTIMER_SetPrescaler(TIMER2, stop);

	MPWM_AnalogWrite_percent(PD_7, 0);
}
void MPWM_AnalogWrite_percent(u8 pin, u8 percent)
{
	switch (pin)
	{
	/*OC0 case*/
	case PB_3:
		if (!percent) //percent ==0
		{
			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER0, stop);
			MTIMER_OCR0 = 0;
		}
		else
		{

			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER0, 0);
			MTIMER_OCR0 = (u8) ((percent * 255) / 100);
		}

		break;
		/*OC2 case*/
	case PD_7:
		/*Clock Select (No prescaling) */

		if (!percent) //percent ==0
		{
			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER2, stop);
			MTIMER_OCR2 = 0;
		}
		else
		{

			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER2, 0);
			MTIMER_OCR2 = (u8) ((percent * 255) / 100);
		}

		break;
	case PD_4:

		if (!percent) //percent ==0
		{
			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER1, stop);
			MTIMER_OCR1BL = 0;
			MTIMER_OCR1BH = 0;
		}
		else
		{

			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER1, 0);
			MTIMER_OCR1BL = (u8) ((percent * 255) / 100);
			MTIMER_OCR1BH = 0;
		}
		break;
	case PD_5:

		if (!percent) //percent ==0
		{
			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER1, stop);
			MTIMER_OCR1AL = 0;
			MTIMER_OCR1AH = 0;
		}
		else
		{

			/*Clock Select (No prescaling) */
			MTIMER_SetPrescaler(TIMER1, 0);
			MTIMER_OCR1AL = (u8) ((percent * 255) / 100);
			MTIMER_OCR1AH = 0;
		}
		break;
	default:
		break;
	}
}
