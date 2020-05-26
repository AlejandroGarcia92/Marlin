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

#undef THERMISTOR_NAME

// Thermcouples
#if THERMISTOR_ID == -4
  #define THERMISTOR_NAME "AD8495"
#elif THERMISTOR_ID == -3
  #define THERMISTOR_NAME "MAX31855"
#elif THERMISTOR_ID == -2
  #define THERMISTOR_NAME "MAX6675"
#elif THERMISTOR_ID == -1
  #define THERMISTOR_NAME "AD595"

// Standard thermistors
#elif THERMISTOR_ID == 1
  #define THERMISTOR_NAME "EPCOS 100K"
#elif THERMISTOR_ID == 2
  #define THERMISTOR_NAME "ATC 204GT-2"
#elif THERMISTOR_ID == 3
  #define THERMISTOR_NAME "Mendel-parts"
#elif THERMISTOR_ID == 4
  #define THERMISTOR_NAME "Generic 10K"
#elif THERMISTOR_ID == 5
  #define THERMISTOR_NAME "ATC 104GT-2"
#elif THERMISTOR_ID == 6
  #define THERMISTOR_NAME "EPCOS (alt)"
#elif THERMISTOR_ID == 7
  #define THERMISTOR_NAME "Honeywell 104LAG"
#elif THERMISTOR_ID == 71
  #define THERMISTOR_NAME "Honeywell 104LAF"
#elif THERMISTOR_ID == 8
  #define THERMISTOR_NAME "E3104FHT"
#elif THERMISTOR_ID == 9
  #define THERMISTOR_NAME "GE AL03006"
#elif THERMISTOR_ID == 10
  #define THERMISTOR_NAME "RS 198-961"
#elif THERMISTOR_ID == 11
  #define THERMISTOR_NAME "1% beta 3950"
#elif THERMISTOR_ID == 12
  #define THERMISTOR_NAME "Unknown"
#elif THERMISTOR_ID == 13
  #define THERMISTOR_NAME "Hisens"
#elif THERMISTOR_ID == 20
  #define THERMISTOR_NAME "PT100 UltiMB"
#elif THERMISTOR_ID == 60
  #define THERMISTOR_NAME "Makers Tool"
#elif THERMISTOR_ID == 70
  #define THERMISTOR_NAME "Hephestos 2"
#elif THERMISTOR_ID == 75
  #define THERMISTOR_NAME "MGB18"

// Modified thermistors
#elif THERMISTOR_ID == 51
  #define THERMISTOR_NAME "EPCOS 1K"
#elif THERMISTOR_ID == 52
  #define THERMISTOR_NAME "ATC204GT-2 1K"
#elif THERMISTOR_ID == 55
  #define THERMISTOR_NAME "ATC104GT-2 1K"
#elif THERMISTOR_ID == 1047
  #define THERMISTOR_NAME "PT1000 4K7"
#elif THERMISTOR_ID == 1010
  #define THERMISTOR_NAME "PT1000 1K"
#elif THERMISTOR_ID == 147
  #define THERMISTOR_NAME "PT100 4K7"
#elif THERMISTOR_ID == 110
  #define THERMISTOR_NAME "PT100 1K"

// High Temperature thermistors
#elif THERMISTOR_ID == 66
  #define THERMISTOR_NAME "Dyze 4.7M"

// Dummies for dev testing
#elif THERMISTOR_ID == 998
  #define THERMISTOR_NAME "Dummy 1"
#elif THERMISTOR_ID == 999
  #define THERMISTOR_NAME "Dummy 2"

#endif // THERMISTOR_ID

// Thermcouples

const char* const thermistor_name_AD8495 = "AD8495";
#define THERMISTOR_NAME_AD8495 thermistor_name_AD8495

const char* const thermistor_name_MAX31855 = "MAX31855";
#define THERMISTOR_NAME_MAX31855 thermistor_name_MAX31855

const char* const thermistor_name_MAX6675 = "MAX6675";
#define THERMISTOR_NAME_MAX6675 thermistor_name_MAX6675

