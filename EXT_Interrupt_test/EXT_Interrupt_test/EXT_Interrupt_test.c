/*
 * EXT_Interrupt_test.c
 *
 * Created: 20/03/14 11:57:10 AM
 *  Author: Mohamed Sobhy
 */ 


#include "EX_Inter_Header.h"
#include <avr/interrupt.h>

ISR(INT0_vect)
{
TOGGEL_BIT(PORTA,2);//motor
}

ISR(INT1_vect)
{
TOGGEL_BIT(PORTA,7);
REST_BIT(PORTA,6);//led
}

void INT0_Init(void)
{
	SREG_EXinTrup |=(1<<I_BIT);                            // Enable GENERAL INTERRUPT bit  
	
	GICR_EXinTrup |= (1<<INT0_BIT);                       // Enable External INTERRUPT bit INT0
	
	PORTA &=(~(1<<2));                                // configure output as negative resistance   
	
	MCUCR_EXinTrup |=((1<<ISC01_BIT) |(1<<ISC00_BIT));    //configure trigger bit level 
	
	GIFR_EXinTrup |=(1<<INTF0_BIT);                       // configure INTERRUPT bit flag for INTO
	


}

void INT1_Init(void)
{
	SREG_EXinTrup |=(1<<I_BIT);                     // Enable GENERAL INTERRUPT bit  
	
	GICR_EXinTrup |= (1<<INT1_BIT);                        // Enable External INTERRUPT bit INT1
	
	PORTA &=(~(1<<7));                                  //configure output as negative resistance
	PORTA &=(~(1<<6));
	MCUCR_EXinTrup|=((1<<ISC10_BIT) |(1<<ISC11_BIT));      //configure trigger bit level
	
	GIFR_EXinTrup |=(1<<INTF1_BIT);                          // configure INTERRUPT bit flag for INT1
	


}
int main(void)
{
	INT1_Init(); 
	INT0_Init();
	
	REST_BIT(DDRD,2);
	REST_BIT(DDRD,3);
	SET_BIT(DDRA,2);
	SET_BIT(DDRA,7);
	SET_BIT(DDRA,6);
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}