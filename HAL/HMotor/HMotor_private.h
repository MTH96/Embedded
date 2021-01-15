#ifndef HMOTOR_PRIVATE_H
#define HMOTOR_PRIVATE_H




/*supporting */
#define ON 		1
#define OFF		0


u8 speed_percent;
volatile u8 INT0_status;
volatile u8 INT1_status;

volatile u16 MR_T;
volatile u16 ML_T;

#endif
