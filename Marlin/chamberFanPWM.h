// chamberFanPWM.h

#ifndef _CHAMBERFANPWM_h
#define _CHAMBERFANPWM_h

#include "MarlinConfig.h"


#define DEFAULT_DUTYCYCLE_CHAMBER 2
#define MAX_POWER_CHAMBER 5

class ChamberFanPWM {
	
	public:
	ChamberFanPWM() {}

	static void setup();
	static void setup(uint16_t timer_period);
	
	static void setDuty(uint8_t duty);

};

extern ChamberFanPWM chamberFanPWM;

#endif

