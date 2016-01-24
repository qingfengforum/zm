#include "include/led.h"
#define GPB0_OUT	(1<<0)
#define rGPBCON	\
	*(volatile unsigned *)0x56000010
#define rGPBDAT	\
	*(volatile unsigned *)0x56000014
void init_beep()
{
	rGPBCON |=	GPB0_OUT;
}
void beep_on()
{
	rGPBDAT |= 1;
}
void beep_off()
{
	rGPBDAT &= ~1;
}
