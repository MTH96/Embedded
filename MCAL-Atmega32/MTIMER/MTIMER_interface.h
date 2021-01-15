#ifndef MTIMER_INTERFACE_H
#define MTIMER_INTERFACE_H

/**************************APIs function*********************/
void MTIMER_Mode(u8 timer, u8 mode);
		//timers
		#define TIMER0	0
		#define TIMER1	1
		#define TIMER2	2
		//modes
		#define PWM		0
		#define NORMAL	1

void MTIMER_Status(u8 timer, u8 status);
		//Available status
		#define stop	30
		#define start	40

u16 MTIMER_GetValue(u8 timer );
void MPWM_AnalogWrite_percent(u8 pin, u8 percent);

/****************************setting*****************************/
#define PRE		6 //means pow(2,PRE)

#endif
