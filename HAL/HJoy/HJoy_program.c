#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "HJoy_interface.h"
#include "HJoy_private.h"

void HJoy_init()
{
	MSPI_init(SPI_MASTER);

	extern volatile u8 press_1;
	extern volatile u8 press_2;

	press_1 = 0xff;
	press_2 = 0xff;

}

void HJoy_Poll()
{
	extern volatile u8 press_1;
	extern volatile u8 press_2;

	u8 rx_buffer[21];

	// Send header
	rx_buffer[0] = MSPI_SwapChar(0x01);
	rx_buffer[1] = MSPI_SwapChar(0x42); //pooling to get data
	rx_buffer[2] = MSPI_SwapChar(0x00);
	u8 i = 0, datain_size = (rx_buffer[2] & 0x0f) * 2;
	for (i = 0; i < datain_size; i++) //get all the data from joystick
	{
		rx_buffer[i + 3] = MSPI_SwapChar(0x00);
	}

	press_1 = rx_buffer[4];
	press_2 = rx_buffer[5];

}

u16 HJoy_GetPress()
{
	extern volatile u8 press_1;
	extern volatile u8 press_2;

	return (press_2<<8) | press_1;

}
