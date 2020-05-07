/*
 * GccApplication1.c
 *
 * Created: 5/3/2020 2:40:08 PM
 * Author : MAZDA
 */ 
 #define F_CPU 16000000
#include <avr/io.h>

#define  M11 7
#define  M12  2
#define ENA 7
#include <util/delay.h>
//prototype
void motor_cw(unsigned char speed);
void motor_anti_cw(unsigned char speed);
void motor_init();
	
	

//control DC motor from timer 2 PWM ,fast pwm , no Prescale inverting mode
int main(void)
{
	motor_init();
	
	
    while (1) 
    {

	motor_cw(50);
	_delay_ms(500);
	motor_anti_cw(60);
    }

	
}
	void motor_cw(unsigned char speed ){
		PORTC=(1<<M11);
		PORTC&=~(M12);
		OCR2= (speed*255)/100; //half speed
	}
void motor_init(){
	DDRD=(1<<M11);
	DDRC=(1<<M12);
	DDRC=(1<<ENA);
	TCCR2=(1<<WGM20)|(1<<WGM21)|(1<<COM20)|(1<<CS20);
	
}
void motor_anti_cw(unsigned char speed){
		PORTC=(1<<M12);
		PORTC&=~(M11);
		OCR2= (speed*255)/100;
}