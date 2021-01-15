/*
 * HFM25V01.h
 *
 * Created: 27/06/2020 03:57:11 م
 *  Author: ENG
 */ 


#ifndef HFM25V01_H_
#define HFM25V01_H_


/***
* size 128 Kb
* no delay writes
* SPI clock 40MHZ
* SPI mode 0/3
* MSB first
* write protection in WP`
* Write disable instruction
Name		 Description			 Opcode
WREN     Set write enable latch		0000 0110b
WRDI	 Reset write enable latch	0000 0100b
RDSR	 Read Status Register		0000 0101b
WRSR	 Write Status Register		0000 0001b
READ	 Read memory data			0000 0011b
FSTRD	 Fast read memory data		0000 1011b
WRITE	 Write memory data			0000 0010b
SLEEP	 Enter sleep mode			1011 1001b
RDID	 Read device ID				1001 1111b
*/
/*

Status reg:
bit(1) ( WEL(0) )	WEL indicates if the device is write enabled. This bit defaults to ‘0’ (disabled) on power-up.
				WEL = '1' --> Write enabled
				WEL = '0' --> Write disabled
				
bit(2) ( BP0(0) )	Used for block protection
bit(3) ( BP1(0) )	Used for block protection
	 Block Memory Write Protection
	BP1	 BP0		 Protected Address Range
	0	 0				 None
	0	 1			3000h to 3FFFh (upper 1/4)
	1	 0			2000h to 3FFFh (upper 1/2)
	1	 1			0000h to 3FFFh (all)
bit(7) ( WPEN(0) ) Write Protect Enable bit Used to enable the function of Write Protect Pin (WP)
	 When the WPEN bit is set to '0', the status of the WP pin is ignored.
	 When the WPEN bit is set to '1', a LOW on the WP pin inhibits a write to the Status Register

WEL	  WPEN		WP	 Protected Blocks		Unprotected Blocks		Status Register
0		X		X	 Protected				     Protected				Protected
1		0		X	 Protected					Unprotected			   Unprotected
1		1		0	 Protected					Unprotected				Protected
1		1		1	 Protected					Unprotected			   Unprotected

operations :

write:(No page register is needed and any number of sequential writes may be performed.)
________________________________________________________________________________________________________________________________________
	status reg:	
enable write enable latch .. select write status reg ... send data ....reset write enable latch
send:	(CS LOW)(WREN)						(WRSR)			(data)			(WRDI) (HIGH CS)
________________________________________________________________________________________________________________________________________
	memory:
enable write enable latch .. select write memory .. two-byte address....send data bytes (till CS go high)....reset write enable latch
send:(CS LOW)	(WREN)				(WRITE)		(2 bytes address)(A13-A0)	(data_0..data_n)	(HIGH CS)  (CS LOW)	(WRDI) (CS HIGH)
========================================================================================================================================
read status reg:
send read status reg .. receive the value of status reg
send:	(CS LOW) (RDSR)				garbage (get status reg. value)
________________________________________________________________________________________________________________________________________
memory:
 start comm  send read command ... two-byte address....read data bytes (till CS go high)
send:(CS LOW)	(READ)				(2 bytes address)(A13-A0)	(data_0..data_n)	(HIGH CS) 


*/ 
#define WREN		 (0x06)
#define WRDI		 (0x04)
#define RDSR		 (0x05)
#define WRSR		 (0x01)
#define READ		 (0x03)
#define FSTRD		 (0x0b)
#define WRITE	 	 (0x02)
#define SLEEP		 (0xb9)
#define RDID		 (0x9f)



void FRAM_init();
uint8_t FRAM_ReadStatus( void);
void FRAM_WriteStatus(uint8_t data);
uint8_t* FRAM_ReadData(uint16_t address ,uint8_t num_bytes);
void FRAM_WriteData(uint16_t address ,uint8_t* data);
void FRAM_WriteEnable(void);
void FRAM_WriteDisable(void);
void FRAM_Sleep();

#endif /* HFM25V01=H= */