#include "main.h"
#define END_MENU 6

void flash_check()
{

	int cursor_pos_down_wait=0;
	int count_wait=0;
	int in_game_end=1;
	int test_off=0;
	int i=0;
	int in_game_mode=0;
	button_clear();
	
	//init
	unsigned char data_temp[256];
	unsigned char data_temp2[4];
	unsigned char data_first_1[64];
	unsigned char data_first_2[64];
	unsigned char data_end_1[64];
	unsigned char data_end_2[64];
	char hex_temp[2];
	char hex_temp2[2];
	int erase_sector=0;
	int y=0;
	int x=0;
	int deviceid=0;
	int select_device=0;
	//END MENU
	int menu_exit=END_MENU;
	int bank=0;
	for(i=0;i<64;i++)
	{
		
		data_first_1[i]=0;
		data_first_2[i]=0;
		data_end_1[i]=0;
		data_end_2[i]=0;
	}
	while(in_game_end) {
		if(display_is_old)	{
			DoubleBuffering();
			ClearScreen();
			button_update();
			
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(1,1);
			print_str(30,20,11,"FLASH CHECK");
			print_str(30,40,13,"SELECT DEVICE");

			switch(select_device)
			{
				case 0:
					deviceid=ONBOARD;
					break;
				case 1:
					deviceid=PCCARD1;
					break;
				case 2:
					deviceid=PCCARD2;
					break;
					
			}
			switch(select_device)
			{
				case 0:
					print_str(100,40,7,"ONBOARD");
					break;
				case 1:
					print_str(100,40,7,"PCCARD1");
					break;
				case 2:
					print_str(100,40,7,"PCCARD2");
					break;
				case 3:
					print_str(100,40,5,"NVRAM");
					break;
			}
			sprintf(data_temp, "BANK          %02d",bank);
			print_str(30,50,16,data_temp);
			print_str(30,60,5,"RESET");
			print_str(100,60,5,"ERASE");
			print_str(30,70,10,"AUTOSELECT");
			print_str(100,70,5,"WRITE");
			print_str(150,60,2,hex_temp2);
			print_str(30,190,4,"EXIT");
			switch(in_game_mode){
				case 0:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,40,13,"SELECT DEVICE");
					switch(select_device)
					{
						
						case 0:
							print_str(100,40,7,"ONBOARD");
							break;
						case 1:
							print_str(100,40,7,"PCCARD1");
							break;
						case 2:
							print_str(100,40,7,"PCCARD2");
							break;
						case 3:
							print_str(100,40,5,"NVRAM");
							break;
					}
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 1:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,50,16,data_temp);
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 2:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,60,5,"RESET");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 3:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(100,60,5,"ERASE");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 4:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,70,10,"AUTOSELECT");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 5:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(100,70,5,"WRITE");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;

				case END_MENU:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,190,4,"EXIT");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
			}

			if(pushed_button_hold[2][2]==PAD_ON){
				if(cursor_pos_down_wait==0)
				{
					if(in_game_mode!=menu_exit){
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
			};
			if(pad_read(PAD_TEST)==PAD_ON&&test_off==1){
				if(count_wait==0){
					count_wait=0;
					if(in_game_mode==0)
					{
						select_device++;
						if(select_device==4)
						{
							select_device=0;
						}
					}
					if(in_game_mode==1)
					{
						bank++;
						if(bank==16)
						{
							bank=0;
						}
					}
					if(in_game_mode==2)
					{
						flash_mem_reset(deviceid,bank);
					}
					if(in_game_mode==3)
					{
						flash_mem_reset(deviceid,bank);
						for(erase_sector=0;erase_sector<32;erase_sector++)
						{
							DoubleBuffering();
							ClearScreen();
							sprintf( hex_temp, "%02d",erase_sector);
							flash_mem_erase(deviceid,erase_sector,bank);
							print_str(10,100,12,"Erase Sector");
							print_str(100,100,2,hex_temp);
							print_str(116,100,3,"/31");
							GsDrawList();
							while(GsIsDrawing());
							display_is_old=0;
						}
						flash_mem_reset(deviceid,bank);
					}
					if(in_game_mode==4)
					{
						flash_mem_reset(deviceid,bank);
						flash_mem_autoselect(deviceid,bank);
					}
					if(in_game_mode==5)
					{
						flash_mem_reset(deviceid,bank);
						flash_mem_write_data(deviceid,0,bank,0xAA,0xBB);
						flash_mem_write_data(deviceid,2,bank,0xCC,0xDD);
						flash_mem_write_data(deviceid,4,bank,0xEE,0xFF);
						flash_mem_write_data(deviceid,0x3FFFF0,bank,0x00,0x11);
						flash_mem_write_data(deviceid,0x3FFFF2,bank,0x22,0x33);
						flash_mem_write_data(deviceid,0x3FFFF4,bank,0x44,0x55);
						flash_mem_write_data(deviceid,0x3FFFF6,bank,0x66,0x77);
						flash_mem_write_data(deviceid,0x3FFFF8,bank,0x88,0x99);
						flash_mem_write_data(deviceid,0x3FFFFA,bank,0xAA,0xBB);
						flash_mem_write_data(deviceid,0x3FFFFC,bank,0xCC,0xDD);
						flash_mem_write_data(deviceid,0x3FFFFE,bank,0xCC,0xDD);
					}
	
					if(in_game_mode==menu_exit)
					{
						game_mode=0;
						in_game_end=0;
					}
				}
				
				count_wait++;
			}else{
				count_wait=0;
			}
			//main util
			y=0;
			x=0;
			if(in_game_mode!=menu_exit)
			{
				if(select_device<3){
					print_str(30,90,10,"0x00->0x3F");
					for(i=0;i<64;i++)
					{
						
						data_first_1[i]=flash_mem_read_data(deviceid,i,bank);
						sprintf( hex_temp, "%02x",data_first_1[i]);
						print_str(30+(x*10)+2,100+(y*10),2,hex_temp);
						x++;
						if(x%16==0)
						{
							x=0;
							y++;
						}
					}
				
					y=0;
					x=0;
					print_str(30,140,18,"0x3FFFC0->0x3FFFFF");
					for(i=0;i<64;i++)
					{

						data_first_2[i]=flash_mem_read_data(deviceid,i+0x3FFFC0,bank);
						sprintf( hex_temp, "%02x",data_first_2[i]);
						print_str(30+(x*10)+2,150+(y*10),2,hex_temp);
						x++;
						if(x%16==0)
						{
							x=0;
							y++;
						}
					}
				}else{
					print_str(30,90,10,"0x00->0x3F");
					for(i=0;i<64;i++)
					{
						data_end_1[i]=nvram_read_byte(i);
						sprintf( hex_temp, "%02x",data_end_1[i]);
						print_str(30+(x*10)+2,100+(y*10),2,hex_temp);
						x++;
						if(x%16==0)
						{
							x=0;
							y++;
						}
					}
				
					y=0;
					x=0;
					print_str(30,140,14,"0x1FC0->0x1FFF");
					for(i=0;i<64;i++)
					{
						
						data_end_2[i]=nvram_read_byte(i+0x1fc0);
						sprintf( hex_temp, "%02x",data_end_2[i]);
						print_str(30+(x*10)+2,150+(y*10),2,hex_temp);
						x++;
						if(x%16==0)
						{
							x=0;
							y++;
						}
					}
					
				}

			
			}
			
			GsDrawList();
			
			while(GsIsDrawing());
			display_is_old=0;
		}
	}
}
