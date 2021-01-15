/*
 * MTIMER_private.h
 *
 * Created: 24/2/2019 01:50:32 ?
 *  Author: nadai 
 */ 
#ifndef MTIMER_PRIVATE_H
#define MTIMER_PRIVATE_H


#define MTIMER_TCCR0 (*(volatile u8*)(0x53))
#define FOC0	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00 	0

#define MTIMER_TCNT0 (*(volatile u8*)(0x52))

#define MTIMER_OCR0 (*(volatile u8*)(0x5C))

#define MTIMER_TIMSK (*(volatile u8*)(0x59))
#define OCIE2	7
#define TOIE2	6
#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2
#define OCIE0	1
#define TOIE0 	0

#define MTIMER_SFIOR (*(volatile u8*)(0x50))
#define ADTS2	7
#define ADTS1	6
#define ADTS0	5
#define ACME	3
#define PUD		2
#define PSR2	1
#define PSR10 	0

#define MTIMER_TCCR1A (*(volatile u8*)(0x4F))
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10 	0

#define MTIMER_TCCR1B (*(volatile u8*)(0x4E))
#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11	1
#define CS10 	0

#define MTIMER_TCNT1H (*(volatile u8*)(0x4D))
#define MTIMER_TCNT1L (*(volatile u8*)(0x4C))

#define MTIMER_OCR1AH (*(volatile u8*)(0x4B))
#define MTIMER_OCR1AL (*(volatile u8*)(0x4A))

#define MTIMER_OCR1BH (*(volatile u8*)(0x49))
#define MTIMER_OCR1BL (*(volatile u8*)(0x48))

#define MTIMER_ICR1H (*(volatile u8*)(0x47))
#define MTIMER_ICR1L (*(volatile u8*)(0x46))

#define MTIMER_TCCR2 (*(volatile u8*)(0x45))
#define FOC2	7
#define WGM20	6
#define COM21	5
#define COM20	4
#define WGM21	3
#define CS22	2
#define CS21	1
#define CS20 	0

#define MTIMER_TCNT2 (*(volatile u8*)(0x44))

#define MTIMER_OCR2 (*(volatile u8*)(0x43))
#define MTIMER_ASSR (*(volatile u8*)(0x42))
#define AS2		3
#define TCN2UB	2
#define OCR2UB	1
#define TCR2UB 	0

#define SREG		    (*(volatile u8*)(0x5F)) // Status Register
#define IE	7


/*timers variable */
volatile u16 TIMER0_counter;
volatile u8 TIMER0_OV;

volatile u16 TIMER1_counter;

volatile u16 TIMER2_counter;
volatile u8 TIMER2_OV;
/*supporting function */
void MTIMER_init(u8 timer);
void MTIMER_SetPrescaler(u8 timer, u8 pre);//enter prescaler =2^pre
void MPWM_init_OC0();
void MPWM_init_OC1A();
void MPWM_init_OC1B();
void MPWM_init_OC2();


#endif /* MTIMER_PRIVATE_H_ */
