// printerStats.h

#ifndef _PRINTERSTATS_h
#define _PRINTERSTATS_h


#include "stepper.h"
#include "Marlin.h"

#include "MarlinConfig.h"


class PrinterStats {
	public:
	PrinterStats() {}		

	static void reset();
	
	static void report();
	
	static void update(AxisEnum axis, float distance, uint8_t tool);
	
	static bool homing;
	private:
	static float X1_lenght_done_mm;
	static float X2_lenght_done_mm;
	static float E1_lenght_done_mm;
	static float E2_lenght_done_mm;
	static float Y_lenght_done_mm;
	static float Z_lenght_done_mm;

};

extern PrinterStats printerStats;

#endif

