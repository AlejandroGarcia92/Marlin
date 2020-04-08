// chamberFanPWM.h

#ifndef _CHAMBERFANPWM_h
#define _CHAMBERFANPWM_h

#include "MarlinConfig.h"


#define DEFAULT_DUTYCYCLE_CHAMBER 2
#define MAX_POWER_CHAMBER 5

class ChamberFanPWM {
	
public:
	ChamberFanPWM() {}

	void setup(uint16_t timer_period = 500);
	void setDuty(uint8_t duty);

private:
	//Counters
	uint8_t dutycycle = 0; //value range 0% to 100;
	uint8_t counter_timer = 0; //value range 0% to 100;
	//Timer
	uint32_t timeelapsed_fan = 0;
};

extern ChamberFanPWM chamberFanPWM;

#endif

