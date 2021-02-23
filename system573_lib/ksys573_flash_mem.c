#include "ksys573_FLASH_MEM.h"
#include <psx.h>
#include <string.h>
unsigned char flash_mem_read_data(int deviceid,int address,int bank)
{
	unsigned char ret_data[1];
	char command[1];
	char* control;
	char* flash_bank;
	ret_data[0]=0x00;
	control=(char*)FLASH_MEM_SELECT_DEVICE;
	flash_bank=(char*)FLASH_MEM_BASE;
	control[0]=deviceid+bank;
	memcpy(ret_data,flash_bank+address,sizeof(char)*1);
	return ret_data[0];
}
void wait(long count)
{
	long i=0;
	int stop=0;
	while(stop==0)
	{
		i++;
		if(i>count)
		{
			stop=1;
		}	
	}
}
void flash_mem_reset(int deviceid,int bank)
{
	char* control;
	char* flash_bank;
	short* raw_mem;
	control=(char*)FLASH_MEM_SELECT_DEVICE;
	flash_bank=(char*)FLASH_MEM_BASE;
	control[0]=deviceid+bank;

	raw_mem=(short*)flash_bank;
	switch(deviceid)
	{
		case ONBOARD:
		case PCCARD1:
		case PCCARD2:
			//fujitsu
			raw_mem[0]=0xF0F0;
			//intel
			while(GsIsDrawing());
			raw_mem[0]=0xFFFF;
		break;
	}
}
void flash_mem_erase(int deviceid,int sector,int bank)
{
	unsigned char ref_data1=0x00;
	unsigned char ref_data2=0x00;
	int is_clear=0x00;
	char* control;
	char* flash_bank;
	short* raw_mem;
	short* raw_mem_AAA;
	short* raw_mem_554;
	short* raw_mem_sector;
	unsigned int address_sector=0x00;

	control=(char*)FLASH_MEM_SELECT_DEVICE;
	flash_bank=(char*)FLASH_MEM_BASE;
	control[0]=deviceid+bank;
	raw_mem=(short*)(flash_bank);

	switch(deviceid)
	{
		case ONBOARD:
		case PCCARD1:
		case PCCARD2:
			flash_mem_autoselect(deviceid,bank);
			if(flash_mem_read_data(deviceid,0,bank)==0x04)
			{
				//fujitsu
				flash_mem_reset(deviceid,bank);		
				address_sector=sector<<17;
				raw_mem_AAA=(short*)(0xAAA+flash_bank);
				raw_mem_554=(short*)(0x554+flash_bank);
				raw_mem_sector=(short*)(flash_bank+address_sector);
				raw_mem_AAA[0]=0xAAAA;
				raw_mem_554[0]=0x5555;
				while(GsIsDrawing());
				raw_mem_AAA[0]=0x8080;
				while(GsIsDrawing());
				raw_mem_AAA[0]=0xAAAA;
				while(GsIsDrawing());
				raw_mem_554[0]=0x5555;
				raw_mem_sector[0]=0x3030;
				while(GsIsDrawing());
				while(is_clear==0)
				{
					ref_data1=flash_mem_read_data(deviceid,(sector*0x20000),bank);
					ref_data2=flash_mem_read_data(deviceid,(sector*0x20000)+1,bank);
					while(GsIsDrawing());
					if(ref_data1==0xFF&&ref_data2==0xFF)
					{
						is_clear=1;
					}
				}
			}
			if(flash_mem_read_data(deviceid,0,bank)==0x89)
			{
				//intel
				flash_mem_reset(deviceid,bank);		
				raw_mem[sector*0x10000]=0xFFFF;
				while(GsIsDrawing());
				raw_mem[sector*0x10000]=0x2020;
				while(GsIsDrawing());
				raw_mem[sector*0x10000]=0xD0D0;
				while(GsIsDrawing());
				while(is_clear==0)
				{
					
					ref_data1=flash_mem_read_data(deviceid,(sector*0x10000),bank);
					ref_data2=flash_mem_read_data(deviceid,(sector*0x10000)+1,bank);
					while(GsIsDrawing());
					if(ref_data1==0x80&&ref_data2==0x80)
					{
						is_clear=1;
					}
				}
			}
			break;
	}
	flash_mem_reset(deviceid,bank);		
}
void flash_mem_autoselect(int deviceid,int bank)
{
	char* control;
	char* flash_bank;
	short* raw_mem_AAA;
	short* raw_mem_554;

	control=(char*)FLASH_MEM_SELECT_DEVICE;
	flash_bank=(char*)FLASH_MEM_BASE;
	control[0]=deviceid+bank;

	raw_mem_AAA=(short*)(0xAAA+flash_bank);
	raw_mem_554=(short*)(0x554+flash_bank);

	switch(deviceid)
	{
		case ONBOARD:
		case PCCARD1:
		case PCCARD2:
			raw_mem_AAA[0]=0xAAAA;
			raw_mem_554[0]=0x5555;
			while(GsIsDrawing());
			raw_mem_AAA[0]=0x9090;
			while(GsIsDrawing());
			break;	
	}
	
}
void flash_mem_write_data(int deviceid,int address,int bank,unsigned char data1,unsigned char data2)
{
	char* control;
	char* flash_bank;
	short write_data;
	short* raw_mem;
	short* raw_mem_AAA;
	short* raw_mem_554;
	write_data=(data2<<8)+data1;
	control=(char*)FLASH_MEM_SELECT_DEVICE;
	flash_bank=(char*)FLASH_MEM_BASE;
	control[0]=deviceid+bank;

	raw_mem=(short*)(flash_bank);
	switch(deviceid)
	{
		case ONBOARD:
		case PCCARD1:
		case PCCARD2:
			flash_mem_autoselect(deviceid,bank);
			if(flash_mem_read_data(deviceid,0,bank)==0x04)
			{
				//fujitsu
				
				flash_mem_reset(deviceid,bank);		
				raw_mem_AAA=(short*)(0xAAA+flash_bank);
				raw_mem_554=(short*)(0x554+flash_bank);
				raw_mem_AAA[0]=0xAAAA;
				raw_mem_554[0]=0x5555;
				while(GsIsDrawing());
				raw_mem_AAA[0]=0xA0A0;
				raw_mem[address/2]=write_data;
				while(GsIsDrawing());
				while(GsIsDrawing());
			}
			if(flash_mem_read_data(deviceid,0,bank)==0x89)
			{
				//intel
				flash_mem_reset(deviceid,bank);	
				raw_mem[address/2]=0xFFFF;
				while(GsIsDrawing());
				raw_mem[address/2]=0x5050;
				while(GsIsDrawing());
				raw_mem[address/2]=0x4040;
				while(GsIsDrawing());
				raw_mem[address/2]=write_data;
				while(GsIsDrawing());
				while(GsIsDrawing());
			}
			break;	
	}
	flash_mem_reset(deviceid,bank);	
}