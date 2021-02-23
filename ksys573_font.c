#include "ksys573_font.h"

#include "tim/font.h"
void print_int(int x,int y,int val){
	int digit = 0; 
	int i=0;
	int temp=0;
	int temp_val=val;
	int temp_digit=temp_val;
	if(temp_val==0){
		sprite_font[0x10].x=x;
		sprite_font[0x10].y=y;
		sprite_font[0x10].r=font_r;
		sprite_font[0x10].g=font_g;
		sprite_font[0x10].b=font_b;
		sprite_font[0x10].scalex=font_size;
		sprite_font[0x10].scaley=font_size;
		GsSortSprite(&sprite_font[0x10]);
	}
	while(temp_digit!=0){ 
		temp_digit=temp_digit/10; 
		 ++digit; 
	}
	for(i=0;0<temp_val;i++){
		temp = temp_val % 10;
 		temp_val = temp_val / 10;
		sprite_font[temp+0x10].r=font_r;
		sprite_font[temp+0x10].g=font_g;
		sprite_font[temp+0x10].b=font_b;
		sprite_font[temp+0x10].scalex=font_size;
		sprite_font[temp+0x10].scaley=font_size;
		sprite_font[temp+0x10].x=(font_x*(digit-i-1))+x;
		sprite_font[temp+0x10].y=y;
		GsSortSprite(&sprite_font[temp+0x10]);
	}

}
void print_set_font_color(int r,int g ,int b)
{
	font_r=r;
	font_g=g;
	font_b=b;
}

void print_set_font_status( int size,int interval){
	font_size=size;
	font_interval=interval;
}
void print_str(int x,int y,int length,char str[]){
	int i=0;
	int temp;
	for(i=0;i<length;i++){
		temp=str[i];
		sprite_font[temp-0x20].r=font_r;
		sprite_font[temp-0x20].g=font_g;
		sprite_font[temp-0x20].b=font_b;
		sprite_font[temp-0x20].scalex=font_size;
		sprite_font[temp-0x20].scaley=font_size;
		sprite_font[temp-0x20].x=x+(i*(font_x+font_interval));
		sprite_font[temp-0x20].y=y;
		GsSortSprite(&sprite_font[temp-0x20]);
	}
}
void load_font()
{
	int i=0;
	int j=0;
	GsImageFromTim(&game_image,font);
	GsUploadImage(&game_image);
	print_set_font_color(0x00,0x00,0x00);
	print_set_font_status(1,0);
	for(j=0;j<6 ;j++){
		for(i=0;i<16 ;i++){
			GsSpriteFromImage(&sprite_font[i+(16*j)], &game_image, 1);
			sprite_font[i+(16*j)].w = font_x ;
			sprite_font[i+(16*j)].h = font_y ;
			sprite_font[i+(16*j)].u = font_x*i;
			sprite_font[i+(16*j)].v = font_y*j;
		}	
	}
}