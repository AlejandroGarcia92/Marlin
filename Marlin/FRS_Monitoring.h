// FRS_Service.h

#ifndef _FRS_SERVICE_h
#define _FRS_SERVICE_h

#include "cardreader.h"
#include "printcounter.h"
#include "stepper.h"
#include "Marlin.h"

#include "MarlinConfig.h"

#define FIL_RUNOUT_THRESHOLD 5

class FRS_Monitoring {
	public:
	FRS_Monitoring() {}

	static void setup();
	
	static void report();
		
	FORCE_INLINE static void run() {
		bool change = false;
		for(uint8_t i=0;i<EXTRUDERS;i++){
			bool newstate = check(i);
			if(newstate != runout_state[i]){
				runout_state[i]=newstate;
				change = true;
			}			
		}
		if(change) report();		
	}
	private:
	static uint8_t runout_count[EXTRUDERS];
	static bool runout_state[EXTRUDERS];

	FORCE_INLINE static bool check(uint8_t extruder) {
		
		// Read the sensor for the active extruder
		bool is_out;
		switch (extruder) {
			case 0: is_out = digitalRead(FIL_RUNOUT_PIN) == true; break;
			case 1: is_out = digitalRead(FIL_RUNOUT2_PIN) == true; break;
		}
		
		if(is_out){
			
			if(runout_count[extruder] <= FIL_RUNOUT_THRESHOLD) runout_count[extruder]++;
			
		}else{
			runout_count[extruder] = 0;		
		}
		return runout_count[extruder] > FIL_RUNOUT_THRESHOLD;
	}
};

extern FRS_Monitoring frs_monitor;


#endif

