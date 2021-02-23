#ifndef _KSYS573_PAD_H
#define _KSYS573_PAD_H

#define button_num 11
#define player_num 3
/* jamma_pad. */
#define IN1 		0x1f400004
#define IN2 		0x1f400008
#define IN3		0x1f40000C
/* IN1 */
#define PAD_ON 		0x0
#define PAD_OFF		0x1
#define PAD_DIP1	0x00010001
#define PAD_DIP2	0x00010002
#define PAD_DIP3	0x00010004
#define PAD_DIP4	0x00010008
#define PAD_COIN1	0x01010000
#define PAD_COIN2	0x02010000
#define PAD_PCCARD1	0x04010000
#define PAD_PCCARD2	0x08010000
#define PAD_SERVICE	0x10010000
/* IN2 */
#define PAD_1P_LEFT	0x00020100
#define PAD_1P_RIGHT	0x00020200
#define PAD_1P_UP	0x00020400
#define PAD_1P_DOWN	0x00020800
#define PAD_1P_BUTTON1	0x00021000
#define PAD_1P_BUTTON2	0x00022000
#define PAD_1P_BUTTON3	0x00024000
#define PAD_1P_START	0x00028000

#define PAD_2P_LEFT	0x00020001
#define PAD_2P_RIGHT	0x00020002
#define PAD_2P_UP	0x00020004
#define PAD_2P_DOWN	0x00020008
#define PAD_2P_BUTTON1	0x00020010
#define PAD_2P_BUTTON2	0x00020020
#define PAD_2P_BUTTON3	0x00020040
#define PAD_2P_START	0x00020080

/* IN3 */
#define PAD_1P_BUTTON4	0x00040100
#define PAD_1P_BUTTON5	0x00040200
#define PAD_TEST	0x00040400
#define PAD_1P_BUTTON6	0x00040800

#define PAD_2P_BUTTON4	0x01040000
#define PAD_2P_BUTTON5	0x02040000
#define PAD_2P_BUTTON6	0x08040000

unsigned int pushed_button[player_num][button_num];
unsigned int pushed_button_old[player_num][button_num];
unsigned int pushed_button_hold[player_num][button_num];
void button_clear();
void button_update();
int pad_read(int pad_bit);
int pad_read_raw_in1();
int pad_read_raw_in2();
int pad_read_raw_in3();

#endif
