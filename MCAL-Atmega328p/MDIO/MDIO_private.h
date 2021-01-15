#ifndef _MDIO_PRIVATE_H
#define _MDIO_PRIVATE_H


/*MDIO Registers*/
#define MDIO_PINB      (*(volatile u8*)(0x23))
#define MDIO_DDRB      (*(volatile u8*)(0x24))
#define MDIO_PORTB     (*(volatile u8*)(0x25))
#define MDIO_PINC      (*(volatile u8*)(0x26))
#define MDIO_DDRC      (*(volatile u8*)(0x27))
#define MDIO_PORTC     (*(volatile u8*)(0x28))
#define MDIO_PIND      (*(volatile u8*)(0x29))
#define MDIO_DDRD      (*(volatile u8*)(0x2A))
#define MDIO_PORTD     (*(volatile u8*)(0x2B)) 
#define MDIO_MCUCR     (*(volatile u8*)(0x55))


#endif