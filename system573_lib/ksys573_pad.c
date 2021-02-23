#include "ksys573_pad.h"
#include <psx.h>

void button_clear(){
	int i=0;
	int j=0;
	for(i=0;i<player_num;i++)
	{
		for(j=0;j<button_num;j++)
		{
			pushed_button[i][j]=0x00;
			pushed_button_old[i][j]=0x00;
			pushed_button_hold[i][j]=0x00;
		}
	}
}
void button_update(){
	int i=0;
	int j=0;
	
	pushed_button[0][0]=pad_read(PAD_1P_START);
	pushed_button[0][1]=pad_read(PAD_1P_UP);
	pushed_button[0][2]=pad_read(PAD_1P_DOWN);
	pushed_button[0][3]=pad_read(PAD_1P_LEFT);
	pushed_button[0][4]=pad_read(PAD_1P_RIGHT);
	pushed_button[0][5]=pad_read(PAD_1P_BUTTON1);
	pushed_button[0][6]=pad_read(PAD_1P_BUTTON2);
	pushed_button[0][7]=pad_read(PAD_1P_BUTTON3);
	pushed_button[0][8]=pad_read(PAD_1P_BUTTON4);
	pushed_button[0][9]=pad_read(PAD_1P_BUTTON5);
	pushed_button[0][10]=pad_read(PAD_1P_BUTTON6);
	
	pushed_button[1][0]=pad_read(PAD_2P_START);
	pushed_button[1][1]=pad_read(PAD_2P_UP);
	pushed_button[1][2]=pad_read(PAD_2P_DOWN);
	pushed_button[1][3]=pad_read(PAD_2P_LEFT);
	pushed_button[1][4]=pad_read(PAD_2P_RIGHT);
	pushed_button[1][5]=pad_read(PAD_2P_BUTTON1);
	pushed_button[1][6]=pad_read(PAD_2P_BUTTON2);
	pushed_button[1][7]=pad_read(PAD_2P_BUTTON3);
	pushed_button[1][8]=pad_read(PAD_2P_BUTTON4);
	pushed_button[1][9]=pad_read(PAD_2P_BUTTON5);
	pushed_button[1][10]=pad_read(PAD_2P_BUTTON6);

	
	pushed_button[2][0]=pad_read(PAD_COIN1);
	pushed_button[2][1]=pad_read(PAD_COIN2);
	pushed_button[2][2]=pad_read(PAD_SERVICE);
	pushed_button[2][3]=pad_read(PAD_TEST);
	pushed_button[2][4]=pad_read(PAD_DIP1);
	pushed_button[2][5]=pad_read(PAD_DIP2);
	pushed_button[2][6]=pad_read(PAD_DIP3);
	pushed_button[2][7]=pad_read(PAD_DIP4);
	pushed_button[2][8]=pad_read(PAD_PCCARD1);
	pushed_button[2][9]=pad_read(PAD_PCCARD2);
	pushed_button[2][10]=PAD_OFF;

	for(i=0;i<player_num;i++)
	{
		for(j=0;j<button_num;j++)
		{
			pushed_button_hold[i][j]=PAD_OFF;
			if(pushed_button_old[i][j]==PAD_ON&&pushed_button[i][j]==PAD_ON){
				pushed_button_hold[i][j]=PAD_ON;
			}	
		}
	}
	memcpy(pushed_button_old,pushed_button,button_num*player_num);
}
int pad_read(int pad_bit)
{
	int *pad_state;
	int ret=PAD_OFF;
	switch(pad_bit&0x000F0000)
	{

		case 0x00010000:
			
			//GsPrintFont(0, 30, "pad_bit:IN1");
			pad_state=(int*)IN1;
			break;
		case 0x00020000:
			//GsPrintFont(0, 30, "pad_bit:IN2");
			pad_state=(int*)IN2;
			break;
		case 0x00040000:
			//GsPrintFont(0, 30, "pad_bit:IN3");
			pad_state=(int*)IN3;
			break;
		default:
			ret=-1;
			break;
	}
	if(ret==PAD_OFF)
	{
		
		//GsPrintFont(0, 40, "pad_bit:%x",*pad_state);
		ret=(*pad_state&(pad_bit&0xFFF0FFFF));
		
	}
	return ret;
}
int pad_read_raw_in1()
{
	int *pad_state;
	pad_state=(int*)IN1;
	return *pad_state;
}
int pad_read_raw_in2()
{
	int *pad_state;
	pad_state=(int*)IN2;
	return *pad_state;
}
int pad_read_raw_in3()
{
	int *pad_state;
	pad_state=(int*)IN3;
	return *pad_state;
}
