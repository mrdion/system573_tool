#ifndef _KSYS573_TIMER_H
#define _KSYS573_TIMER_H
// 33,868 Mhz = 44100 * 256 * 3 
/* Timer0. */
#define TIMER0_VAL		0x1f801100
#define TIMER0_MODE		0x1f801104
#define TIMER0_LAST_VAL		0x1f801108
/* Timer1. */
#define TIMER0_VAL		0x1f801110
#define TIMER0_MODE		0x1f801114
#define TIMER0_LAST_VAL		0x1f801118
/* Timer2. */
#define TIMER0_VAL		0x1f801120
#define TIMER0_MODE		0x1f801124
#define TIMER0_LAST_VAL		0x1f801128

/* Timer_mode. */
#define COUNTER_ENABLE		0x0001
#define LAST_VAL_ENABLE		0x0008
#define INTERRUPT_ENABLE	0x0010
//Only timer0 and timer1
//timer0
//Sync ?
//timer1
//Sync H_BLANK
#define COUNTER_MODE		0x0100

//Only timer2
//1/8
#define COUNTER_PLL		0x0200


#define IRQ_TIMER_REGISTER	0x1f801070
#define IRQ_TIMER_0_ENABLE	0xf0000010
#define IRQ_TIMER_1_ENABLE	0xf0000020
#define IRQ_TIMER_2_ENABLE	0xf0000040

#define IRQ_TIMER_MASK_REGISTER	0x1f801074

void set_timer(int id,int mode);
void start_timer(int id);
int get_timer_count(int id);
int get_timer_irq(int id);

#endif
