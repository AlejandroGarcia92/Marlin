/*
- Leds_manager.h - A class that manages the Led colours
Last Update: 18/10/2019
Author: Alejandro Garcia (S3mt0x)
*/
#ifndef _LEDS_MANAGER_h
#define _LEDS_HANDLER_h

#include "MarlinConfig.h"

enum ledStates{
	led_idle,	 //0
	led_mode1,   //1
	led_mode2,   //2
	led_mode3,   //3
	led_shutdown //4
};

class Leds_Handler {
	
	public:
	Leds_Handler() {}

	static void setup();
	
	static void setNewLedState(ledStates ledstate);	
	static void setMaxLevel(uint8_t level);
};

extern Leds_Handler leds_handler;


#endif

