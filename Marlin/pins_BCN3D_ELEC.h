/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Bcn3d board pin assignments
 */

/**
 * Rev B  5 DEC 2017
 *
 */



#ifndef __AVR_ATmega2560__
  #error "Oops!  Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu."
#endif

#include "bcn3dcfg_adv.h"

#define BOARD_NAME              "BCN3D ELECTRONICS"



/////////////////////////////////////////////////////

#define LARGE_FLASH true

//BCN3D
//#define MYSERIAL_SCREEN Serial2
#define RESETLINE		9
#define AUTOLEVELPIN	8

//We have inverted the X X2 in BCN3D rev...
#define X_ENABLE_PIN	2
#define X_STEP_PIN		5
#define X_DIR_PIN		3

#define X2_STEP_PIN		73//76
#define X2_DIR_PIN		76//73
#define X2_ENABLE_PIN	75//75

#define X_MIN_PIN		77 //Minim endstop
#define X_MAX_PIN		79 //Max endstop per 2n extrusor

#define E0_STEP_PIN		29
#define E0_DIR_PIN		27
#define E0_ENABLE_PIN	28
//#define E0_STOP		//26

#define E1_STEP_PIN		57//A3
#define E1_DIR_PIN		55//A1
#define E1_ENABLE_PIN	56//A2
//#define E1_STOP		 //A0

#define Z_STEP_PIN		25
#define Z_DIR_PIN		23
#define Z_ENABLE_PIN	24

//#define Z_MIN_PIN		34
//#define Z_MAX_PIN		-1

#define Z_MIN_PIN		34//34
#define Z_MAX_PIN		-1
#define Z2_MIN_PIN		43//43 
#define Z2_MAX_PIN		-1 
//#define Z_ENDSTOP_0 23
//#define Z_ENDSTOP_1 22

#define Y_STEP_PIN		30
#define Y_DIR_PIN		32
#define Y_ENABLE_PIN	31

#define Y_MAX_PIN		33
#define Y_MIN_PIN		-1

#define PS_ON_PIN       -1

//Layer Fans
#define FAN_PIN			45
#define	FAN1_PIN		6
//RGB LEDs
#define GREEN			11
#define	RED				12
#define BLUE			13
//Power Supply Relay
#define	RELAY			10
//HOTEND HEATERS
#define	HEATER_0_PIN	44
#define	HEATER_1_PIN	7
#define HEATER_2_PIN	-1
//HEATED BED
#define HEATER_BED_PIN	46
//THERMISTORS
#define TEMP_0_PIN		9//62//A9
#define TEMP_1_PIN		8//63//A8
#define TEMP_2_PIN		-1
#define TEMP_BED_PIN	15//69//A15

#define MLED			68//A14

#define SDSS			53
#define SDPOWER			-1
#define LED_PIN			-1
//#define SDCARDDETECT	-1

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
#define SCK_PIN          52
#define MISO_PIN         50
#define MOSI_PIN         51
#endif