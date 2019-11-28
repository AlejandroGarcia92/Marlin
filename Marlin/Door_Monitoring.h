
#ifndef _DOOR_MONITORING_h
#define _DOOR_MONITORING_h

#include "cardreader.h"
#include "printcounter.h"
#include "stepper.h"
#include "Marlin.h"

#include "MarlinConfig.h"

#define DOOR_THRESHOLD 5

class Door_Monitoring {
	public:
	Door_Monitoring() {}

	static void setup();
	
	static void report();
	
	FORCE_INLINE static void run() {
		
		bool newstate = check();
		if(newstate != door_state){
			door_state=newstate;
			report();
		}
		
	}
	private:
	static uint8_t door_count;
	static bool door_state;

	FORCE_INLINE static bool check() {
		
		// Read the sensor for the active extruder
		bool is_out = digitalRead(SAFE_STOP_PIN) == false; 
		
		if(is_out){
			
			if(door_count <= DOOR_THRESHOLD) door_count++;
			
			}else{
			door_count = 0;
		}
		return door_count > DOOR_THRESHOLD;
	}
};

extern Door_Monitoring door_monitor;


#endif
