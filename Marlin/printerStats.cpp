// 
// 
// 

#include "printerStats.h"

PrinterStats printerStats;

bool PrinterStats::homing = false;
float PrinterStats::X1_lenght_done_mm = 0.0;
float PrinterStats::X2_lenght_done_mm = 0.0;
float PrinterStats::E1_lenght_done_mm = 0.0;
float PrinterStats::E2_lenght_done_mm = 0.0;
float PrinterStats::Y_lenght_done_mm = 0.0;
float PrinterStats::Z_lenght_done_mm = 0.0;

void PrinterStats::reset() {
	PrinterStats::X1_lenght_done_mm = 0.0;
	PrinterStats::X2_lenght_done_mm = 0.0;
	PrinterStats::E1_lenght_done_mm = 0.0;
	PrinterStats::E2_lenght_done_mm = 0.0;
	PrinterStats::Y_lenght_done_mm = 0.0;
	PrinterStats::Z_lenght_done_mm = 0.0;
}

void PrinterStats::report() {
	SERIAL_ECHO_START();
	SERIAL_ECHOPAIR(" Distance: XL: ", PrinterStats::X1_lenght_done_mm);
	SERIAL_ECHOPAIR(" XR: ", PrinterStats::X2_lenght_done_mm);
	SERIAL_ECHOPAIR(" Y: ", PrinterStats::Y_lenght_done_mm);
	SERIAL_ECHOPAIR(" Z: ", PrinterStats::Z_lenght_done_mm);
	SERIAL_ECHOPAIR(" EL: ", PrinterStats::E1_lenght_done_mm);
	SERIAL_ECHOLNPAIR(" ER: ", PrinterStats::E2_lenght_done_mm);
	reset();
}
void PrinterStats::update(AxisEnum axis, float distance, uint8_t tool) {	
	if(homing) return;	
	switch(axis){
		case X_AXIS:
		if(motorMode != motordriver_mode::motordefault) {
			PrinterStats::X1_lenght_done_mm += distance;
			PrinterStats::X2_lenght_done_mm += distance;
		} else if(tool == 0) {
			PrinterStats::X1_lenght_done_mm += distance;
		} else {
			PrinterStats::X2_lenght_done_mm += distance;
		} 		
		break;
		case Y_AXIS:
		PrinterStats::Y_lenght_done_mm += distance;
		break;
		case Z_AXIS:
		PrinterStats::Z_lenght_done_mm += distance;
		break;
		case E_CART:
		if(motorMode != motordriver_mode::motordefault) {
			PrinterStats::E1_lenght_done_mm += distance;
			PrinterStats::E2_lenght_done_mm += distance;
			} else if(tool == 0) {
			PrinterStats::E1_lenght_done_mm += distance;
			} else {
			PrinterStats::E2_lenght_done_mm += distance;
		}
		break;
		default:
		break;
	}
		
}
