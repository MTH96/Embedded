/*
 * MDAC_interface.c
 *
 * Created: 17/11/2018 06:01:27 ص
 *  Author: mahmoud
 */ 
#include "LUTILS.h"
#include "LSTDTYPES.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MADC_private.h"
void MADC_referance(u8 v_ref)
{
	switch (v_ref)
	{
	case EXTERNAL_REF :
		/*AREF, Internal V ref turned off*/
		CLEAR_BIT(MADC_ADMUX,REFS1);
		CLEAR_BIT(MADC_ADMUX,REFS0);
		break;
	case VCC_REF :
		/*AV CC with external capacitor at AREF pin*/
		CLEAR_BIT(MADC_ADMUX,REFS1);
		SET_BIT(MADC_ADMUX,REFS0);
		break;
	case INTERNAL_1V_REF :
		/*Internal 1.1V Voltage Reference with external capacitor at AREF pin*/
		SET_BIT(MADC_ADMUX,REFS1);
		SET_BIT(MADC_ADMUX,REFS0);
		break;
	default:
		break;
	}
}
void MADC_setDirection(u8 dir)
{
	if(dir)
		SET_BIT(MADC_ADMUX,ADLAR);
	else
		CLEAR_BIT(MADC_ADMUX,ADLAR);
}
void MADC_sel_pin(u8 pin)
{
	MADC_ADMUX&=~(0xF);
	switch (pin)
	{
	case PC_0:
		/*ADC0*/
		MADC_ADMUX|=(ADC0);
		break;
	case PC_1:
		/*ADC1*/
		MADC_ADMUX|=(ADC1);
		break;
	case PC_2:
		/*ADC2*/
		MADC_ADMUX|=(ADC2);
		break;
	case PC_3:
		/*ADC3*/
		MADC_ADMUX|=(ADC3);
		break;
	case PC_4:
		/*ADC4*/
		MADC_ADMUX|=(ADC4);
		break;
	case PC_5:
		/*ADC5*/
		MADC_ADMUX|=(ADC5);
		break;
	default :
		MADC_ADMUX|=(ADC0);
		break;
	}
	
}
u16 MADC_analogRead_10Mode(u8 pin)
{
	u16 result=0;
	/*select input pin*/
	MADC_sel_pin(pin);

	/*set result direction */
	MADC_setDirection(Right_adj);

	/*ADC Enable*/
	SET_BIT(MADC_ADCSRA,ADEN);

	SET_BIT(MADC_ADCSRA,ADSC);//start conversion
	while(GET_BIT(MADC_ADCSRA,ADSC));//wait until conv end
	result = MADC_ADCL;
	result |= (MADC_ADCH<<8);
	CLEAR_BIT(MADC_ADCSRA,ADEN);//disable ADC
	return result;
	
}
u8 MADC_analogRead_8Mode(u8 pin)
{
	MADC_sel_pin(pin);//set  to pin
	MADC_setDirection(Left_adj);
	SET_BIT(MADC_ADCSRA,ADEN);//enable ADC
	SET_BIT(MADC_ADCSRA,ADSC);//start conversion
	while( GET_BIT(MADC_ADCSRA,ADSC) );//wait until conv end
	CLEAR_BIT(MADC_ADCSRA,ADEN);//disable ADC
	return MADC_ADCH;//return the value	
}
