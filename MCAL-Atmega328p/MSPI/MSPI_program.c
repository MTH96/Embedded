#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "MSPI_private.h"
#include <avr/interrupt.h>
void MSPI_init(u8 mode) {
	/*the LSB of the data word is transmitted first*/
	SET_BIT(MSPI_SPCR0, DORD0);
	/*f osc /64*/
	CLEAR_BIT(MSPI_SPCR0, SPR00);
	SET_BIT(MSPI_SPCR0, SPR01);
	CLEAR_BIT(MSPI_SPSR0, SPI2X0);

	/*high-when-idle (CPOL), sample on trail (CPHA)*/
	SET_BIT(MSPI_SPSR0, CPOL0);
	SET_BIT(MSPI_SPSR0, CPHA0);

	switch (mode) {
	case SPI_MASTER:

		/*set as a master*/
		SET_BIT(MSPI_SPCR0, MSTR0);

		/*configure pin direction*/
		MDIO_PinStatus(SPI_MOSI, OUTPUT);
		MDIO_PinStatus(SPI_SCK, OUTPUT);
		MDIO_PinStatus(SPI_SS, OUTPUT);
		MDIO_SetPinValue(SPI_MISO, INPUT_FLOAT);
		break;
	case SPI_SLAVE:

		/*set as a slave*/
		CLEAR_BIT(MSPI_SPCR0, MSTR0);
		/*configure pin direction*/
		MDIO_PinStatus(SPI_MISO, OUTPUT);
		MDIO_PinStatus(SPI_MOSI, INPUT_FLOAT);
		MDIO_PinStatus(SPI_SS, INPUT_FLOAT);
		MDIO_PinStatus(SPI_SCK, INPUT_FLOAT);
		/*enable SPI0 Interrupt*/
		SET_BIT(MSPI_SPCR0, SPIE0);
		sei();
		break;
	}
	/*enable SPI */
	SET_BIT(MSPI_SPCR0, SPE0);

}

u8 MSPI_ReadChar() {
	// Wait for transmission complete
	while (!GET_BIT(MSPI_SPSR0, SPIF0))
		;

	return MSPI_SPDR0;
}

void MSPI_WriteChar(u8 dataout) {

	// Start transmission (MOSI)
	MSPI_SPDR0 = dataout;

	// Wait for transmission complete
	while (!GET_BIT(MSPI_SPSR0, SPIF0))
		;

}
u8 MSPI_SwapChar(u8 dataout) {
	// Start transmission (MOSI)
	MSPI_SPDR0 = dataout;

	// Wait for transmission complete
	while (!GET_BIT(MSPI_SPSR0, SPIF0))
		;

	return MSPI_SPDR0;;
}

