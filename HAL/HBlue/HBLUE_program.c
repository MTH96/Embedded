#include "LSTDTYPES.h"
#include "LUTILS.h"
#include "MUART_interface.h"

void HBLUE_init(void)
{
	MUART_init(9600);
	return ;
}

u8 HBLUE_GetCommand()
{
	return MUART_read_char();
}
