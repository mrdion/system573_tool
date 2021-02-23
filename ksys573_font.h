#ifndef _KSYS573_FONT_H
#define _KSYS573_FONT_H
#include "main.h"
#define font_x 4
#define font_y 8
#define font_max 96

GsSprite sprite_font[font_max];
int font_size;
int font_interval;
int font_r;
int font_g;
int font_b;
void print_int(int x,int y,int val);
void print_set_font_color(int r,int g ,int b);
void print_set_font_status( int size,int interval);
void print_str(int x,int y,int length,char str[]);
void load_font();
#endif