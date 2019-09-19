#include "MarlinConfig.h"

#if defined(BCN3D_MOD)

#include "Door_Monitoring.h"

Door_Monitoring door_monitor;

uint8_t Door_Monitoring::door_count = 0; // = 0
bool Door_Monitoring::door_state = false; // = false

void Door_Monitoring::setup() {

	#define INIT_DOOR_PIN(P) pinMode(P, INPUT)

	INIT_DOOR_PIN(SAFE_STOP_PIN);

}
void Door_Monitoring::report(){
	SERIAL_PROTOCOLPGM("door: ");
	SERIAL_PROTOCOLLN(Door_Monitoring::door_state);
}


#endif // BCN3D mod