#include "main.h"
void sio_check()
{

	int cursor_pos_down_wait=0;
	int count_wait=0;
	int in_game_end=1;
	int test_off=0;
	int i=0;
	int in_game_mode=0;
	int is_init=0;
	unsigned char temp_data=0;
	int in_byte=0;
	int out_byte=0;
	button_clear();
	unsigned short status=0;
	char hex_temp[255];
	//init
	int ret=0;
	while(in_game_end) {
		if(display_is_old)	{
			DoubleBuffering();
			ClearScreen();
			button_update();
			
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(1,1);
			print_str(30,20,9,"SIO CHECK");
			print_str(30,40,13,"115200bps 8N1");
			print_str(30,130,4,"EXIT");
			switch(in_game_mode){
				case 0:
					print_set_font_color(0xFF,0x00,0x00);
					print_str(30,130,4,"EXIT");
					print_set_font_color(0xFF,0xFF,0xFF);
					break;
			}

			if(pushed_button_hold[2][2]==PAD_ON){
				if(cursor_pos_down_wait==0)
				{
					if(in_game_mode!=0){
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
							game_mode=0;
							in_game_end=0;
							SIOStop();
							break;
						defalut:
						break;
					}
				}
				
				count_wait++;
			}else{
				count_wait=0;
			}
			

			//main util
			if(is_init==0)
			{
				
				//SIOStart(115200);
				SIOStart_Ksys573();
				is_init=1;
				for(i=0;i<26;i++){
					ret=SIOSendByte_wait_txen((unsigned char)('A'+i),0xFFF);
				}
				SIOSendByte((unsigned char)'\n');
			}
			status=SIOSTATUS();
			sprintf(hex_temp, "STATUS_%04x",status);
			print_str(30,70,11,hex_temp);

			out_byte=SIOCheckOutBuffer();
			sprintf(hex_temp, "OUTBUF_%02x",out_byte);
			print_str(30,80,9,hex_temp);

			in_byte=SIOCheckInBuffer();
			sprintf(hex_temp, "INBUF__%02x",in_byte);
			print_str(30,90,9,hex_temp);

			sprintf(hex_temp, "RET____%02x",ret);
			print_str(30,100,9,hex_temp);
			//SIOSendByte(0x41);
			if(in_byte!=0)
			{
				temp_data=SIOReadByte();
				SIOSendByte_wait_txen(temp_data,0xFF);
			}
			
			sprintf(hex_temp, "INDATA_%02x",temp_data);
			print_str(30,110,9,hex_temp);
			GsDrawList();
			while(GsIsDrawing());
			display_is_old=0;
		}
	}
}
