#ifndef MSPI_INTERFACE_H
#define MSPI_INTERFACE_H


void MSPI_init(u8 mode);

u8 MSPI_ReadChar();
void MSPI_WriteChar(u8 dataout);

u8 MSPI_SwapChar(u8 dataout);



#define SPI_MASTER	0
#define SPI_SLAVE	1

#define SPI_MOSI	PB_3
#define SPI_MISO	PB_4
#define SPI_SS		PB_2
#define SPI_SCK		PB_5

#endif
