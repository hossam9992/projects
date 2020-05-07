/*
 * into.c
 *
 * Created: 5/5/2020 4:35:06 PM
 * Author : MAZDA
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
volatile unsigned int counter;
int main(void)
{
	DDRC=(1<<2);
  TCCR0=(1<<CS00)|(1<<CS01);
  TIMSK=(1<<TOIE0);
  sei();  
   
    while (1) 
    { 
		if (counter>=100)
		{
			PORTC^=(1<<2);
			counter=0;
			
		}
	
    }
	
}
ISR(TIMER0_OVF_vect){
	counter++;
}



