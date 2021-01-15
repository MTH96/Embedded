/*
 * MADC_interface.h
 *
 * Created: 17/11/2018 06:02:21 ص
 *  Author: mahmoud
 */ 


#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_
/************************************************************************/
/*                      MADC_ADMUX Register                                                */
/************************************************************************/
#define EXTERNAL_REF      0
#define VCC_REF		      1
#define INTERNAL_1V_REF   2

#define Right_adj	0
#define Left_adj	1

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7
#define TEMP_SENS 8

/****************APIS***********/
void MADC_referance(u8 v_ref);
u16 MADC_analogRead_10Mode(u8 pin);
u8 MADC_analogRead_8Mode(u8 pin);

/**********supportive function**********/

void MADC_setDirection(u8 dir);
void MADC_sel_pin(u8 pin);



#endif /* MADC_INTERFACE_H_ */