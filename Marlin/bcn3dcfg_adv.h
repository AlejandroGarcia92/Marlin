/*
 * bcn3dcfg_adv.h
 *
 * Created: 18/09/2019 13:30:33
 *  Author: agarciamoreno
 */ 
#include "Configuration.h"

#define BCN3D_MOD

//#define BCN3D_PRINT_SIMULATION							//Dummy driver emulator, this define must be disabled
#ifdef BCN3D_PRINT_SIMULATION
	#define SIMULATION_TEMP_AMB							22.5
#endif

//	DUAL MODE SETTINGS
// This defines the Z offset threshold tolerance
#define RAFT_Z_THRESHOLD 0.05
//	END DUAL MODE SETTINGS

#define RETRACT_PRINTER_FACTOR			 8			//(mm)
#define RETRACT_PRINT_TEST_FACTOR		 8			//(mm)
#define PURGE_PRINTER_FACTOR			 20			//(mm)

//RETRACT SETTINGS

//////	RETRACT SETTINGS

#define RETRACT_SPEED_PRINT_TEST		2100.0
#define NOZZLE_PARK_DISTANCE_BED_Y0		-2.5

//BED CALIB
#define CALIB_FEEDRATE_ZAXIS 6*60 // bed homing speeds (mm/min)

#define PAS_M5 0.80

// ZXY Calib

#define NUM_LINES 10
#define LINES_GAP 0.05
//#define LINES_LAYER_HEIGHT_Z   {0.1,0.15,0.15,0.15,0.2,0.2} /// hotend 0.3 0.4 0.5 0.6 0.8 1.0
#define LINES_LAYER_HEIGHT_XY 0.2
#define DRAW_LINE_SPEED		1500.0



#define X_SIGMA_PROBE_SHIFT_BETWEEN 20

//Left extruder probe point
#define X_SIGMA_PROBE_1_LEFT_EXTR	 -4
#define Y_SIGMA_PROBE_1_LEFT_EXTR	 280

#define X_SIGMA_PROBE_2_LEFT_EXTR	 (X_SIGMA_PROBE_1_LEFT_EXTR + X_SIGMA_PROBE_SHIFT_BETWEEN)
#define Y_SIGMA_PROBE_2_LEFT_EXTR	 12.5

#define X_SIGMA_PROBE_3_LEFT_EXTR	 (X_BED_SIZE - 11.5) 
#define Y_SIGMA_PROBE_3_LEFT_EXTR	 Y_SIGMA_PROBE_2_LEFT_EXTR

#define X_SIGMA_PROBE_PIEZO_1_LEFT_EXTR		(X_BED_SIZE / 2 ) 
#define Y_SIGMA_PROBE_PIEZO_1_LEFT_EXTR	 	Y_SIGMA_PROBE_1_LEFT_EXTR

#define X_SIGMA_PROBE_PIEZO_2_LEFT_EXTR	 	10
#define Y_SIGMA_PROBE_PIEZO_2_LEFT_EXTR	 	25

#define X_SIGMA_PROBE_PIEZO_3_LEFT_EXTR	 	(X_BED_SIZE - X_SIGMA_PROBE_PIEZO_2_LEFT_EXTR)
#define Y_SIGMA_PROBE_PIEZO_3_LEFT_EXTR	 	Y_SIGMA_PROBE_PIEZO_2_LEFT_EXTR


//Right extruder probe point
#define X_SIGMA_PROBE_1_RIGHT_EXTR	 (X_SIGMA_PROBE_3_LEFT_EXTR + X_SIGMA_PROBE_SHIFT_BETWEEN)
#define Y_SIGMA_PROBE_1_RIGHT_EXTR	 Y_SIGMA_PROBE_1_LEFT_EXTR

#define X_SIGMA_PROBE_2_RIGHT_EXTR	 X_SIGMA_PROBE_3_LEFT_EXTR
#define Y_SIGMA_PROBE_2_RIGHT_EXTR	 Y_SIGMA_PROBE_2_LEFT_EXTR

#define X_SIGMA_PROBE_3_RIGHT_EXTR	 X_SIGMA_PROBE_2_LEFT_EXTR
#define Y_SIGMA_PROBE_3_RIGHT_EXTR	 Y_SIGMA_PROBE_2_LEFT_EXTR

#define X_GAP_AVOID_COLLISION_LEFT	(13.2)
#define X_GAP_AVOID_COLLISION_RIGHT	(12.7)

//#define CARGOL_1_X  x_screw_bed_calib_1
#define SCREW_BED_1_X (X1_MIN_POS + 262.9)
//#define CARGOL_1_Y  y_screw_bed_calib_1
#define SCREW_BED_1_Y (Y_MAX_POS + 30.3)

//#define CARGOL_2_X  x_screw_bed_calib_2
#define SCREW_BED_2_X (X1_MIN_POS + 54.4)
//#define CARGOL_2_Y  y_screw_bed_calib_2
#define SCREW_BED_2_Y (Y_MAX_POS - 297.2)

//#define CARGOL_3_X  x_screw_bed_calib_3
#define SCREW_BED_3_X (X1_MIN_POS + 471.4)
//#define CARGOL_3_Y  y_screw_bed_calib_3
#define SCREW_BED_3_Y (Y_MAX_POS - 297.2)

#define DEFAULT_DUPLICATION_X_OFFSET 210

#define PARKING_COLLISON_AVOIDANCE
#ifdef PARKING_COLLISON_AVOIDANCE
	#define PARKING_COLLISON_AVOIDANCE_Y_UPPER 50.0
	#define PARKING_COLLISON_AVOIDANCE_Y_LOWER 20.0
#endif


#define Z_RAISE_BEF_PROBING 5      //How much the extruder will be raised before traveling to the first probing point.
#define Z_RAISE_BET_PROBINGS 2.5  //How much the extruder will be raised when traveling from between next probing points

#define FANSPEED_CLASSIC // Support classic fan speed usage

#define G36_LAYER_DIF 0.05
