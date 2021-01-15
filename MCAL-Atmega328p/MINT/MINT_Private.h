/*
 * MInterrupt_Private.h
 *
 * Created: 16/11/2018 01:52:46 م
 *  Author: Saeed Eltohamy 
 */ 


#ifndef MINTERRUPT_PRIVATE_H_
#define MINTERRUPT_PRIVATE_H_

 // INTERRUPT REGESTERS 
#define MINT_EICRA      (*(volatile u8*)(0x69))
#define ISC11	3
#define ISC10	2
#define ISC01	1
#define ISC00	0

#define MINT_EIMSK      (*(volatile u8*)(0x3D))
#define INT1	1
#define INT0	0

#define MINT_INTF       (*(volatile u8*)(0x3C))
#define INTF1	1
#define INTF0	0
/*
#define MINT_PCICR 		(*(volatile u8*)(0x68))
#define PCIE2	2
#define PCIE1	1
#define PCIE0	0

#define MINT_PCIFR 		(*(volatile u8*)(0x38))
#define PCIF2	2
#define PCIF1	1
#define PCIF0	0
*/
#define SREG		    (*(volatile u8*)(0x5F)) // Status Register
#define IE	7


// 
#define MINT_EICRA_INT1_MASK 	0b00001100
#define MINT_EICRA_INT0_MASK	0b00000011

#endif /* MINTERRUPT_PRIVATE_H_ */
