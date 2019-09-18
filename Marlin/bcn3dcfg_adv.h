/*
 * bcn3dcfg_adv.h
 *
 * Created: 18/09/2019 13:30:33
 *  Author: agarciamoreno
 */ 


#define BCN3D_MOD

#define BCN3D_PRINTER_IS_SIGMA	 	3107
#define BCN3D_PRINTER_IS_SIGMAX		713

#ifndef BCN3D_PRINTER_SETUP
#define BCN3D_PRINTER_SETUP BCN3D_PRINTER_IS_SIGMA
#endif

//	DUAL MODE SETTINGS
// This defines the Z offset threshold tolerance
#define RAFT_Z_THRESHOLD 0.05
//	END DUAL MODE SETTINGS

//////	PAUSE PRINT
#if BCN3D_PRINTER_SETUP == BCN3D_PRINTER_IS_SIGMAX
#define RETRACT_PRINTER_FACTOR			 8				//(mm)
#define RETRACT_PRINT_TEST_FACTOR		 8				//(mm)
#define PAUSE_G69_XYMOVE				 5				//(mm)
#define PAUSE_G70_ZMOVE					 2				//(mm)
#define PURGE_PRINTER_FACTOR			 20				//(mm)
#endif
#if BCN3D_PRINTER_SETUP == BCN3D_PRINTER_IS_SIGMA
#define RETRACT_PRINTER_FACTOR			 6				//(mm)
#define RETRACT_PRINT_TEST_FACTOR		 6				//(mm)
#define PAUSE_G69_XYMOVE				 5				//(mm)
#define PAUSE_G70_ZMOVE					 2				//(mm)
#define PURGE_PRINTER_FACTOR			 20				//(mm)
#endif

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

//Left extruder probe point
#define X_SIGMA_PROBE_1_LEFT_EXTR 55
#define Y_SIGMA_PROBE_1_LEFT_EXTR 265
//#define Y_SIGMA_PROBE_1_LEFT_EXTR 275

#define X_SIGMA_PROBE_2_LEFT_EXTR 55
#define Y_SIGMA_PROBE_2_LEFT_EXTR 10
//#define Y_SIGMA_PROBE_2_LEFT_EXTR 10

#define X_SIGMA_PROBE_3_LEFT_EXTR 254
#define Y_SIGMA_PROBE_3_LEFT_EXTR 10
//#define Y_SIGMA_PROBE_3_LEFT_EXTR 10

//Right extruder probe point
#define X_SIGMA_PROBE_1_RIGHT_EXTR 254
#define Y_SIGMA_PROBE_1_RIGHT_EXTR 265
//#define Y_SIGMA_PROBE_1_RIGHT_EXTR 275

#define X_SIGMA_PROBE_2_RIGHT_EXTR 254
#define Y_SIGMA_PROBE_2_RIGHT_EXTR 10
//#define Y_SIGMA_PROBE_2_RIGHT_EXTR 10

#define X_SIGMA_PROBE_3_RIGHT_EXTR 55
#define Y_SIGMA_PROBE_3_RIGHT_EXTR 10
//#define Y_SIGMA_PROBE_3_RIGHT_EXTR 10

#define X_GAP_AVOID_COLLISION_LEFT	10
#define X_GAP_AVOID_COLLISION_RIGHT	13

////Left extruder probe point
//#define X_SIGMA_PROBE_1_LEFT_EXTR 58.5
//#define Y_SIGMA_PROBE_1_LEFT_EXTR 265
////#define Y_SIGMA_PROBE_1_LEFT_EXTR 275
//
//#define X_SIGMA_PROBE_2_LEFT_EXTR 58.5
//#define Y_SIGMA_PROBE_2_LEFT_EXTR 10
////#define Y_SIGMA_PROBE_2_LEFT_EXTR 10
//
//#define X_SIGMA_PROBE_3_LEFT_EXTR 468 //254
//#define Y_SIGMA_PROBE_3_LEFT_EXTR 10
////#define Y_SIGMA_PROBE_3_LEFT_EXTR 10
//
////Right extruder probe point
//#define X_SIGMA_PROBE_1_RIGHT_EXTR 468//254
//#define Y_SIGMA_PROBE_1_RIGHT_EXTR 265
////#define Y_SIGMA_PROBE_1_RIGHT_EXTR 275
//
//#define X_SIGMA_PROBE_2_RIGHT_EXTR 468 ///254
//#define Y_SIGMA_PROBE_2_RIGHT_EXTR 10
////#define Y_SIGMA_PROBE_2_RIGHT_EXTR 10
//
//#define X_SIGMA_PROBE_3_RIGHT_EXTR 58.5
//#define Y_SIGMA_PROBE_3_RIGHT_EXTR 10
////#define Y_SIGMA_PROBE_3_RIGHT_EXTR 10
//
//#define X_GAP_AVOID_COLLISION_LEFT	14.5
//#define X_GAP_AVOID_COLLISION_RIGHT	19.5

#define Z_RAISE_BEF_PROBING 5      //How much the extruder will be raised before traveling to the first probing point.
#define Z_RAISE_BET_PROBINGS 2.5  //How much the extruder will be raised when traveling from between next probing points

//Screw positions on BED for
#define CARGOL_1_X  263.5
//#define CARGOL_1_X  104;
#define CARGOL_1_Y  272.5

#define CARGOL_2_X  86
//#define CARGOL_2_X  17;
#define CARGOL_2_Y  19

#define CARGOL_3_X  441
//#define CARGOL_3_X  192;
#define CARGOL_3_Y  19