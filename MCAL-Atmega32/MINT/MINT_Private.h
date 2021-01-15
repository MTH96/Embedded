/*
 * MINT_Private.h
 *
 * Created: 14/04/2019 04:54:14 م
 *  Author: Mahmoud Hashem
 */


#ifndef MINTERRUPT_PRIVATE_H_
#define MINTERRUPT_PRIVATE_H_

/*
$35 ($55) MCUCR  SE  SM2  SM1 SM0  ISC11 ISC10 ISC01 ISC00 
$34 ($54) MCUCSR JTD ISC2 –   JTRF WDRF  BORF  EXTRF PORF 

$3B ($5B) GICR  INT1  INT0  INT2  – – – IVSEL IVCE 
$3A ($5A) GIFR  INTF1 INTF0 INTF2 – – – –     –
*/
#define MINT_MCUCR	(*(volatile u8*)(0x55))
#define SE		7
#define SM2		6
#define SM1		5
#define SM0		4
#define ISC11	3
#define ISC10	2
#define ISC01	1
#define ISC00	0

#define MINT_MCUCSR	(*(volatile u8*)(0x54))
#define JTD		7
#define ISC2	6
#define JTRF	4
#define WDRF	3
#define BORF	2
#define EXTRF	1
#define PORF	0

#define MINT_GICR	(*(volatile u8*)(0x5B))
#define INT1	7
#define INT0	6
#define INT2	5
#define IVSEL	1
#define IVCE	0

#define MINT_GIFR	(*(volatile u8*)(0x5A))
#define INTF1	7
#define INTF0	6
#define INTF2	5

#define SREG		    (*(volatile u8*)(0x5F)) // Status Register
#define IE	7


#endif /* MINTERRUPT_PRIVATE_H_ */
