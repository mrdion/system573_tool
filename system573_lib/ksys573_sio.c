#include <psx.h>
#include "ksys573_sio.h"
#include <stdio.h>
#include "ksys573_psx_gpu.h"

void SIOStop()
{
	SIO_MODE = 0;
	SIO_CTRL = 0;
	SIO_BPSV = 0;
}

unsigned char SIOReadByte()
{
	return (unsigned char)SIO_TX_RX;
}

void SIOSendByte(unsigned char data)
{
	SIO_TX_RX = data;
}
int SIOSendByte_wait_txen(unsigned char data,int timeout)
{
	int ret =0;
	//ksys573_psx_gpuにも定義してるが初期化してるとは限らないため。
	int * wachdog_=(int*)0x1f5c0000;
	if(timeout<100)
	{
		timeout=100;
	}
	while(SIOCheckOutBuffer()!=1){
		ret++;
		if(ret==timeout)
		{
			break;
		}
		*wachdog_=0x0;
	}
	if(ret!=timeout)
	{
		SIO_TX_RX = data;
	}else
	{
		ret=-1;
	}
	return ret;
}

int SIOCheckInBuffer()
{
	return (SIO_STAT & 0x2)>0;
}

int SIOCheckOutBuffer()
{
	return (SIO_STAT & 0x4)>0;
}
	
void SIOStart_Ksys573()
{
	SIO_MODE = 0x004e;
	SIO_CTRL = 0x0c37;
	SIO_BPSV = 0x0012;
}
unsigned short SIOSTATUS()
{
	unsigned short temp=SIO_STAT;
	return temp;
}