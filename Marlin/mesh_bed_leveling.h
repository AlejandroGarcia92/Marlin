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

#ifndef _MESH_BED_LEVELING_H_
#define _MESH_BED_LEVELING_H_

#include "MarlinConfig.h"

enum MeshLevelingState : char {
  MeshReport,
  MeshStart,
  MeshNext,
  MeshSet,
  MeshSetZOffset,
  MeshReset
};

extern uint8_t meshPointsX;
extern uint8_t meshPointsY;
extern float xBedSize;
extern float yBedSize;
extern float x_probe_left_extr[3];
extern float y_probe_left_extr[3];

class mesh_bed_leveling {
public:
  static float z_offset,
               mesh_x_dist,
               mesh_y_dist;

  static float * z_values;
  static float * index_to_xpos;
  static float * index_to_ypos;

  mesh_bed_leveling();
  ~mesh_bed_leveling();

  static void report_mesh();

  static void reset();

  static void update_mesh_bed_leveling(float max_x, float max_y);

  FORCE_INLINE static bool has_mesh() {
    for (uint8_t x = 0; x < GRID_MAX_POINTS_X; x++)
      for (uint8_t y = 0; y < GRID_MAX_POINTS_Y; y++)
        if (*((z_values+x)+y)) return true;
    return false;
  }

  static void set_z(const int8_t px, const int8_t py, const float &z) { *((z_values+px)+py) = z; }

  static inline void zigzag(const int8_t index, int8_t &px, int8_t &py) {
    px = index % (meshPointsX);
    py = index / (meshPointsY);
    if (py & 1) px = (meshPointsX - 1) - px; // Zig zag
  }

  static void set_zigzag_z(const int8_t index, const float &z) {
    int8_t px, py;
    zigzag(index, px, py);
    set_z(px, py, z);
  }

  static int8_t cell_index_x(const float &x) {
    int8_t cx = (x - (x_probe_left_extr[1])) * (1.0f / (mesh_x_dist));
    return constrain(cx, 0, (meshPointsX) - 2);
  }

  static int8_t cell_index_y(const float &y) {
    int8_t cy = (y - (y_probe_left_extr[1])) * (1.0f / (mesh_y_dist));
    return constrain(cy, 0, (meshPointsY) - 2);
  }

  static int8_t probe_index_x(const float &x) {
    int8_t px = (x - (x_probe_left_extr[1]) + 0.5f * (mesh_x_dist)) * (1.0f / (mesh_x_dist));
    return WITHIN(px, 0, meshPointsX - 1) ? px : -1;
  }

  static int8_t probe_index_y(const float &y) {
    int8_t py = (y - (x_probe_left_extr[1]) + 0.5f * (mesh_y_dist)) * (1.0f / (mesh_y_dist));
    return WITHIN(py, 0, meshPointsY - 1) ? py : -1;
  }

  static float calc_z0(const float &a0, const float &a1, const float &z1, const float &a2, const float &z2) {
    const float delta_z = (z2 - z1) / (a2 - a1),
                delta_a = a0 - a1;
    return z1 + delta_a * delta_z;
  }

  static float get_z(const float &x0, const float &y0
    #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
      , const float &factor
    #endif
  ) {
    const int8_t cx = cell_index_x(x0), cy = cell_index_y(y0);
    const float z1 = calc_z0(x0, index_to_xpos[cx], *((z_values+cx)+cy), index_to_xpos[cx + 1], *((z_values+cx+1)+cy));
    const float z2 = calc_z0(x0, index_to_xpos[cx], *((z_values+cx)+(cy+1)), index_to_xpos[cx + 1], *((z_values+cx+1)+(cy+1)));
    const float z0 = calc_z0(y0, index_to_ypos[cy], z1, index_to_ypos[cy + 1], z2);

    return z_offset + z0
      #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
        * factor
      #endif
    ;
  }
};

extern mesh_bed_leveling* mbl;

#endif // _MESH_BED_LEVELING_H_
