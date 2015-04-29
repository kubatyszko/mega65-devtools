/*
  MEGA65 Partial emulator machine state.

  (C) Copyright Paul Gardner-Stephen 2015.

-- *  This program is free software; you can redistribute it and/or modify
-- *  it under the terms of the GNU General Public License as
-- *  published by the Free Software Foundation; either version 3 of the
-- *  License, or (at your option) any later version.
-- *
-- *  This program is distributed in the hope that it will be useful,
-- *  but WITHOUT ANY WARRANTY; without even the implied warranty of
-- *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- *  GNU General Public License for more details.
-- *
-- *  You should have received a copy of the GNU General Public License
-- *  along with this program; if not, write to the Free Software
-- *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
-- *  02111-1307  USA.

*/

struct gs4510_cpu_state {
  // User-visible CPU state
  unsigned short pc;
  unsigned char a;
  unsigned char x;
  unsigned char y;
  unsigned char z;
  unsigned char spl;
  unsigned char sph;
  unsigned char b;
  unsigned char flags;

  // 4510 MAP state
  unsigned short map_lo_offset;
  unsigned short map_hi_offset;
  unsigned char map_lo_bitmask;
  unsigned char map_hi_bitmask;
  // GS4510 MAP extensions
  unsigned char map_lo_mb;
  unsigned char map_hi_mb;

  // XXX - Hypervisor and other stuff to add here
  
};

struct viciv_state {
  int frame_x;
  int frame_y;

  // XXX - Lots of registers to add here
};

struct mega65_machine_state {
  // Memory arrays
  unsigned char chipram[128*1024];
  unsigned char shadowram[128*1024];
  unsigned char romram[128*1024];
  unsigned char colourram[32*1024];

  struct gs4510_cpu_state cpu_state;

  struct viciv_state viciv_state;
};