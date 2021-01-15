/*
 * MPWM_private.h
 *
 * Created: 24/2/2019 01:50:32 ?
 *  Author: nadai 
 */ 
#ifndef MPWM_PRIVATE_H
#define MPWM_PRIVATE_H

/*timer 0*/
#define MPWM_TCCR0A     ( *(volatile u8*)(0x44) )
#define COM0A1 7
#define COM0A0 6
#define COM0B1 5
#define COM0B0 4
#define WGM01  1
#define WGM00  0
	   
#define MPWM_TCCR0B      ( *(volatile u8*)(0x45) )  
#define FOC0A  7
#define FOC0B  6
#define WGM02  3
#define CS02   2
#define CS01   1
#define CS00   0
	   
#define MPWM_TCNT0         ( *(volatile u8*)(0x46) )
#define MPWM_OCR0A     	   ( *(volatile u8*)(0x47) )
#define MPWM_OCR0B		   ( *(volatile u8*)(0x48) ) 
#define MPWM_TIMSK0		   ( *(volatile u8*)(0x6E) )
#define OCIE0B 2
#define OCIE0A 1
#define TOIE0  0

#define MPWM_TIFR0		   ( *(volatile u8*)(0x35) )
#define OCF0B 2
#define OCF0A 1
#define TOV0  0
		
/* timer 1*/

#define MPWM_TCCR1A     ( *(volatile u8*)(0x80) )
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define WGM11  1
#define WGM10  0

#define MPWM_TCCR1B      ( *(volatile u8*)(0x81) )
#define ICNC1	7
#define ICES1   6
#define WGM13	4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define MPWM_TCCR1C      ( *(volatile u8*)(0x82) )
#define FOC1A  7
#define FOC1B  6

#define MPWM_TCNT1L        ( *(volatile u8*)(0x84) )
#define MPWM_TCNT1H   	   ( *(volatile u8*)(0x85) )
#define MPWM_ICR1L		   ( *(volatile u8*)(0x86) )
#define MPWM_ICR1H		   ( *(volatile u8*)(0x87) )
#define MPWM_OCR1AL		   ( *(volatile u8*)(0x88) )
#define MPWM_OCR1AH		   ( *(volatile u8*)(0x89) )
#define MPWM_OCR1BL		   ( *(volatile u8*)(0x8A) )
#define MPWM_OCR1BH		   ( *(volatile u8*)(0x8B) )
#define MPWM_TIMSK1		   ( *(volatile u8*)(0x6F) )
#define ICIE	5
#define OCIEB 	2
#define OCIEA 	1
#define TOIE 	0

#define MPWM_TIFR1		   ( *(volatile u8*)(0x36) )
#define ICF		5
#define OCFB 	2
#define OCFA	1
#define TOV	  	0

#endif /* MPWM_PRIVATE_H_ */
