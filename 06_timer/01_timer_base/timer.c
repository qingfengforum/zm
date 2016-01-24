
#define rTCFG0 \
	*(volatile unsigned*)0x51000000
#define rTCFG1	\
	*(volatile unsigned*)0x51000004
#define rTCON	\
	*(volatile unsigned*)0x51000008
#define rTCNTB0 \
	*(volatile unsigned*)0x5100000C
#if 0
TCMPB0
0x51000010
TCNTO0
0x51000014
TCNTB1
0x51000018
TCMPB1
0x5100001C
TCNTO1
0x51000020
TCNTB2
0x51000024
TCMPB2
0x51000028
TCNTO2
0x5100002C
TCNTB3
0x51000030
TCMPB3
0x51000034
TCNTO3
0x51000038
#endif

#define rTCNTB4	\
	*(volatile unsigned*)0x5100003C
#define rTCNTO4 \
	*(volatile unsigned*)0x51000040

void init_timer4()
{
	/*
	 TF = PCLK / {prescaler value+1} / {divider value};
	 {prescaler value} = 0~255
	 {divider value} = 2, 4, 8, 16
	 */
#if 1
	rTCFG0 = 99<<8;//prescaler:99+1=100
	rTCFG1 = 3<<16;//divider:16
//	rTCNTB4 = 31250;	//1秒
	rTCNTB4 = 31250/2;	//0.5秒
	
	rTCON |= 1<<21;
	rTCON = 5<<20;
#else
	rTCFG0 = 99;//prescaler:99+1=100
	rTCFG1 = 3;//divider:16
	rTCNTB0 = 31250;
	
	rTCON |= 1<<1;
	rTCON = 9;

#endif
}
int write_TCNTB4(int c)
{
	rTCNTB4 = c;
}
int read_TCNTB4()
{
	return rTCNTB4;
}
