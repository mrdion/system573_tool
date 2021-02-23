#include "ksys573_psx_gpu.h"
#include <psx.h>
void init_standard_psx_mode(){
	GsInit();
	GsClearMem();
	GsSetVideoMode(320, 240,VMODE_NTSC);
	game_dispenv.x=0;
   	game_dispenv.y=0;
  	GsSetDispEnv(&game_dispenv);
  	game_drawenv.x=0;
   	game_drawenv.y=0;
  	game_drawenv.w=320;
   	game_drawenv.h=240;
  	game_drawenv.draw_on_display=1;
  	game_drawenv.ignore_mask=0;
 	game_drawenv.dither=0;
  	game_drawenv.set_mask=0;
   	GsSetDrawEnv(&game_drawenv);
	GsLoadFont(768, 0, 768, 256);
	GsSetList(prim_list);
	SetVBlankHandler(prog_vblank_handler);
	frame_counter=0;
	display_is_old=1;
	wachdog=(int*)0x1f5c0000;
}
void prog_vblank_handler() {
	display_is_old = 1;
	frame_counter++;
	if(frame_counter==120)
	{
		frame_counter=0;
	}
}
void ClearScreen(){
	GsRectangle gs_rect;
	gs_rect.x = 0;
	gs_rect.y = 0;
	gs_rect.w = 320;
	gs_rect.h = 240;
	gs_rect.r = 0;
	gs_rect.g = 0;
	gs_rect.b = 0;
	gs_rect.attribute = 0;   
	GsSortRectangle(&gs_rect);

}

void DoubleBuffering(){

if(game_dispenv.y == 0)
      {
         game_dispenv.y = 256;
         game_drawenv.y = 0;
      }
      else
      {
         game_dispenv.y = 0;
         game_drawenv.y = 256;
      }
      *wachdog=0x0;
      GsSetDispEnv(&game_dispenv);
      GsSetDrawEnv(&game_drawenv);
        
}