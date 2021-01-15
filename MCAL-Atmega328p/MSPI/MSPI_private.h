#ifndef MSPI_PRIVATE_H
#define MSPI_PRIVATE_H

#define MSPI_SPCR0 (*(volatile u8*)(0x4C))
#define SPIE0	7
#define SPE0	6
#define DORD0	5
#define MSTR0	4
#define CPOL0	3
#define CPHA0	2
#define SPR01	1
#define SPR00	0

#define MSPI_SPSR0 (*(volatile u8*)(0x4D))
#define SPIF0	7
#define WCOL0	6
#define SPI2X0	0

#define MSPI_SPDR0 (*(volatile u8*)(0x4E))



#endif
