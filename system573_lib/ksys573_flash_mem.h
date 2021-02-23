#ifndef _KSYS573_FLASH_MEM_H
#define _KSYS573_FLASH_MEM_H

#define FLASH_MEM_BASE		0x1f000000
#define FLASH_MEM_SELECT_DEVICE	0x1f500000
#define ONBOARD			0x40
#define PCCARD1			0x10
#define PCCARD2			0x60


unsigned char flash_mem_read_data(int deviceid,int address,int bank);
void flash_mem_write_data(int deviceid,int address,int bank,unsigned char data1,unsigned char data2);
void flash_mem_reset(int deviceid,int bank);
void flash_mem_autoselect(int deviceid,int bank);
void flash_mem_erase(int deviceid,int sector,int bank);
#endif
