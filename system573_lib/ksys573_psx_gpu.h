#ifndef _KSYS573_PSX_GPU_H
#define _KSYS573_PSX_GPU_H
#include <psx.h>


unsigned int prim_list[0x4000];
int *wachdog;
volatile int display_is_old;
volatile int frame_counter;

GsDispEnv game_dispenv;
GsDrawEnv game_drawenv;
void init_standard_psx_mode();
void prog_vblank_handler();
void ClearScreen();
void DoubleBuffering();
#endif
