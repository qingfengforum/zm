
#define rTCFG0 \
	*(volatile unsigned*)0x51000000
#define rTCFG1	\
	*(volatile unsigned*)0x51000004
#define rTCON	\
	*(volatile unsigned*)0x51000008
#define rTCNTB0 \
	*(volatile unsigned*)0x5100000C
#define rTCMPB0	\
	*(volatile unsigned*)0x51000010
#if 0
TCNTO0	0x51000014
TCNTB1	0x51000018
TCMPB1	0x5100001C
TCNTO1	0x51000020
TCNTB2	0x51000024
TCMPB2	0x51000028
TCNTO2	0x5100002C
TCNTB3	0x51000030
TCMPB3 	0x51000034
TCNTO3	0x51000038
#endif

#define rTCNTB4	\
	*(volatile unsigned*)0x5100003C
#define rTCNTO4 \
	*(volatile unsigned*)0x51000040

void init_timer0()
{
	rTCFG0 = 99;//prescaler:99+1=100
	rTCFG1 = 3;//divider:16
	rTCNTB0 = 312;
	rTCMPB0 = 156;	//脉冲宽度调制
	
	rTCON |= 1<<1;
//	rTCON = 9;		//启动定时器，设定为自动加载，同时初始化电平是低
	rTCON = 0xd;	
	/*
	 TCON	
	 [0]	0:关闭timer0
	 		1：启动timer0
	 [1]	0:无操作;
	 		1：刷新TCNTB0和TCMPB0;
			（此操作要先于定时器的启动）
	 [2]	0：初始化电平为低;
	 		1：初始化电平为高;
	 [3]	0：定时一次
	 		1：自动加载，重复定时;
	 [4]	0：禁用死区
	 		1：使能死区
			(只有timer0有死区控制)
	 
	 */

}
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
