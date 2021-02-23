#ifndef _KSYS573_NVRAM_H
#define _KSYS573_NVRAM_H
/*
m48t58
0x00->0x2000
*/
/* nvram_address. */
#define NVRAM 		0x1f620000
#define NVRAM_MAX       0x2000
unsigned char nvram_read_byte(unsigned int address);
void nvram_write_byte(unsigned int address,unsigned char data);
int nvram_read();
int nvram_write();
int nvram_regs_read(unsigned char* buf);
int nvram_regs_write(unsigned char* buf);
int nvram_set_year(unsigned char);
int nvram_get_year();
int nvram_set_month(unsigned char);
int nvram_get_month();
int nvram_set_date(unsigned char);
int nvram_get_date();
int nvram_get_battery_is_row();
int nvram_set_use_battery_check(unsigned char);
int nvram_get_use_battery_check();
int nvram_set_day_of_the_week(unsigned char);
int nvram_get_day_of_the_week();
int nvram_set_hour(unsigned char);
int nvram_get_hour();
int nvram_set_minites(unsigned char);
int nvram_get_minites();
int nvram_set_seconds(unsigned char);
int nvram_get_seconds();
int nvram_set_stop_bit(unsigned char);
int nvram_get_stop_bit();
int nvram_read_bit_is_on();
int nvram_read_bit_is_off();
int nvram_write_bit_is_on();
int nvram_write_bit_is_off();
char* get_day_of_the_week_char();
char* get_day_of_the_week_from_int();
#endif
