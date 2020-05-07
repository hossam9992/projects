/*
 * GccApplication2int.c
 *
 * Created: 5/5/2020 4:59:45 AM
 * Author : MAZDA
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
volatile char flag;
ISR(INT0_vect){
	flag=1;
}

void toggle_led(){
	DDRC^=(1<<2);
	_delay_ms(1000);
}
int main(void)
{
    GICR|=(1<<INT0);
	MCUCR|=(1<<ISC00)|(1<<ISC01);
	DDRC|=(1<<2);
	sei();
    while (1) 
    {
		if (flag!=0)
		{
			toggle_led();
			flag=0;
		}
    }
	return 0;
}

