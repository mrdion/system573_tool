#ifndef _KSYS573_DUMP_H
#define _KSYS573_DUMP_H
void sio_check();
unsigned short crc16(int deviceid,int bank);
unsigned long crc32(int deviceid,int bank);
void read_serial_ram(int deviceid,int bank);
void send_serial_ram(int deviceid,int bank);
#endif