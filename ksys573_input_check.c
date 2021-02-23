#include "main.h"
void input_check_1()
{
	GsLine line;
	int mode_end=1;
	int end_flag=0;
	int push_start_on=0;
	int push_start_count=0;
	int *timer;
	int time0=0;
	int time60=0;
	int time120=0;
	int test_x=105;
	int status_interval=100;
	int test_y=50;
	int p1_x=30;
	int p1_y=100;
	int p2_x=180;
	int p2_y=100;
	while(mode_end) {
		if(display_is_old)
		{
			DoubleBuffering();
			ClearScreen();
			button_update();
			GsSortCls(0,0,0);
			
			
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(2,5);
			print_str(120,10,9,"I/O CHECK");
			print_set_font_status(1,1);
			print_str(135,30,11,"INPUT CHECK");
			print_str(p1_x,test_y+((font_y*font_size)*0),11,"TEST BUTTON");
			print_str(p1_x,test_y+((font_y*font_size)*1),14,"SERVICE BUTTON");
			print_str(p1_x,test_y+((font_y*font_size)*2),10,"COIN1 MECH");
			print_str(p1_x,test_y+((font_y*font_size)*3),10,"COIN2 MECH");
			print_str(p2_x,test_y+((font_y*font_size)*0),3,"DIP");
			print_str(p2_x,test_y+((font_y*font_size)*1),7,"PCCARD1");
			print_str(p2_x,test_y+((font_y*font_size)*2),7,"PCCARD2");
			print_str(p1_x,p1_y+((font_y*font_size)*0),8,"P1 START");
			print_str(p1_x,p1_y+((font_y*font_size)*1),5,"P1 UP");
			print_str(p1_x,p1_y+((font_y*font_size)*2),7,"P1 DOWN");
			print_str(p1_x,p1_y+((font_y*font_size)*3),7,"P1 LEFT");
			print_str(p1_x,p1_y+((font_y*font_size)*4),8,"P1 RIGHT");
			print_str(p1_x,p1_y+((font_y*font_size)*5),10,"P1 BUTTON1");
			print_str(p1_x,p1_y+((font_y*font_size)*6),10,"P1 BUTTON2");
			print_str(p1_x,p1_y+((font_y*font_size)*7),10,"P1 BUTTON3");
			print_str(p1_x,p1_y+((font_y*font_size)*8),10,"P1 BUTTON4");
			print_str(p1_x,p1_y+((font_y*font_size)*9),10,"P1 BUTTON5");
			print_str(p1_x,p1_y+((font_y*font_size)*10),10,"P1 BUTTON6");
			print_str(p2_x,p2_y+((font_y*font_size)*0),8,"P2 START");
			print_str(p2_x,p2_y+((font_y*font_size)*1),5,"P2 UP");
			print_str(p2_x,p2_y+((font_y*font_size)*2),7,"P2 DOWN");
			print_str(p2_x,p2_y+((font_y*font_size)*3),7,"P2 LEFT");
			print_str(p2_x,p2_y+((font_y*font_size)*4),8,"P2 RIGHT");
			print_str(p2_x,p2_y+((font_y*font_size)*5),10,"P2 BUTTON1");
			print_str(p2_x,p2_y+((font_y*font_size)*6),10,"P2 BUTTON2");
			print_str(p2_x,p2_y+((font_y*font_size)*7),10,"P2 BUTTON3");
			print_str(p2_x,p2_y+((font_y*font_size)*8),10,"P2 BUTTON4");
			print_str(p2_x,p2_y+((font_y*font_size)*9),10,"P2 BUTTON5");
			print_str(p2_x,p2_y+((font_y*font_size)*10),10,"P2 BUTTON6");
			print_str(85,220,32,"PRESS TEST + SERVICE = EXIT");
			if(pushed_button_hold[2][2]==PAD_ON&&pushed_button_hold[2][3]==PAD_ON)
			{
				end_flag=1;
				
			}
			if(pushed_button_hold[2][2]!=PAD_ON&&pushed_button_hold[2][3]!=PAD_ON&&end_flag==1)
			{
				end_flag=1;
				game_mode=0;
				mode_end=0;
				
			}
	/*pushed_button[2][4]=pad_read(PAD_DIP1);
	pushed_button[2][5]=pad_read(PAD_DIP2);
	pushed_button[2][6]=pad_read(PAD_DIP3);
	pushed_button[2][7]=pad_read(PAD_DIP4);
	pushed_button[2][8]=pad_read(PAD_PCCARD1);
	pushed_button[2][9]=pad_read(PAD_PCCARD2);*/
			if(pushed_button_hold[2][8]==PAD_ON)
			{
				
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,test_y+((font_y*font_size)*1),2,"OK");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,test_y+((font_y*font_size)*1),2,"--");
			}
			if(pushed_button_hold[2][9]==PAD_ON)
			{
				
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,test_y+((font_y*font_size)*2),2,"OK");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,test_y+((font_y*font_size)*2),2,"--");
			}
			if(pushed_button_hold[2][4]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,test_y+((font_y*font_size)*0),2,"1");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,test_y+((font_y*font_size)*0),3,"1");
			}
			if(pushed_button_hold[2][5]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval+5,test_y+((font_y*font_size)*0),2,"2");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval+5,test_y+((font_y*font_size)*0),3,"2");
			}
			if(pushed_button_hold[2][6]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval+10,test_y+((font_y*font_size)*0),2,"3");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval+10,test_y+((font_y*font_size)*0),3,"3");
			}
			if(pushed_button_hold[2][7]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval+15,test_y+((font_y*font_size)*0),2,"4");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval+15,test_y+((font_y*font_size)*0),3,"4");
			}
			if(pushed_button_hold[2][3]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*0),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*0),3,"OFF");
			}
			if(pushed_button_hold[2][2]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*1),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*1),3,"OFF");
			}
			if(pushed_button_hold[2][0]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*2),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*2),3,"OFF");
			}
			if(pushed_button_hold[2][1]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*3),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,test_y+((font_y*font_size)*3),3,"OFF");
			}
			
			if(pushed_button_hold[0][0]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*0),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*0),3,"OFF");
			}
			if(pushed_button_hold[0][1]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*1),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*1),3,"OFF");
			}
			if(pushed_button_hold[0][2]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*2),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*2),3,"OFF");
			}
			if(pushed_button_hold[0][3]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*3),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*3),3,"OFF");
			}
			if(pushed_button_hold[0][4]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*4),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*4),3,"OFF");
			}
			if(pushed_button_hold[0][5]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*5),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*5),3,"OFF");
			}
			if(pushed_button_hold[0][6]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*6),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*6),3,"OFF");
			}
			if(pushed_button_hold[0][7]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*7),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*7),3,"OFF");
			}
			if(pushed_button_hold[0][8]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*8),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*8),3,"OFF");
			}
			if(pushed_button_hold[0][9]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*9),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*9),3,"OFF");
			}
			if(pushed_button_hold[0][10]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*10),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p1_x+status_interval,p1_y+((font_y*font_size)*10),3,"OFF");
			}					
			
			if(pushed_button_hold[1][0]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*0),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*0),3,"OFF");
			}
			if(pushed_button_hold[1][1]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*1),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*1),3,"OFF");
			}
			if(pushed_button_hold[1][2]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*2),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*2),3,"OFF");
			}
			if(pushed_button_hold[1][3]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*3),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*3),3,"OFF");
			}
			if(pushed_button_hold[1][4]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*4),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*4),3,"OFF");
			}
			if(pushed_button_hold[1][5]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*5),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*5),3,"OFF");
			}
			if(pushed_button_hold[1][6]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*6),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*6),3,"OFF");
			}
			if(pushed_button_hold[1][7]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*7),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*7),3,"OFF");
			}
			if(pushed_button_hold[1][8]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*8),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*8),3,"OFF");
			}
			if(pushed_button_hold[1][9]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*9),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*9),3,"OFF");
			}
			if(pushed_button_hold[1][10]==PAD_ON)
			{
				print_set_font_color(0,0xFF,0);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*10),2,"ON");
			}else{
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(p2_x+status_interval,p2_y+((font_y*font_size)*10),3,"OFF");
			}					
			
			GsDrawList();
			while(GsIsDrawing());
			display_is_old=0;
		}
	}
}
void input_check_2()
{
	GsLine line;
	GsLine line1;
	GsLine line2;
	GsLine line3;
	int page=1;
	int timing_counter=0;
	int end_flag=0;
	int next_page_flag=0;
	int pre_page_flag=0;
	int mode_end=1;
	int push_start_on=0;
	int push_start_count=0;
	int count_start=0;
	int test_clear=0;
	int pushed_buttons[600][2][11];
	int j=0;
	int i=0;
	int k=0;
	button_clear();
	line.r=0xFF;
	line.g=0xFF;
	line.b=0xFF;
	line1.r=0xFF;
	line1.g=0xFF;
	line1.b=0xFF;
	line2.r=0xFF;
	line2.g=0xFF;
	line2.b=0xFF;
	line3.r=0xFF;
	line3.g=0xFF;
	line3.b=0xFF;
	line1.x[0]=40;
	line1.x[1]=40;
	line1.y[0]=50;
	line1.y[1]=55;
	line2.y[0]=50;
	line2.y[1]=55;
	line2.x[0]=160;
	line2.x[1]=160;
	line3.y[0]=50;
	line3.y[1]=55;
	line3.x[0]=279;
	line3.x[1]=279;
	line.y[0]=55;
	line.y[1]=70;
	for(k=0;k<600;k++){
		for(j=0;j<2;j++)
		{
			for(i=0;i<11;i++)
			{
				pushed_buttons[k][j][i]=0;
			}
		}
	}
	while(mode_end) {
		if(display_is_old)
		{
			DoubleBuffering();
			ClearScreen();
			button_clear();
			button_update();
			print_set_font_color(0xFF,0xFF,0xFF);
			print_set_font_status(2,5);
			print_str(120,10,9,"I/O CHECK");
			print_set_font_status(1,1);
			print_str(120,30,18,"INPUT TIMING CHECK");
			if(count_start==0)
			{
				if(pushed_button[2][3]!=PAD_ON){
					test_clear=1;
				}
				print_str(85,215,27,"PRESS TEST    = COUNT START");
				if(pushed_button[2][3]==PAD_ON&&test_clear==1){
					count_start=1;
					timing_counter=0;
				}
				frame_counter=0;
			}
			if(count_start==1)
			{
				print_str(85,215,25,"PRESS SERVICE = COUNT END");
			}
			if(count_start==2)
			{
				print_str(85,205,26,"PRESS SERVICE  = NEXT PAGE");
				print_str(85,215,26,"PRESS TEST = PREVIOUS PAGE");
				if(pushed_button_hold[2][3]==PAD_ON)
				{
					next_page_flag=1;
					pre_page_flag=0;
				
				}
				if(pushed_button_hold[2][3]!=PAD_ON&&next_page_flag==1)
				{
					next_page_flag=0;
					page=page+1;
					if(page>40)
					{
						page=40;
					}
				
				}
				if(pushed_button_hold[2][2]==PAD_ON)
				{
					pre_page_flag=1;
					next_page_flag=0;
				
				}
				if(pushed_button_hold[2][2]!=PAD_ON&&pre_page_flag==1)
				{
					pre_page_flag=0;
					page=page-1;
					if(page<1)
					{
						page=1;
					}
				
				}
			}
			print_str(85,225,27,"PRESS SERVICE + TEST = EXIT");
			if(pushed_button_hold[2][2]==PAD_ON&&pushed_button_hold[2][3]==PAD_ON)
			{
				end_flag=1;
				
			}
			if(pushed_button_hold[2][2]!=PAD_ON&&pushed_button_hold[2][3]!=PAD_ON&&end_flag==1)
			{
				game_mode=0;
				mode_end=0;
				
			}
			
			line.x[0]=(frame_counter*2)+40;
			line.x[1]=(frame_counter*2)+40;
			if(count_start==1)
			{
			
				for(j=0;j<2;j++)
				{
					for(i=0;i<11;i++)
					{
						if(pushed_button[j][i]==PAD_ON)
						{
							pushed_buttons[timing_counter][j][i]=1;
							print_str(160,120,6,"PUSHED");
						}
						else
						{
							pushed_buttons[timing_counter][j][i]=0;
						}
					}
				}
				print_str(80,120,6,"last ");
				print_int(130,120,600-timing_counter);
				timing_counter++;
				if(pushed_button_hold[2][2]==PAD_ON||timing_counter==600)
				{
					count_start=2;
				}
			
			}

			if(count_start==2){
				
				print_set_font_color(0xFF,0xFF,0xFF);
				print_str(20,30,6,"PAGE:");
				print_int(50,30,page);
				for(k=0;k<15;k++)
				{	
					print_set_font_color(0xFF,0xFF,0xFF);
					print_int((k*20)+10,40,(page-1)*15+k);
					for(j=0;j<2;j++)
					{
						if(j==0){
							
							print_set_font_color(255,50,50);
						}else{
							print_set_font_color(50,50,255);
						}
						for(i=0;i<11;i++)
						{
							if(pushed_buttons[(page-1)*15+k][j][i]==1)
							{
								switch(i)
								{
								case 0:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"S");
									break;
								case 1:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"U");
									break;
								case 2:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"D");
									break;
								case 3:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"L");
									break;
								case 4:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"R");
									break;
								case 5:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"1");
									break;
								case 6:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"2");
									break;
								case 7:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"3");
									break;
								case 8:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"4");
									break;
								case 9:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"5");
									break;
								case 10:
									print_str((k*20)+10,(i*7)+51+(j*70),1,"6");
									break;
								}
							}
						}
					}
				}
			}else{
				
				GsSortLine(&line);
				GsSortLine(&line1);
				GsSortLine(&line2);
				GsSortLine(&line3);
			}
			GsDrawList();
			while(GsIsDrawing());
			display_is_old=0;
			
		}
		
	}
}
