/*
- Leds_manager.cpp - A class that manages the Led colours
Last Update: 18/10/2019
Author: Alejandro Garcia (S3mt0x)
*/

#include "Leds_handler.h"

#include "Marlin.h"


//Counters
uint8_t start_up_counter = 0;
uint8_t counter_red = 255;
uint8_t counter_green = 255;
uint8_t counter_blue = 255;
uint8_t counter_colour1 = 255;
uint8_t counter_colour2 = 255;
uint8_t counter_colour3 = 255;

//Modes states
bool rising_red_mode2 = false;
bool rising_green_mode2 = false;
bool rising_blue_mode2 = false;
uint8_t mode3_state = 0; //up to 5
bool rising_mode3 = false;

//Led Mode
ledStates led_mode_state = ledStates::led_idle;

//Max level
uint8_t max_level = 255;

uint16_t MidSecond = 0;

//Class call
Leds_Handler leds_handler;

void Leds_Handler::setup(){

	// Set led pins as output and low
	pinMode(RED,OUTPUT);
	pinMode(GREEN,OUTPUT);
	pinMode(BLUE,OUTPUT);
	
	digitalWrite(RED,LOW);
	digitalWrite(GREEN,LOW);
	digitalWrite(BLUE,LOW);
	
	//Setup Timer2 to fire every 1ms
	TCCR2B = 0x00;        //Disbale Timer2 while we set it up
	TCNT2  = 130;         //Reset Timer Count to 130 out of 255
	TIFR2  = 0x00;        //Timer2 INT Flag Reg: Clear Timer Overflow Flag
	TIMSK2 = 0x01;        //Timer2 INT Reg: Timer2 Overflow Interrupt Enable
	TCCR2A = 0x00;        //Timer2 Control Reg A: Wave Gen Mode normal
	TCCR2B = 0x05;        //Timer2 Control Reg B: Timer Prescaler set to 128
 
}

ISR(TIMER2_OVF_vect) {
	if(MidSecond < 50){
		MidSecond++;
	}
	else{
		switch(led_mode_state){
			case ledStates::led_mode1:		
			start_up_counter++;
			analogWrite(RED, constrain(start_up_counter, 0, max_level));
			analogWrite(GREEN, constrain(start_up_counter, 0, max_level));
			analogWrite(BLUE, constrain(start_up_counter, 0, max_level));
			if(start_up_counter == 255) led_mode_state = ledStates::led_idle;				
			break;
			
			case ledStates::led_mode2:
			
			
			if(rising_mode3){
				if(counter_colour1 < 251)counter_colour1 = counter_colour1 + 4;
				else if(counter_colour2 < 251)counter_colour2 = counter_colour2 + 4;
				else if(counter_colour3 < 251)counter_colour3 = counter_colour3 + 4;
				else {
					rising_mode3 = false;
					switch (mode3_state){
						case 0:
						mode3_state = 1;
						break;
						case 1:
						mode3_state = 2;
						break;
						case 2:
						mode3_state = 3;
						break;
						case 3:
						mode3_state = 3;
						break;
						case 4:
						mode3_state = 4;
						break;
						case 5:
						mode3_state = 0;
						break;
					}
				}
			}
			else{
				
				if(counter_colour1 > 3)counter_colour1 = counter_colour1 - 4;
				else if(counter_colour2 > 3)counter_colour2 = counter_colour2 - 4;
				else if(counter_colour3 > 3)counter_colour3 = counter_colour3 - 4;
				else {
					rising_mode3 = true;
					switch (mode3_state){
						case 0:
						mode3_state = 1;
						break;
						case 1:
						mode3_state = 2;
						break;
						case 2:
						mode3_state = 3;
						break;
						case 3:
						mode3_state = 3;
						break;
						case 4:
						mode3_state = 4;
						break;
						case 5:
						mode3_state = 0;
						break;
					}
				}
			}
			switch (mode3_state){			
				// Sequence:
				// mode3_state:
				// 0 : R->G->B
				// 1 : G->R->B
				// 2 : B->G->R
				// 3 : B->R->G
				// 4 : G->B->R
				// 5 : R->B->G
				case 0:
				analogWrite(RED, counter_colour1);
				analogWrite(GREEN, counter_colour2);
				analogWrite(BLUE, counter_colour3);
				break;
				case 1:
				analogWrite(RED, counter_colour2);
				analogWrite(GREEN, counter_colour1);
				analogWrite(BLUE, counter_colour3);
				break;
				case 2:
				analogWrite(RED, counter_colour3);
				analogWrite(GREEN, counter_colour2);
				analogWrite(BLUE, counter_colour1);
				break;
				case 3:
				analogWrite(RED, counter_colour2);
				analogWrite(GREEN, counter_colour3);
				analogWrite(BLUE, counter_colour1);
				break;
				case 4:
				analogWrite(RED, counter_colour3);
				analogWrite(GREEN, counter_colour1);
				analogWrite(BLUE, counter_colour2);
				break;
				case 5:
				analogWrite(RED, counter_colour1);
				analogWrite(GREEN, counter_colour3);
				analogWrite(BLUE, counter_colour2);
				break;
			}
			
			break;
			
			case ledStates::led_mode3:
			//Code
			
			
			if(rising_red_mode2){
				if(counter_red < 224)counter_red+=32;
				else {rising_red_mode2 = false;counter_red=255;}
			}
			else{
				if(counter_red > 31)counter_red-=32;
				else {rising_red_mode2 = true;counter_red=0;}
			}
			if(rising_green_mode2){
				if(counter_green < 224)counter_green+=32;
				else {rising_green_mode2 = false;counter_green=255;}
			}
			else{
				if(counter_green > 31)counter_green-=32;
				else {rising_green_mode2 = true;counter_green=0;}
			}
			if(rising_blue_mode2){
				if(counter_blue < 224)counter_blue+=32;
				else {rising_blue_mode2 = false;counter_blue=255;}
			}
			else{
				if(counter_blue > 31)counter_blue-=32;
				else {rising_blue_mode2 = true;counter_blue=0;}
			}
			
			analogWrite(RED, counter_blue);
			analogWrite(GREEN, counter_green);
			analogWrite(BLUE, counter_red);
			
			break;
			
			case led_shutdown:
			analogWrite(RED, 0);
			analogWrite(GREEN, 0);
			analogWrite(BLUE, 0);
			led_mode_state = led_idle;			
			break;
			
			default:
			break;
			
		}
		
		
		
		MidSecond = 0;
	}
	
	
	TCNT2 = 130;           //Reset Timer to 130 out of 255
	TIFR2 = 0x00;          //Timer2 INT Flag Reg: Clear Timer Overflow Flag
}
void Leds_Handler::setNewLedState(ledStates ledstate) {
	counter_red = 255;
	counter_green = 255;
	counter_blue = 255;
	counter_colour1 = 255;
	counter_colour2 = 255;
	counter_colour3 = 255;
	rising_red_mode2 = false;
	rising_green_mode2 = false;
	rising_blue_mode2 = false;
	mode3_state = 0; //up to 5
	start_up_counter  = 0;
	rising_mode3 = false;
	led_mode_state = ledstate;
}

void Leds_Handler::setMaxLevel(uint8_t level) {
	max_level = level;
	if(led_mode_state == ledStates::led_idle) {
		analogWrite(RED, level);
		analogWrite(GREEN, level);
		analogWrite(BLUE, level);
	}
}