const char* const thermistor_name_AD595 = "AD595";
#define THERMISTOR_NAME_AD595 thermistor_name_AD595

// Standard thermistors

const char* const thermistor_name_1 = "EPCOS 100K";
#define THERMISTOR_NAME_1 thermistor_name_1

const char* const thermistor_name_2 = "ATC 204GT-2";
#define THERMISTOR_NAME_2 thermistor_name_2

const char* const thermistor_name_3 = "Mendel-parts";
#define THERMISTOR_NAME_3 thermistor_name_3

const char* const thermistor_name_4 = "Generic 10K";
#define THERMISTOR_NAME_4 thermistor_name_4

const char* const thermistor_name_5 = "ATC 104GT-2";
#define THERMISTOR_NAME_5 thermistor_name_5

const char* const thermistor_name_6 = "EPCOS (alt)";
#define THERMISTOR_NAME_6 thermistor_name_6

const char* const thermistor_name_7 = "Honeywell 104LAG";
#define THERMISTOR_NAME_7 thermistor_name_7

const char* const thermistor_name_71 = "Honeywell 104LAF";
#define THERMISTOR_NAME_71 thermistor_name_71

const char* const thermistor_name_8 = "E3104FHT";
#define THERMISTOR_NAME_8 thermistor_name_8

const char* const thermistor_name_9 = "GE AL03006";
#define THERMISTOR_NAME_9 thermistor_name_9

const char* const thermistor_name_10 = "RS 198-961";
#define THERMISTOR_NAME_10 thermistor_name_10

const char* const thermistor_name_11 = "1% beta 3950";
#define THERMISTOR_NAME_11 thermistor_name_11

const char* const thermistor_name_12 = "Unknown";
#define THERMISTOR_NAME_12 thermistor_name_12

const char* const thermistor_name_501 = "Unknown";
#define THERMISTOR_NAME_501 thermistor_name_501

const char* const thermistor_name_15 = "Unknown";
#define THERMISTOR_NAME_15 thermistor_name_15

const char* const thermistor_name_75 = "Unknown";
#define THERMISTOR_NAME_75 thermistor_name_75

const char* const thermistor_name_13 = "Hisens";
#define THERMISTOR_NAME_13 thermistor_name_13

const char* const thermistor_name_20 = "PT100 UltiMB";
#define THERMISTOR_NAME_20 thermistor_name_20

const char* const thermistor_name_60 = "Makers Tool";
#define THERMISTOR_NAME_60 thermistor_name_60

const char* const thermistor_name_70 = "Hephestos 2";
#define THERMISTOR_NAME_70 thermistor_name_70

const char* const thermistor_name_80 = "MGB18";
#define THERMISTOR_NAME_80 thermistor_name_80

// Modified thermistors

const char* const thermistor_name_51 = "EPCOS 1K";
#define THERMISTOR_NAME_51 thermistor_name_51

const char* const thermistor_name_52 = "ATC204GT-2 1K";
#define THERMISTOR_NAME_52 thermistor_name_52

const char* const thermistor_name_55 = "ATC104GT-2 1K";
#define THERMISTOR_NAME_55 thermistor_name_55

const char* const thermistor_name_1047 = "PT1000 4K7";
#define THERMISTOR_NAME_1047 thermistor_name_1047

const char* const thermistor_name_1010 = "PT1000 1K";
#define THERMISTOR_NAME_1010 thermistor_name_1010

const char* const thermistor_name_147 = "PT100 4K7";
#define THERMISTOR_NAME_147 thermistor_name_147

const char* const thermistor_name_110 = "PT100 1K";
#define THERMISTOR_NAME_110 thermistor_name_110

// High Temperature thermistors

const char* const thermistor_name_66 = "Dyze 4.7M";
#define THERMISTOR_NAME_66 thermistor_name_66

// Dummies for dev testing

const char* const thermistor_name_998 = "Dummy 1";
#define THERMISTOR_NAME_998 thermistor_name_998

const char* const thermistor_name_999 = "Dummy 2";
#define THERMISTOR_NAME_999 thermistor_name_999
