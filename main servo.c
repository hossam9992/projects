/*
 * servo.c
 *
 * Created: 5/7/2020 1:51:21 AM
 * Author : MAZDA
 */ 

#include <avr/io.h>
#define  F_CPU 16000000
#include <util/delay.h>
#define out_min 250
#define  out_max 500

void Servo_Write(char angle);
void Wait(){
	uint16_t i;
	for (i=0;i<50;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}
	
int main(void)
{
   TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
   TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10);
   ICR1=4999;
   DDRD|=(1<<PD4)|(1<<PD5);
   
   }
   while (1) 
    {
		Servo_Write(90);
		_delay_ms(3000);
		Servo_Write(0);
		_delay_ms(3000);
		Servo_Write(180);
		_delay_ms(3000);
		
    }
}

void Servo_Write(char angle){
	if (angle==0)
	{OCR1A =out_min;
	}
	else{
		OCR1A=(angle*(out_max-out_min)/(180-0))+out_min;
	}
}