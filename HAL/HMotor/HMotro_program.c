
#include <avr/interrupt.h>
#include <math.h>

#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "HMotor_interface.h"
#include "HMotor_private.h"
#include "MDIO_interface.h"
#include "MINT_Interface.h"
#include "MTIMER_interface.h"

void HMotor_init()
{
	extern u8 speed_percent;
	extern volatile u8 INT0_status;
	extern volatile u8 INT1_status;

	//motor init
	MDIO_PinStatus(MR_DIR_1, OUTPUT);
	MDIO_PinStatus(MR_DIR_2, OUTPUT);
	MDIO_PinStatus(ML_DIR_1, OUTPUT);
	MDIO_PinStatus(ML_DIR_2, OUTPUT);
	MTIMER_Mode(TIMER1,PWM);
	speed_percent = 0;
	MPWM_AnalogWrite_percent(MR_SPEED, speed_percent);
	MPWM_AnalogWrite_percent(ML_SPEED, speed_percent);

	//encoder init
	MDIO_PinStatus(ENC_R, INPUT_PULLUP);
	MDIO_PinStatus(ENC_L, INPUT_PULLUP);

	MINT_EnableAllInt();
	MINT_enable(INT_0, LOW_LEVEL);
	MINT_enable(INT_1, LOW_LEVEL);

	MTIMER_Mode(TIMER0,NORMAL);
	MTIMER_Mode(TIMER2,NORMAL);

	MTIMER_Status(TIMER0,start);
	MTIMER_Status(TIMER2,start);

	INT0_status = ON;
	INT1_status = ON;

}

void HMotor_Dir(u8 status)
{
	extern u8 speed_percent;
	switch (status)
	{
	case FORWARD:
		MDIO_SetPinValue(MR_DIR_1, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MPWM_AnalogWrite_percent(MR_SPEED, speed_percent);
		MPWM_AnalogWrite_percent(ML_SPEED, speed_percent);
		break;
	case BACKWARD:
		MDIO_SetPinValue(MR_DIR_1, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MPWM_AnalogWrite_percent(MR_SPEED, speed_percent);
		MPWM_AnalogWrite_percent(ML_SPEED, speed_percent);
		break;
	case F_RIGHT:
		MDIO_SetPinValue(MR_DIR_1, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MPWM_AnalogWrite_percent(MR_SPEED, speed_percent);
		MPWM_AnalogWrite_percent(ML_SPEED, speed_percent / 2);
		break;
	case F_LEFT:
		MDIO_SetPinValue(MR_DIR_1, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MPWM_AnalogWrite_percent(MR_SPEED, speed_percent / 2);
		MPWM_AnalogWrite_percent(ML_SPEED, speed_percent);
		break;
	case B_RIGHT:
		MDIO_SetPinValue(MR_DIR_1, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MPWM_AnalogWrite_percent(MR_SPEED, speed_percent / 2);
		MPWM_AnalogWrite_percent(ML_SPEED, speed_percent);
		break;
	case B_LEFT:
		MDIO_SetPinValue(MR_DIR_1, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, HIGH);
		MPWM_AnalogWrite_percent(MR_SPEED, speed_percent);
		MPWM_AnalogWrite_percent(ML_SPEED, speed_percent / 2);
		break;
	case STOP:
		MDIO_SetPinValue(MR_DIR_1, LOW);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		MDIO_SetPinValue(MR_DIR_2, LOW);
		speed_percent = 0;
		MPWM_AnalogWrite_percent(MR_SPEED, speed_percent);
		MPWM_AnalogWrite_percent(ML_SPEED, speed_percent);
		break;
	default:
		break;
	}
}

void HMotor_SpeedStatus(u8 status)
{
	extern u8 speed_percent;
	switch (status)
	{
	case SPEED_UP:
		speed_percent++;
		break;
	case SPEED_DOWN:
		speed_percent--;
		break;
	case STOP:
		speed_percent = 0;
		break;
	}
}
u16 HMotor_GetSpeed(u8 motor)
{
	extern volatile u16 MR_T;
	extern volatile u16 ML_T;
switch (motor)
{
case MR:
	return (60*pow(10,3))/T_ms(MR_T);

	break;
case ML:
	return (60*pow(10,3))/T_ms(ML_T);

	break;

default :
	return 0;
	break;
}
}
ISR( INT0_vect)
{
	extern volatile u8 INT0_status;
	extern volatile u16 MR_T;
	switch (INT0_status)
	{
	case ON:
		MTIMER_Status(TIMER0, start);

		break;
	case OFF:
		MTIMER_Status(TIMER0, stop);
		MR_T=MTIMER_GetValue(TIMER0);

		break;
	}
}

ISR( INT1_vect)
{
	extern volatile u8 INT1_status;
	extern volatile u16 ML_T;
	switch (INT1_status)
	{
	case ON:
			MTIMER_Status(TIMER2, start);

			break;
		case OFF:
			MTIMER_Status(TIMER2, stop);
			ML_T=MTIMER_GetValue(TIMER2);

			break;
	}
}

