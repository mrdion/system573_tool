#include "ksys573_nvram.h"
#include <psx.h>
unsigned char nvram_read_byte(unsigned int address)
{
	unsigned char temp[1];
	temp[0]=0x00;
	if(address<=NVRAM_MAX){
		memcpy(temp,NVRAM+(address*2),1);
	}
	return temp[0];
}
void nvram_write_byte(unsigned int address,unsigned char data)
{
	unsigned char temp[1];
	temp[0]=data;
	if(address<=NVRAM_MAX){
		memcpy(NVRAM+(address*2),temp,1);
	}
}
int nvram_read(unsigned char *buf,int offset,int length)
{
	int i=0;
	int index=0;
	if(offset+length<=NVRAM_MAX){
		for(i=0;i<length;i++){
			memcpy(buf+i,(NVRAM+(offset*2))+index,1);
			index=index+2;
		}
		return 0;	
	}else{
		return 1;
	}
}
int nvram_write(unsigned char *buf,int offset,int length)
{
	int i=0;
	int index=0;
	if(offset+length<=NVRAM_MAX){
		for(i=0;i<length;i++){
			memcpy((NVRAM+(offset*2))+index,buf+i,1);
			index=index+2;
		}
		return 0;	
	}else{
		return 1;
	}
}
int nvram_regs_read(unsigned char* buf)
{
	int i=0;
	int index=0;
	int offset = 0x1FF8;
	char* nvram_raw;
	//nvram_read_bit_is_on();
	for(i=0;i<8;i++){
		memcpy(buf+i,(NVRAM+(offset*2))+index,1);
		index=index+2;
	}
	//nvram_read_bit_is_off();
	return 0;
}
int nvram_regs_write(unsigned char* buf)
{
	int i=0;
	int index=0;
	int offset = 0x1FF8;
	unsigned char temp;
	temp = buf[6]&0x1F;
	buf[6]=temp;
	temp=buf[4]&0x77;
	buf[4]=temp;
	temp=buf[3]&0x3f;
	buf[3]=temp;
	temp=buf[2]&0x7f;
	buf[2]=temp;
	nvram_write_bit_is_on();
	for(i=0;i<8;i++){
		
		memcpy((NVRAM+(offset*2))+index,buf+i,1);
		index=index+2;
	}
	nvram_write_bit_is_off();
	return 0;
}
int nvram_set_year(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	buf[7]=ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_year(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret= buf[7];
	free(buf);
	return ret;
}
int nvram_set_month(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	buf[6]=ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_month(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret= buf[6];
	free(buf);
	return ret;
}
int nvram_set_date(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	unsigned char tmp;
	tmp=buf[5]&0xC0;
	buf[5]=tmp|ch;
	free(buf);
	return 0;
}
int nvram_get_date(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret= buf[5]&0x3f;
	free(buf);
	return ret;
}
int nvram_get_battery_is_row(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret=buf[5]&0x40;
	free(buf);
	return ret;
}
int nvram_set_use_battery_check(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	unsigned char tmp;
	tmp=buf[5]&0x7F;
	buf[5]=tmp|ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_use_battery_check(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret=buf[5]&0x80;
	free(buf);
	return ret;
}
int nvram_set_day_of_the_week(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	unsigned char tmp;
	tmp=buf[4]&0xF8;
	buf[4]=tmp|ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_day_of_the_week(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret=buf[4]&0x07;
	free(buf);
	return ret;
}
int nvram_set_hour(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	buf[3]=ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_hour(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret=buf[3];
	free(buf);
	return ret;
}
int nvram_set_minites(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	buf[2]=ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_minites(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret=buf[2];
	free(buf);
	return ret;
}
int nvram_set_seconds(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	unsigned char tmp;
	tmp=buf[1]&0x80;
	buf[1]=tmp|ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_seconds(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret=buf[1]&0x7f;
	free(buf);
	return ret;
}
int nvram_set_stop_bit(unsigned char ch){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	unsigned char tmp;
	tmp=buf[1]&0x7f;
	buf[1]=tmp|ch;
	nvram_regs_write(buf);
	free(buf);
	return 0;
}
int nvram_get_stop_bit(){
	unsigned char* buf;
	buf=(unsigned char*)malloc(8);
	nvram_regs_read(buf);
	int ret=buf[1]&0x80;
	free(buf);
	return ret;
}
int nvram_read_bit_is_on()
{
	int offset = 0x1FF8;
	unsigned char buf[1];
	unsigned char temp;
	memcpy(buf,(NVRAM+(offset*2)),1);
	temp=buf[0]&0xBF;
	buf[0]=temp|0x40;
	memcpy(NVRAM+(offset*2),0x40,1);
	return 0;
}
int nvram_read_bit_is_off()
{
	int offset = 0x1FF8;
	unsigned char buf[1];
	unsigned char temp;
	memcpy(buf,(NVRAM+(offset*2)),1);
	temp=buf[0]&0xBF;
	buf[0]=temp|0x00;
	memcpy(NVRAM+(offset*2),0x40,1);
	return 0;
}
int nvram_write_bit_is_on()
{
	int offset = 0x1FF8;
	unsigned char buf[1];
	unsigned char temp;
	memcpy(buf,(NVRAM+(offset*2)),1);
	temp=buf[0]&0x7f;
	buf[0]=temp|0x80;
	memcpy(NVRAM+(offset*2),0x40,1);
	return 0;
}
int nvram_write_bit_is_off()
{
	int offset = 0x1FF8;
	unsigned char buf[1];
	unsigned char temp;
	memcpy(buf,(NVRAM+(offset*2)),1);
	temp=buf[0]&0x7f;
	buf[0]=temp|0x00;
	memcpy(NVRAM+(offset*2),0x40,1);
	return 0;
}
char* get_day_of_the_week_char(){
	switch(nvram_get_day_of_the_week())
	{
		case 1:
			return "Sun.";
			break;
		case 2:
			return "Mon.";
			break;
		case 3:
			return "Tue.";
			break;
		case 4:
			return "Wed.";
			break;
		case 5:
			return "Thu.";
			break;
		case 6:
			return "Fri.";
			break;
		case 7:
			return "Sat.";
			break;
		default:
			return "NULL";
			break;

	}
}
char* get_day_of_the_week_from_int(int in){
	switch(in)
	{
		case 1:
			return "Sun.";
			break;
		case 2:
			return "Mon.";
			break;
		case 3:
			return "Tue.";
			break;
		case 4:
			return "Wed.";
			break;
		case 5:
			return "Thu.";
			break;
		case 6:
			return "Fri";
			break;
		case 7:
			return "Sat.";
			break;
		default:
			return "NULL";
			break;

	}
}