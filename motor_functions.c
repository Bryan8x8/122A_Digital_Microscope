/*
 * stepper_motor.c
 *
 * Created: 11/8/2018 1:04:37 PM
 * Author : Juan Delgado
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "timer.c"

//====== DEFINITIONS =======

#define stepperMotorOne_1 PC0
#define stepperMotorOne_2 PC1
#define stepperMotorOne_3 PC2
#define stepperMotorOne_4 PC3

#define stepperMotorTwo_1 PC4
#define stepperMotorTwo_2 PC5
#define stepperMotorTwo_3 PC6
#define stepperMotorTwo_4 PC7

#define stepperMotorThree_1 PD0
#define stepperMotorThree_2 PD1
#define stepperMotorThree_3 PD2
#define stepperMotorThree_4 PD3

//====== VARIABLES ====== 

//none

void init_motors(){
	
	DDRC |= (1 << stepperMotorOne_1);
	DDRC |= (1 << stepperMotorOne_2);
	DDRC |= (1 << stepperMotorOne_3);
	DDRC |= (1 << stepperMotorOne_4);
	
	DDRC |= (1 << stepperMotorTwo_1);
	DDRC |= (1 << stepperMotorTwo_2);
	DDRC |= (1 << stepperMotorTwo_3);
	DDRC |= (1 << stepperMotorTwo_4);
	
	DDRD |= (1 << stepperMotorThree_1);
	DDRD |= (1 << stepperMotorThree_2);
	DDRD |= (1 << stepperMotorThree_3);
	DDRD |= (1 << stepperMotorThree_4);
	
}

void step_motor_three(unsigned char input){
	//TimerSet(1000);
	//TimerOn();
	/*
	//1
	PORTD |= (1 << stepperMotorThree_1);
	PORTD &= ~(1 << stepperMotorThree_4);

	_delay_ms(10000);
	
	//2
	PORTD |= (1 << stepperMotorThree_3);
	
	_delay_ms(10000);
	
	//3
	PORTD &= ~(1 << stepperMotorThree_1);
	_delay_ms(10000);
	
	//4
	PORTD |= (1 << stepperMotorThree_2);
	_delay_ms(10000);
	
	//5
	PORTD &= ~(1 << stepperMotorThree_3);
	_delay_ms(10000);
	
	//6
	PORTD |= (1 << stepperMotorThree_4);
	_delay_ms(10000);
	
	//7
	PORTD &= ~(1 << stepperMotorThree_2);
	_delay_ms(10000);
	
	//8
		PORTD |= (1 << stepperMotorThree_1);
	_delay_ms(10000);
	*/
	if(input == 0x00){
		//1
		PORTD &= ~(1 << stepperMotorThree_1);
		PORTD |= (1 << stepperMotorThree_4);
		_delay_ms(100);
	
		//2
		PORTD &= ~(1 << stepperMotorThree_4);
		PORTD |= (1 << stepperMotorThree_3);
		_delay_ms(100);
	
		//3
		PORTD &= ~(1 << stepperMotorThree_3);
		PORTD |= (1 << stepperMotorThree_2);
		_delay_ms(100);
	
		//4
		PORTD &= ~(1 << stepperMotorThree_2);
		PORTD |= (1 << stepperMotorThree_1);
		_delay_ms(100);
	}
	
	if(input == 0x0F){
		PORTD &= ~(1 << stepperMotorThree_4);
		PORTD |= (1 << stepperMotorThree_1);
		_delay_ms(100);
		
		//2
		PORTD &= ~(1 << stepperMotorThree_1);
		PORTD |= (1 << stepperMotorThree_2);
		_delay_ms(100);
		
		//3
		PORTD &= ~(1 << stepperMotorThree_2);
		PORTD |= (1 << stepperMotorThree_3);
		_delay_ms(100);
		
		//4
		PORTD &= ~(1 << stepperMotorThree_3);
		PORTD |= (1 << stepperMotorThree_4);
		_delay_ms(100);
	}
	
	
}

void step_motor_two(unsigned char input){
	
	if(input == 0x00){
		PORTC &= ~(1 << stepperMotorTwo_1);
		PORTC |= (1 << stepperMotorTwo_4);
		_delay_ms(100);
	
		//2
		PORTC &= ~(1 << stepperMotorTwo_4);
		PORTC |= (1 << stepperMotorTwo_3);
		_delay_ms(100);
	
		//3
		PORTC &= ~(1 << stepperMotorTwo_3);
		PORTC |= (1 << stepperMotorTwo_2);
		_delay_ms(100);
	
		//4
		PORTC &= ~(1 << stepperMotorTwo_2);
		PORTC |= (1 << stepperMotorTwo_1);
		_delay_ms(100);
	}
		
	if(input == 0x0F){
		PORTC &= ~(1 << stepperMotorTwo_4);
		PORTC |= (1 << stepperMotorTwo_1);
		_delay_ms(100);
		
		//2
		PORTC &= ~(1 << stepperMotorTwo_1);
		PORTC |= (1 << stepperMotorTwo_2);
		_delay_ms(100);
		
		//3
		PORTC &= ~(1 << stepperMotorTwo_2);
		PORTC |= (1 << stepperMotorTwo_3);
		_delay_ms(100);
		
		//4
		PORTC &= ~(1 << stepperMotorTwo_3);
		PORTC |= (1 << stepperMotorTwo_4);
		_delay_ms(100);
	}
		
}

void step_motor_one(unsigned int input){
	
	if(input == 0x00){
		PORTC &= ~(1 << stepperMotorOne_1);
		PORTC |= (1 << stepperMotorOne_4);
		_delay_ms(100);
		
		//2
		PORTC &= ~(1 << stepperMotorOne_4);
		PORTC |= (1 << stepperMotorOne_3);
		_delay_ms(100);
		
		//3
		PORTC &= ~(1 << stepperMotorOne_3);
		PORTC |= (1 << stepperMotorOne_2);
		_delay_ms(100);
		
		//4
		PORTC &= ~(1 << stepperMotorOne_2);
		PORTC |= (1 << stepperMotorOne_1);
		_delay_ms(100);
	}
	
	if(input == 0x0F){
		PORTC &= ~(1 << stepperMotorOne_4);
		PORTC |= (1 << stepperMotorOne_1);
		_delay_ms(100);
		
		//2
		PORTC &= ~(1 << stepperMotorOne_1);
		PORTC |= (1 << stepperMotorOne_2);
		_delay_ms(100);
		
		//3
		PORTC &= ~(1 << stepperMotorOne_2);
		PORTC |= (1 << stepperMotorOne_3);
		_delay_ms(100);
		
		//4
		PORTC &= ~(1 << stepperMotorOne_3);
		PORTC |= (1 << stepperMotorOne_4);
		_delay_ms(100);
	}
	
}

void motor_function (unsigned char input){
	
	unsigned char select_motor = input >> 4;
	unsigned char direction;
	
		if (select_motor == 0x01)
		{
			direction = input & 0xF;
			step_motor_one(direction);
		}
		if (select_motor == 0x02)
		{
			direction = input & 0xF;
			step_motor_two(direction);
		}
		if (select_motor == 0x03)
		{
			direction = input & 0xF;
			step_motor_three(direction);
		}
	
}


int main(void)
{
    init_motors();
	
    while (1) 
    {
		motor_function(0x20);	
    }
}

