
#include "MarlinConfig.h"

#if defined(BCN3D_MOD)

#include "FRS_Monitoring.h"

FRS_Monitoring frs_monitor;

uint8_t FRS_Monitoring::runout_count[EXTRUDERS]={ 0 }; // = 0
bool FRS_Monitoring::runout_state[EXTRUDERS]={ false, false }; // = 0

void FRS_Monitoring::setup() {

	#define INIT_RUNOUT_PIN(P) pinMode(P, INPUT)

	INIT_RUNOUT_PIN(FIL_RUNOUT_PIN);
	INIT_RUNOUT_PIN(FIL_RUNOUT2_PIN);

}
void FRS_Monitoring::report(){
	SERIAL_PROTOCOLPGM("frsID0: ");
	SERIAL_PROTOCOL(FRS_Monitoring::runout_state[0]);
	SERIAL_PROTOCOLPGM(" frsID1: ");
	SERIAL_PROTOCOLLN(FRS_Monitoring::runout_state[1]);	
}
	

#endif // BCN3D mod