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

#ifndef THERMISTORTABLES_H_
#define THERMISTORTABLES_H_

#include "Marlin.h"
#include "macros.h"

#define OVERSAMPLENR 16
#define OV(N) int16_t((N)*(OVERSAMPLENR))

#define ANY_THERMISTOR_IS(n) (THERMISTORHEATER_0 == n || THERMISTORHEATER_1 == n || THERMISTORHEATER_2 == n || THERMISTORHEATER_3 == n || THERMISTORHEATER_4 == n || THERMISTORBED == n || THERMISTORCHAMBER == n)

// Pt1000 and Pt100 handling
//
// Rt=R0*(1+a*T+b*T*T) [for T>0]
// a=3.9083E-3, b=-5.775E-7
#define PtA 3.9083E-3
#define PtB -5.775E-7
#define PtRt(T,R0) ((R0)*(1.0+(PtA)*(T)+(PtB)*(T)*(T)))
#define PtAdVal(T,R0,Rup) (short)(1024/(Rup/PtRt(T,R0)+1))
#define PtLine(T,R0,Rup) { OV(PtAdVal(T,R0,Rup)), T },


  #include "thermistortable_1.h"

  #include "thermistortable_2.h"

  #include "thermistortable_3.h"

  #include "thermistortable_4.h"

  #include "thermistortable_5.h"

  #include "thermistortable_501.h"

  #include "thermistortable_6.h"

  #include "thermistortable_7.h"

  #include "thermistortable_71.h"

  #include "thermistortable_8.h"

  #include "thermistortable_9.h"

  #include "thermistortable_10.h"

  #include "thermistortable_11.h"

  #include "thermistortable_13.h"

  #include "thermistortable_15.h"

  #include "thermistortable_20.h"

  #include "thermistortable_51.h"

  #include "thermistortable_52.h"

  #include "thermistortable_55.h"

  #include "thermistortable_60.h"

  #include "thermistortable_66.h"

  #include "thermistortable_12.h"

  #include "thermistortable_70.h"

  #include "thermistortable_75.h"

  #include "thermistortable_110.h"

  #include "thermistortable_147.h"

  #include "thermistortable_1010.h"

  #include "thermistortable_1047.h"

  #include "thermistortable_998.h"

  #include "thermistortable_999.h"


#define _TT_NAME(_N) temptable_ ## _N
#define TT_NAME(_N) _TT_NAME(_N)

#if THERMISTORHEATER_0
  #define HEATER_0_TEMPTABLE TT_NAME(THERMISTORHEATER_0)
  #define HEATER_0_TEMPTABLE_LEN COUNT(HEATER_0_TEMPTABLE)
#elif defined(HEATER_0_USES_THERMISTOR)
  #error "No heater 0 thermistor table specified"
#else
  #define HEATER_0_TEMPTABLE NULL
  #define HEATER_0_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_1
  #define HEATER_1_TEMPTABLE TT_NAME(THERMISTORHEATER_1)
  #define HEATER_1_TEMPTABLE_LEN COUNT(HEATER_1_TEMPTABLE)
#elif defined(HEATER_1_USES_THERMISTOR)
  #error "No heater 1 thermistor table specified"
#else
  #define HEATER_1_TEMPTABLE NULL
  #define HEATER_1_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_2
  #define HEATER_2_TEMPTABLE TT_NAME(THERMISTORHEATER_2)
  #define HEATER_2_TEMPTABLE_LEN COUNT(HEATER_2_TEMPTABLE)
#elif defined(HEATER_2_USES_THERMISTOR)
  #error "No heater 2 thermistor table specified"
#else
  #define HEATER_2_TEMPTABLE NULL
  #define HEATER_2_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_3
  #define HEATER_3_TEMPTABLE TT_NAME(THERMISTORHEATER_3)
  #define HEATER_3_TEMPTABLE_LEN COUNT(HEATER_3_TEMPTABLE)
#elif defined(HEATER_3_USES_THERMISTOR)
  #error "No heater 3 thermistor table specified"
#else
  #define HEATER_3_TEMPTABLE NULL
  #define HEATER_3_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_4
  #define HEATER_4_TEMPTABLE TT_NAME(THERMISTORHEATER_4)
  #define HEATER_4_TEMPTABLE_LEN COUNT(HEATER_4_TEMPTABLE)
