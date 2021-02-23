#ifndef _KSYS573_SIO_H
#define _KSYS573_SIO_H

/** Bitrate reload factors */

enum sio_reload_factors
{
	/** STOP */
	SIO_REL_STOP = 0,
	/** MUL1 */
	SIO_REL_MUL1 = 1,
	/** MUL16 */
	SIO_REL_MUL16 = 2,
	/** MUL64 */
	SIO_REL_MUL64 = 3
};
	
/** Character (data) length settings */

enum sio_data_len
{
	/** Data Length = 5 bits */
	SIO_DATA_LEN_5 = 0,
	/** Data Length = 6 bits */
	SIO_DATA_LEN_6 = 1,
	/** Data Length = 7 bits */
	SIO_DATA_LEN_7 = 2,
	/** Data Length = 8 bits */
	SIO_DATA_LEN_8 = 3
};

/** Stop bit length settings */

enum sio_stop_bit
{
	/** Length = 1 bit */
	SIO_STOP_BIT_1 = 1,
	/** Length = 1.5 bits */
	SIO_STOP_BIT_1_5 = 2,
	/** Length = 2 bits */
	SIO_STOP_BIT_2 = 3
};
	
/** Parity settings */

enum sio_parity
{
	/** No parity */
	SIO_PARITY_NONE = 0,
	/** Odd parity */
	SIO_PARITY_ODD = 1,
	/** Even parity */
	SIO_PARITY_EVEN = 3
};

/** SIO FIFO Buffer (TX/RX) Register [Read/Write] */
#define SIO_TX_RX		*((volatile unsigned char*)0x1F801050)
/** SIO Status Register [Read Only] */
#define SIO_STAT		*((volatile unsigned short*)0x1F801054)
/** SIO Mode Register [Read/Write] */
#define SIO_MODE		*((volatile unsigned short*)0x1F801058)
/** SIO Control Register [Read/Write] */
#define SIO_CTRL		*((volatile unsigned short*)0x1F80105A)
/** SIO Baud Rate Register [Read/Write] */
#define SIO_BPSV		*((volatile unsigned short*)0x1F80105E)


void SIOStop(void);


unsigned char SIOReadByte(void);
void SIOSendByte(unsigned char data);
int SIOCheckInBuffer(void);
int SIOCheckOutBuffer(void);
unsigned short SIOSTATUS(void);
void SIOtest(void);
int SIOSendByte_wait_txen(unsigned char data,int timeout);

#endif

