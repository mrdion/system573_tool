/*
 * SIO communication library for PSXSDK.
 * Originally written by Shendo.
 * Thanks to Martin Korth of the NO$PSX for documentation.
 * 
 * This library is accessing SIO registers directly, no BIOS routines are used.
 */

#include <psx.h>
#include "ksys573_sio.h"
#include <stdio.h>
#include "ksys573_psx_gpu.h"

void SIOStart(int bitrate)
{
	/*Set to 8N1 mode with desired bitrate*/
	SIOStartEx(bitrate, SIO_DATA_LEN_8, SIO_PARITY_NONE, SIO_STOP_BIT_1);
}

void SIOStartEx(int bitrate, int datalength, int parity, int stopbit)
{
	/*Set SIO_MODE register, bitrate reload factor set to MUL16 by default*/
	SIO_MODE = SIO_REL_MUL16 | (datalength << 2) | (parity << 4) | (stopbit << 6);

	/*Reset SIO_CTRL register.*/
	SIO_CTRL = 0;

	/*Set TX and RT to enabled, no handshaking signals.*/
	SIO_CTRL = 1 | (1 << 2);

	/*Calculate bitrate reload value based on the given bitrate
	 * Reload = SystemClock (33 Mhz) / (Factor (MULI16) * bitrate)*/
	SIO_BPSV = 0x204CC00 / (16 * bitrate);
}

void SIOStop()
{
	/*Set all SIO related registers to zero*/
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
	/*Return status of RX FIFO*/
	return (SIO_STAT & 0x2)>0;
}

int SIOCheckOutBuffer()
{
	/*Return status of TX Ready flag*/
	return (SIO_STAT & 0x4)>0;
}
	
void SIOStart_Ksys573()
{
	/*Set all SIO related registers to zero*/
	SIO_MODE = 0x004e;
	SIO_CTRL = 0x0c37;
	SIO_BPSV = 0x0012;
}
unsigned short SIOSTATUS()
{
	unsigned short temp=SIO_STAT;
	return temp;
}