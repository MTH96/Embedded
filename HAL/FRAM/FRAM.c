/*
 * HFM25V01.c
 *
 * Created: 27/06/2020 03:56:54 م
 *  Author: ENG
 */ 
#include <stdint.h>
#include <stdlib.h>
#include "uc_configuration.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "FRAM.h"


void FRAM_init()
{
  SPI0.DataOrder = MSB_first;
  SPI0.EnableMode = SPI_MasterMode;
  SPI0.InterruptState = SPI_InterruptDisable;
  SPI0.ClockDivider = FCPU_2;
  SPI0.ClockMode = SPI_mode_0 ;
  
  SPI_init();
  FRAM_WriteStatus(0x00);
    
}
uint8_t FRAM_ReadStatus( void)
{
  uint8_t data=0;
  SPI_SlectSlave(SS0);
  SPI_ReadWrite_Blocing(RDSR);
  data= SPI_ReadWrite_Blocing(0);
 // data= SPI_ReadWrite_Blocing(0);
  SPI_LeaveSlave(SS0);
  return data;
}
void FRAM_WriteStatus(uint8_t data)
{
  /* (CS LOW)(WREN)(WRSR)(data)	(WRDI) (HIGH CS)*/
  SPI_SlectSlave(SS0);
  SPI_ReadWrite_Blocing(WREN);
  SPI_ReadWrite_Blocing(WRSR);
  SPI_ReadWrite_Blocing(data);
  SPI_ReadWrite_Blocing(WRDI);
SPI_LeaveSlave(SS0);
 
  
}
uint8_t* FRAM_ReadData(uint16_t address ,uint8_t num_bytes)
{
  uint8_t *data_ptr = NULL;
  free(data_ptr);
  data_ptr =(uint8_t *) malloc(sizeof(uint8_t)*num_bytes);
  uint8_t counter; /*used to counter into the dynamic array*/
  
  SPI_SlectSlave(SS0);
  SPI_ReadWrite_Blocing(READ);
  SPI_ReadWrite_Blocing( (address>>8) );
  SPI_ReadWrite_Blocing( (uint8_t)address );
 for (counter =0 ;counter<num_bytes;counter++)
 {
  data_ptr[counter] = SPI_ReadWrite_Blocing(0x00);
 }
  SPI_LeaveSlave(SS0);
  
   return data_ptr;
  
}
void FRAM_WriteEnable(void)
{
	SPI_SlectSlave(SS0);
	SPI_ReadWrite_Blocing(WREN);
	SPI_LeaveSlave(SS0);
}
void FRAM_WriteDisable(void)
{
	  
	  SPI_SlectSlave(SS0);
	  SPI_ReadWrite_Blocing(WRDI);
	  SPI_LeaveSlave(SS0);
}
void FRAM_WriteData(uint16_t address ,uint8_t* data)
{
       uint8_t counter=0; /*used to counter into the dynamic array*/
    /*(CS LOW)	(WREN)				(WRITE)		(2 bytes address)(A13-A0)	(data_0..data_n)	(HIGH CS)  (CS LOW)	(WRDI) (CS HIGH)*/
  
	  SPI_SlectSlave(SS0);
     SPI_ReadWrite_Blocing(WRITE);
    SPI_ReadWrite_Blocing(  (uint8_t)(address>>8) );
    SPI_ReadWrite_Blocing( (uint8_t)address );
    while (data[counter] != '\0')
    {
      SPI_ReadWrite_Blocing(data[counter]);
      counter++;
    }
    SPI_LeaveSlave(SS0);
  
}
void FRAM_Sleep();
