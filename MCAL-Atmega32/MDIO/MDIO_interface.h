#ifndef _MDIO_INTERFACE_H
#define _MDIO_INTERFACE_H

/*Initialization of DIO */
void MDIO_PinStatus(u8 pin, u8 status);

/*Reading status of the pin*/
u8 MDIO_GetPinValue(u8 pin);

/*Setting pin value by HIGH or LOW*/
void MDIO_SetPinValue(u8 pin, u8 value);
void MDIO_TogglePinValue(u8 pin);
//////////////////////////////////////////
/*Initialization of DIO */
void MDIO_PortStatus(u8 port, u8 status);

/*Reading status of the pin*/
u8 MDIO_GetPortValue(u8 port);

/*Setting pin value by HIGH or LOW*/
void MDIO_SetPortValue(u8 port, u8 value);

void MDIO_TogglePortValue(u8 port);

/*Pin status Defintions*/
#define OUTPUT 		    1
#define INPUT_FLOAT  	2
#define INPUT_PULLUP    3

#define PORT_OUTPUT 		0xff
#define PORT_INPUT_FLOAT  	0x00
#define PORT_INPUT_PULLUP   1

#define PA   0
#define PB	1
#define PC	2
#define PD	3
/*Pin OUTPUT Conditions*/
#define HIGH            1
#define LOW             0
#define PORT_HIGH 	0xff
#define PORT_LOW	0x00

/*PORTS Digital Pins*/
#define PA_0	0
#define PA_1	1
#define PA_2	2
#define PA_3	3
#define PA_4	4
#define PA_5	5
#define PA_6	6
#define PA_7	7

#define PB_0	8
#define PB_1	9
#define PB_2	10
#define PB_3	11
#define PB_4	12
#define PB_5	13
#define PB_6	14
#define PB_7	15

#define PC_0	16
#define PC_1	17
#define PC_2	18
#define PC_3	19
#define PC_4	20
#define PC_5	21
#define PC_6	22
#define PC_7	23

#define PD_0	24
#define PD_1	25
#define PD_2	26
#define PD_3	27
#define PD_4	28
#define PD_5	29
#define PD_6	30
#define PD_7	31

#endif
