#include "main.h"
void set_time()
{

	int set_time_year= nvram_get_year();
	int set_time_month= nvram_get_month() ;
	int set_time_date= nvram_get_date() ;
	int set_time_wod= nvram_get_day_of_the_week();
	int set_time_hour= nvram_get_hour();
	int set_time_minites=  nvram_get_minites();
	int set_time_seconds= nvram_get_seconds();
	int cursor_pos_down_wait=0;
	int count_wait=0;
	int in_game_end=1;
	int test_off=0;
	char hex_temp[2];
	int in_game_mode=0;
	while(in_game_end) {
		if(display_is_old)	{
			DoubleBuffering();
			ClearScreen();
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(1,1);
			print_str(30,20,8,"SET TIME");
			sprintf( hex_temp, "%02x",set_time_year );
			print_str(30,40,2,hex_temp);
			print_str(40,40,1,"/");
			sprintf( hex_temp, "%02x", set_time_month );
			print_str(45,40,2,hex_temp);
			print_str(55,40,1,"/");
			sprintf( hex_temp, "%02x", set_time_date );
			print_str(60,40,2,hex_temp);
			print_str(70,40,1,"-");
			print_str(75, 40,4,get_day_of_the_week_from_int(set_time_wod));
 			sprintf( hex_temp, "%02x", set_time_hour);
			print_str(160,40,2,hex_temp);
			print_str(170,40,1,":");
		 	sprintf( hex_temp, "%02x", set_time_minites);
			print_str(175,40,2,hex_temp);
			print_str(185,40,1,"-");;
		 	sprintf( hex_temp, "%02x", set_time_seconds);
			print_str(190,40,2,hex_temp);
			print_str(30,120,9,"SAVE TIME");
			print_str(30,130,4,"EXIT");
			switch(in_game_mode){
				case 0:
					print_set_font_color(0xFF,0x00,0x00);
					sprintf( hex_temp, "%02x",set_time_year );
					print_str(30,40,2,hex_temp);
					print_set_font_color(0xFF,0xFF,0xFF);
					
					break;
				case 1:
					
					print_set_font_color(0xFF,0x00,0x00);
					sprintf( hex_temp, "%02x", set_time_month );
					print_str(45,40,2,hex_temp);
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 2:
					print_set_font_color(0xFF,0x00,0x00);
					sprintf( hex_temp, "%02x", set_time_date );
					print_str(60,40,2,hex_temp);
					print_set_font_color(0xFF,0xFF,0xFF);
					
					break;
				case 3:
					
					print_set_font_color(0xFF,0x00,0x00);
					print_str(75, 40,4,get_day_of_the_week_from_int(set_time_wod));
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 4:
					
					print_set_font_color(0xFF,0x00,0x00);
					sprintf( hex_temp, "%02x", set_time_hour);
					print_str(160,40,2,hex_temp);
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 5:
					
					print_set_font_color(0xFF,0x00,0x00);
				 	sprintf( hex_temp, "%02x", set_time_minites);
					print_str(175,40,2,hex_temp);
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 6:
					
					print_set_font_color(0xFF,0x00,0x00);
		 			sprintf( hex_temp, "%02x", set_time_seconds);
					print_str(190,40,2,hex_temp);
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 7:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,120,9,"SAVE TIME");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				case 8:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,130,4,"EXIT");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				defalut:
					break;
			}

			if(pad_read(PAD_SERVICE)==PAD_ON){
				if(cursor_pos_down_wait==0)
				{
					if(in_game_mode!=8){
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
							set_time_year++;
							if(set_time_year==0x0A){
								set_time_year=0x10;
							}
							if(set_time_year==0x1A){
								set_time_year=0x20;
							}
							if(set_time_year==0x2A){
								set_time_year=0x30;
							}
							if(set_time_year==0x3A){
								set_time_year=0x40;
							}
							if(set_time_year==0x4A){
								set_time_year=0x50;
							}
							if(set_time_year==0x5A){
								set_time_year=0x60;
							}
							if(set_time_year==0x6A){
								set_time_year=0x70;
							}
							if(set_time_year==0x7A){
								set_time_year=0x80;
							}
							if(set_time_year==0x8A){
								set_time_year=0x90;
							}
							if(set_time_year>0x99)
							{
								set_time_year=0;
							}
							break;
						case 1:
							set_time_month++;
							if(set_time_month==0x0A){
								set_time_month=0x10;
							}
							if(set_time_month==0x1A){
								set_time_month=0x20;
							}
							if(set_time_month>0x12)
							{
								set_time_month=1;
							}
							break;
						case 2:
							set_time_date++;
							if(set_time_date==0x0A){
								set_time_date=0x10;
							}
							if(set_time_date==0x1A){
								set_time_date=0x20;
							}
							if(set_time_date==0x2A){
								set_time_date=0x30;
							}
							if(set_time_date>0x31)
							{
								set_time_date=1;
							}
							break;
						case 3:
							set_time_wod++;
							if(set_time_wod>0x7)
							{
								set_time_wod=1;
							}
							break;
						case 4:
							set_time_hour++;
							if(set_time_hour==0x0A){
								set_time_hour=0x10;
							}
							if(set_time_hour==0x1A){
								set_time_hour=0x20;
							}
							if(set_time_hour>0x24)
							{
								set_time_hour=0;
							}
							break;
						case 5:
							set_time_minites++;
							if(set_time_minites==0x0A){
								set_time_minites=0x10;
							}
							if(set_time_minites==0x1A){
								set_time_minites=0x20;
							}
							if(set_time_minites==0x2A){
								set_time_minites=0x30;
							}
							if(set_time_minites==0x3A){
								set_time_minites=0x40;
							}
							if(set_time_minites==0x4A){
								set_time_minites=0x50;
							}
							if(set_time_minites==0x5A){
								set_time_minites=0x60;
							}
							if(set_time_minites>0x59)
							{
								set_time_minites=0;
							}
							break;
						case 6:
							set_time_seconds++;
							if(set_time_seconds==0x0A){
								set_time_seconds=0x10;
							}
							if(set_time_seconds==0x1A){
								set_time_seconds=0x20;
							}
							if(set_time_seconds==0x2A){
								set_time_seconds=0x30;
							}
							if(set_time_seconds==0x3A){
								set_time_seconds=0x40;
							}
							if(set_time_seconds==0x4A){
								set_time_seconds=0x50;
							}
							if(set_time_seconds==0x5A){
								set_time_seconds=0x60;
							}
							if(set_time_seconds>0x59)
							{
								set_time_seconds=0;
							}
							break;
						case 7:
					
							nvram_set_year(set_time_year&0xFF);
							nvram_set_month(set_time_month&0xFF);
							nvram_set_date(set_time_date&0xFF);
							nvram_set_day_of_the_week(set_time_wod&0xFF);
							nvram_set_hour(set_time_hour&0xFF);
							nvram_set_minites(set_time_minites&0xFF);
							nvram_set_seconds(set_time_seconds&0xFF);
							break;
						case 8:
							game_mode=3;
							in_game_end=0;
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
void set_start()
{

	int stop_bit_value= nvram_get_stop_bit();
	int cursor_pos_down_wait=0;
	int count_wait=0;
	int in_game_end=1;
	int test_off=0;
	int i=0;
	char hex_temp[2];
	int in_game_mode=0;
	while(in_game_end) {
		if(display_is_old)	{
			DoubleBuffering();
			ClearScreen();
			
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(1,1);
			print_str(30,20,8,"SET STOP BIT");
			print_str(30,40,9,"STOP BIT=");
			print_int(85,40,stop_bit_value);
			print_str(30,120,13,"SAVE STOP BIT");
			print_str(30,130,4,"EXIT");
			switch(in_game_mode){
				case 0:
					print_set_font_color(0xFF,0x00,0x00);
					print_int(85,40,stop_bit_value);	
					print_set_font_color(0xFF,0xFF,0xFF);
					
					break;
				
				case 1:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,120,13,"SAVE STOP BIT");
					print_set_font_color(0xFF,0xFF,0xFF);
					
					break;
				
				case 2:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,130,4,"EXIT");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				defalut:
					break;
			}

			if(pad_read(PAD_SERVICE)==PAD_ON){
				if(cursor_pos_down_wait==0)
				{
					if(in_game_mode!=2){
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
							stop_bit_value++;
							if(stop_bit_value>0x1)
							{
								stop_bit_value=0;
							}
							break;
						case 1:
							if(stop_bit_value==1){
								nvram_set_stop_bit(0x80);
							}else{

								nvram_set_stop_bit(0x00);
							}
							break;
						case 2:
							game_mode=3;
							in_game_end=0;
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
void set_battery()
{

	int use_check_bit= nvram_get_use_battery_check();
	int cursor_pos_down_wait=0;
	int count_wait=0;
	int in_game_end=1;
	int test_off=0;
	int i=0;
	char hex_temp[2];
	int in_game_mode=0;
	button_clear();
	while(in_game_end) {
		if(display_is_old)	{
			DoubleBuffering();
			ClearScreen();
			button_update();
			
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(1,1);
			print_str(30,20,8,"SET BATTRY OPTION");
			print_str(30,40,18,"USE BATTERY CHECK=");
			print_int(120,40,use_check_bit);
			print_str(30,120,22,"SAVE USE BATTERY CHECK");
			print_str(30,130,4,"EXIT");
			switch(in_game_mode){
				case 0:
					print_set_font_color(0xFF,0x00,0x00);
					print_int(120,40,use_check_bit);
					print_set_font_color(0xFF,0xFF,0xFF);
					
					break;
				
				case 1:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,120,22,"SAVE USE BATTERY CHECK");
					print_set_font_color(0xFF,0xFF,0xFF);
					
					break;
				
				case 2:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,130,4,"EXIT");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				defalut:
					break;
			}

			if(pushed_button_hold[2][2]==PAD_ON){
				if(cursor_pos_down_wait==0)
				{
					if(in_game_mode!=2){
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
							use_check_bit++;
							if(use_check_bit>0x1)
							{
								use_check_bit=0;
							}
							break;
						case 1:
							if(use_check_bit==1){
								nvram_set_use_battery_check(0x80);
							}else{

								nvram_set_use_battery_check(0x00);
							}
							break;
						case 2:
							game_mode=3;
							in_game_end=0;
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

void util_nvram()
{
	int cursor_pos_down_wait=0;
	int title_end=1;
	int test_clear=0;
	char hex_temp[128];
	unsigned char hex_temp2[8];
	int i=0;
	int in_game_mode=0;
	button_clear();
	while(title_end) {
		if(display_is_old)	{
			DoubleBuffering();
			ClearScreen();
			button_update();
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(1,1);
			print_str(30,20,8,"RTC TIME");
			switch(in_game_mode){
				case 0:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,90,8,"Set Time");
					print_set_font_color(0xFF,0xFF,0xFF);
					print_str(30,100,13,"Set Start_bit");
					print_str(30,110,21,"Set Use_battery_check");
					print_str(30,130,4,"EXIT");
					break;
				case 1:
					print_set_font_color(0xFF,0xFF,0xFF);
					print_str(30,90,8,"Set Time");
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,100,13,"Set Start_bit");
					print_set_font_color(0xFF,0xFF,0xFF);
					print_str(30,110,21,"Set Use_battery_check");
					print_str(30,130,4,"EXIT");
					break;
				case 2:
					print_set_font_color(0xFF,0xFF,0xFF);
					print_str(30,90,8,"Set Time");
					print_str(30,100,13,"Set Start_bit");
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,110,21,"Set Use_battery_check");
					print_set_font_color(0xFF,0xFF,0xFF);
					print_str(30,130,4,"EXIT");
					break;
				case 3:
					print_set_font_color(0xFF,0xFF,0xFF);
					print_str(30,90,8,"Set Time");
					print_str(30,100,13,"Set Start_bit");
					print_str(30,110,21,"Set Use_battery_check");
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,130,4,"EXIT");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
				defalut:
					break;
			}

			if(pushed_button_hold[2][2]==PAD_ON){
				if(cursor_pos_down_wait==0)
				{
					if(in_game_mode!=3){
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
				test_clear=1;

			}
			if(pad_read(PAD_TEST)==PAD_ON&&test_clear==1){
				switch(in_game_mode){
					case 0:
						//set_time
						game_mode=4;
						title_end=0;
						break;
					case 1:
						//set_start
						game_mode=5;
						title_end=0;
						break;
					case 2:
						//set_buttery
						game_mode=6;
						title_end=0;
						break;
					case 3:
						game_mode=0;
						title_end=0;
						break;
				}
			}
			
 			sprintf( hex_temp, "%02x", nvram_get_year() );
			print_str(30,40,2,hex_temp);
			print_str(40,40,1,"/");
			sprintf( hex_temp, "%02x", nvram_get_month() );
			print_str(45,40,2,hex_temp);
			print_str(55,40,1,"/");
			sprintf( hex_temp, "%02x", nvram_get_date() );
			print_str(60,40,2,hex_temp);
			print_str(70,40,1,"-");
			print_str(75, 40,4,get_day_of_the_week_char());
 			sprintf( hex_temp, "%02x", nvram_get_hour() );
			print_str(160,40,2,hex_temp);
			print_str(170,40,1,":");
 			sprintf( hex_temp, "%02x", nvram_get_minites());
			print_str(175,40,2,hex_temp);
			print_str(185,40,1,"-");

 			sprintf( hex_temp, "%02x", nvram_get_seconds());
			print_str(190,40,2,hex_temp);

			print_str(40,50,9,"STOP_BIT=");
			print_int(90,50,nvram_get_stop_bit());
			print_str(40,60,15,"battery_is_row=");
			print_int(120,60, nvram_get_battery_is_row());
			print_str(40, 70,18,"use_battery_check=");
			print_int(135,70,nvram_get_use_battery_check());



			nvram_regs_read(hex_temp2);
 			sprintf( hex_temp, "%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X", hex_temp2[0], hex_temp2[1], hex_temp2[2], hex_temp2[3], hex_temp2[4], hex_temp2[5], hex_temp2[6], hex_temp2[7]);
			print_str(10,180,23,hex_temp);

			GsDrawList();
			
			while(GsIsDrawing());
			display_is_old=0;
		}
	}
}