/*
 * MADC_private.h
 *
 * Created: 17/11/2018 06:04:15 ص
 *  Author: mahmoud
 */ 


#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_


#define MADC_ADMUX      (*(volatile u8*)(0x7C))
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define MADC_ADCSRA     (*(volatile u8*)(0x7A))
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define MADC_ADCSRB     (*(volatile u8*)(0x7B))
#define ACME	6
#define ADTS2	2
#define ADTS1	1
#define ADTS0	0

#define MADC_ADCL       (*(volatile u8*)(0x78))
#define MADC_ADCH       (*(volatile u8*)(0x79))
#define MADC_DIDR0      (*(volatile u8*)(0x7E))


#endif /* MADC_PRIVATE_H_ */
