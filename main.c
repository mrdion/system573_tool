 #include "main.h"
#include "tim/game_res.h"

GsSprite sprite_game[2][12];
void load_sprite()
{
	int i=0;
	int j=0;
	GsImageFromTim(&game_image,game_res);
	GsUploadImage(&game_image);
	
	for(j=0;j<2;j++)
	{
		for(i=0;i<12 ;i++){
			GsSpriteFromImage(&sprite_game[j][i], &game_image, 1);
			sprite_game[j][i].w = 16; sprite_game[j][i].h = 16;sprite_game[j][i].u =16*i; sprite_game[j][i].v = (16*j)+64;
			
		}
	}
}
void title()
{
	
	int test_off=0;
	int title_end=1;
	int cursor_pos_down_wait=0;
	int in_game_mode=0;
	int in_game_mode_max=5;
	int count_wait=0;
	int i=0;
	int j=0;
	unsigned char temp[1];
	while(title_end) {
		if(display_is_old)
		{
			DoubleBuffering();
			ClearScreen();
			GsSortCls(0,0,0);

			print_set_font_status(1,1);
			print_set_font_color(0xFF,0xFF,0xFF);
			print_str(30,20,14,"SYSTEM573 UTIL");
			print_str(30,40,11,"INPUT CHECK");
			print_str(30,50,18,"INPUT TIMING CHECK");
			print_str(30,60,11,"FLASH CHECK");
			print_str(30,70,9,"SIO CHECK");
			print_str(30,80,8,"Util RTC");
			print_str(30,90,4,"DUMP");
			print_str(30,200,28,"SERVICE BUTTON : ITEM SELECT");
			print_str(30,210,19,"TEST BUTTON    : OK");
			switch(in_game_mode){
				case 0:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,40,11,"INPUT CHECK");
					print_set_font_color(0xFF,0xFF,0xFF);
					
					break;
				case 1:
					
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,50,18,"INPUT TIMING CHECK");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 2:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,60,11,"FLASH CHECK");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 3:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,70,9,"SIO CHECK");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 4:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,80,8,"Util RTC");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 5:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,90,8,"DUMP");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
			}
			if(pad_read(PAD_SERVICE)==PAD_ON){
				if(cursor_pos_down_wait==0)
				{
					if(in_game_mode!=in_game_mode_max){
						in_game_mode++;
					}else{
						in_game_mode=0;
					}
				}
				cursor_pos_down_wait++;
				if(cursor_pos_down_wait==10)
				{
					cursor_pos_down_wait=0;
				}
			}else{
				cursor_pos_down_wait=0;
			}
			if(pad_read(PAD_TEST)!=PAD_ON){
				test_off=1;
			}

			if(pad_read(PAD_TEST)==PAD_ON&&test_off==1){
				if(count_wait==0){
					count_wait=0;
					switch(in_game_mode){
						case 0:
							game_mode=1;
							title_end=0;
							break;
						case 1:
							game_mode=2;
							title_end=0;
							break;
						case 2:
							game_mode=7;
							title_end=0;
							break;
						case 3:
							game_mode=8;
							title_end=0;
							break;
						case 4:
							game_mode=3;
							title_end=0;
							break;
						case 5:
							game_mode=9;
							title_end=0;
							break;

					}
				}
				
				count_wait++;
			}else{
				count_wait=0;
			}
			GsDrawList();
			while(GsIsDrawing());
			display_is_old=0;
		}
	}
}

int main() {
	int i=0;
	int j=0;
	init_standard_psx_mode();
	
    int v1 = 10, v2;
    int* p = &v1;

   	game_mode=0;
	load_font();
	load_sprite();
	while(1){
		
		/*DoubleBuffering();
		ClearScreen();
		GsSortCls(128,128,128);
		GsPrintFont(100,300,"test");
    __asm {
        mov ebx, p      ; アドレスを EBX にロード
        mov eax, [ebx]  ; EAX に *p をロード
        mov v2, eax     ; EAX の値を v2 にストア
        mov [ebx], 100  ; 100 を *p にストア
    }

	
		for(j=0;j<6 ;j++){
			for(i=0;i<16 ;i++){
				sprite_font[i+(j*16)].x=(i*5)+10;
				sprite_font[i+(j*16)].y=(8*j)+10;
				GsSortSprite(&sprite_font[i+(j*16)]);
			}
			
		}
		for(j=0;j<2 ;j++){
			for(i=0;i<12 ;i++){
				sprite_game[j][i].x=(i*16)+100;
				sprite_game[j][i].y=(j*16)+10;
				GsSortSprite(&sprite_game[j][i]);
			}
			
		}
		GsDrawList();
		while(GsIsDrawing());
		display_is_old=0;*/
		switch(game_mode)
		{
			case 0:
				title();
				break;
			case 1:
				input_check_1();
				break;
			case 2:
				input_check_2();
				break;
			case 3:
				util_nvram();
				break;
			case 4:
				set_time();
				break;
			case 5:
				set_start();
				break;
			case 6:
				set_battery();
				break;
			case 7:
				flash_check();
				break;
			case 8:
				sio_check();
				break;
			case 9:
				dump();
				break;
			default:
				title();
				break;
		}
	}
}

