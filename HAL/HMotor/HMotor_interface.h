#ifndef HMOTOR_INTERFACE_H
#define HMOTOR_INTERFACE_H



		/*****************************motor interface***************************/
/*motors pins */
#define MR_SPEED	PD_5
#define MR_DIR_1	PD_6
#define MR_DIR_2	PD_7

#define ML_SPEED	PD_4
#define ML_DIR_1	PB_7
#define ML_DIR_2	PB_6

/*encoder pins*/
#define ENC_R		PD_2
#define ENC_L		PD_3

		/********************************Driver APIs*****************************/
void HMotor_init();
void HMotor_Dir(u8 status);
		/*motor Dir*/
		#define FORWARD		0
		#define BACKWARD	1
		#define F_RIGHT		2
		#define F_LEFT		3
		#define B_RIGHT		4
		#define B_LEFT		5
		#define STOP		6

void HMotor_SpeedStatus(u8 status);
		/*speed state*/
		#define SPEED_UP	1
		#define SPEED_DOWN	2

u16 HMotor_GetSpeed(u8 motor);
		/*motors names */
		#define MR	0
		#define ML	1

#define T_ms(T)   ( (T*pow(2,PRE)) / F_CPU )

#endif
