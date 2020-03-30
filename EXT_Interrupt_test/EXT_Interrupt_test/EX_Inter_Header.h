/*
 * EX_Inter_Header.h
 *
 * Created: 20/03/14 11:58:11 AM
 *  Author: Mohamed Sobhy
 */ 


#ifndef EX_INTER_HEADER_H_
#define EX_INTER_HEADER_H_

#include <avr/io.h>
#define  F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>


#define SET_BIT(REG,BIT_NUM)      (REG |=(1<<BIT_NUM))
#define REST_BIT(REG,BIT_NUM)     (REG &=(~(1<<BIT_NUM)))
#define TOGGEL_BIT(REG,BIT_NUM)   (REG ^=(1<<BIT_NUM))
#define READ_BIT(REG,BIT_NUM)     (REG =(1>>BIT_NUM)&1)

//defining the External interrupt register address

#define        SREG_EXinTrup         (*(volatile uint8_t*)(0x5F))
#define        GICR_EXinTrup         (*(volatile uint8_t*)(0x5B))
#define        GIFR_EXinTrup         (*(volatile uint8_t*)(0x5A))
#define        MCUCR_EXinTrup        (*(volatile uint8_t*)(0x55))
#define        MCUCSR_EXinTrup       (*(volatile uint8_t*)(0x54))

//bit of reg SREG...
#define  I_BIT 7

//defining the External interrupt register MCURC BITS 
enum cont_reg_bits
{
 
 ISC00_BIT=0,     //The level trigger bit for external interrupt INT0
 ISC01_BIT=1,    //The level trigger bit for external interrupt INT0
 
 ISC10_BIT=2,  // The level trigger bit for external interrupt INT1
 ISC11_BIT=3,  //The level trigger bit for external interrupt INT1
 
}Cont_Reg_LEVEL_Bits;


//defining the External interrupt register GICR BITS
enum Grl_Cont_INTR_REG_Bits
{
	INT2_BIT=5,        //EXterternal interrupt  Request 2
	INT0_BIT=6,        //EXterternal interrupt  Request 0
	INT1_BIT=7,        //EXterternal interrupt  Request 1
	
}Cont_Reg_INTR_Bits;



//defining the External interrupt flag  register GIFR BITS
enum Grl_Cont_INTR_flag_REG_Bits
{
	INTF2_BIT=5,        //EXterternal interrupt Flag for Request 2
	INTF0_BIT=6,        //EXterternal interrupt Flag for Request 0
	INTF1_BIT=7,        //EXterternal interrupt Flag for Request 1
	
}Cont_Reg_INTRFLG_Bits;




typedef unsigned  char                 uint8_t ;
typedef signed    char                 sint8_t;
typedef unsigned  short int            sho_uint16_t;
typedef signed    short int            sho_sint16_t;
typedef unsigned long int              uint32_t;
typedef signed   long int              sint32_t;
typedef unsigned long long              uint64_t;
typedef signed   long long              sint64_t;


#endif /* EX_INTER_HEADER_H_ */