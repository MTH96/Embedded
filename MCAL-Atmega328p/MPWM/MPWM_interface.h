
/*
 * MPWM_interface.h
 *
 * Created: 24/2/2019 01:50:32 ?
 *  Author: nadai 
 */ 
#ifndef MPWM_INTERFACE_H
#define MPWM_INTERFACE_H

void MPWM_init();

void MPWM_AnalogWrite_percent(u8 pin , u8 percent);
void MPWM_AnalogWrite(u8 pin , u8 value);
#endif
