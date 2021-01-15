#ifndef HJOY_INTERFACE_H
#define HJOY_INTERFACE_H

volatile u8 press_1;
volatile u8 press_2;

void HJoy_init();
void HJoy_Poll();
u16 HJoy_GetPress();

#endif
