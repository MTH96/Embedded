#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

/*LCD Functions*/
void HLCD_init(void);

void HLCD_WriteCommand(u8 command);

void HLCD_WriteChar(u8 data);

void HLCD_WriteString(u8* ptr);

/*LCD Pins*/
#define HLCD_RS   PC_5
#define HLCD_RW   PC_4
#define HLCD_EN   PC_3
#define HLCD_D0   PC_2
#define HLCD_D1   PC_1
#define HLCD_D2   PC_0
#define HLCD_D3   PD_3
#define HLCD_D4   PD_4
#define HLCD_D5   PD_5
#define HLCD_D6   PD_6
#define HLCD_D7   PD_7




#endif