#elif defined(HEATER_4_USES_THERMISTOR)
  #error "No heater 4 thermistor table specified"
#else
  #define HEATER_4_TEMPTABLE NULL
  #define HEATER_4_TEMPTABLE_LEN 0
#endif

#ifdef THERMISTORBED
  #define BEDTEMPTABLE TT_NAME(THERMISTORBED)
  #define BEDTEMPTABLE_LEN COUNT(BEDTEMPTABLE)
  static void* bedTempTable = temptable_1;
  static uint8_t bedTempTableLen = COUNT(&bedTempTable);
  
#elif defined(HEATER_BED_USES_THERMISTOR)
  #error "No bed thermistor table specified"
#else
  #define BEDTEMPTABLE_LEN 0
#endif

#ifdef THERMISTORCHAMBER
  #define CHAMBERTEMPTABLE TT_NAME(THERMISTORCHAMBER)
  #define CHAMBERTEMPTABLE_LEN COUNT(CHAMBERTEMPTABLE)
#elif defined(HEATER_CHAMBER_USES_THERMISTOR)
  #error "No chamber thermistor table specified"
#else
  #define CHAMBERTEMPTABLE_LEN 0
#endif

// The SCAN_THERMISTOR_TABLE macro needs alteration?
static_assert(HEATER_0_TEMPTABLE_LEN < 256 && HEATER_1_TEMPTABLE_LEN < 256 && HEATER_2_TEMPTABLE_LEN < 256 && HEATER_3_TEMPTABLE_LEN < 256 && HEATER_4_TEMPTABLE_LEN < 256 && BEDTEMPTABLE_LEN < 256 && CHAMBERTEMPTABLE_LEN < 256,
  "Temperature conversion tables over 255 entries need special consideration."
);

// Set the high and low raw values for the heaters
// For thermistors the highest temperature results in the lowest ADC value
// For thermocouples the highest temperature results in the highest ADC value
#ifndef HEATER_0_RAW_HI_TEMP
  #ifdef HEATER_0_USES_THERMISTOR
    #define HEATER_0_RAW_HI_TEMP 0
    #define HEATER_0_RAW_LO_TEMP 16383
  #else
    #define HEATER_0_RAW_HI_TEMP 16383
    #define HEATER_0_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_1_RAW_HI_TEMP
  #ifdef HEATER_1_USES_THERMISTOR
    #define HEATER_1_RAW_HI_TEMP 0
    #define HEATER_1_RAW_LO_TEMP 16383
  #else
    #define HEATER_1_RAW_HI_TEMP 16383
    #define HEATER_1_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_2_RAW_HI_TEMP
  #ifdef HEATER_2_USES_THERMISTOR
    #define HEATER_2_RAW_HI_TEMP 0
    #define HEATER_2_RAW_LO_TEMP 16383
  #else
    #define HEATER_2_RAW_HI_TEMP 16383
    #define HEATER_2_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_3_RAW_HI_TEMP
  #ifdef HEATER_3_USES_THERMISTOR
    #define HEATER_3_RAW_HI_TEMP 0
    #define HEATER_3_RAW_LO_TEMP 16383
  #else
    #define HEATER_3_RAW_HI_TEMP 16383
    #define HEATER_3_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_4_RAW_HI_TEMP
  #ifdef HEATER_4_USES_THERMISTOR
    #define HEATER_4_RAW_HI_TEMP 0
    #define HEATER_4_RAW_LO_TEMP 16383
  #else
    #define HEATER_4_RAW_HI_TEMP 16383
    #define HEATER_4_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_BED_RAW_HI_TEMP
  #ifdef HEATER_BED_USES_THERMISTOR
    #define HEATER_BED_RAW_HI_TEMP 0
    #define HEATER_BED_RAW_LO_TEMP 16383
  #else
    #define HEATER_BED_RAW_HI_TEMP 16383
    #define HEATER_BED_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_CHAMBER_RAW_HI_TEMP
  #ifdef HEATER_CHAMBER_USES_THERMISTOR
    #define HEATER_CHAMBER_RAW_HI_TEMP 0
    #define HEATER_CHAMBER_RAW_LO_TEMP 16383
  #else
    #define HEATER_CHAMBER_RAW_HI_TEMP 16383
    #define HEATER_CHAMBER_RAW_LO_TEMP 0
  #endif
#endif

#endif // THERMISTORTABLES_H_
