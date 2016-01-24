//异步串口线路控制寄存器
//主要用于配置通信的校验，停止，数据位
#define rULCON0	\
	*(volatile unsigned*)0x50000000

//异步串口控制寄存器
//用于设定串口工作的频率，收发方式
#define rUCON0	\
	*(volatile unsigned*)0x50000004

//串口收发状态寄存器
//用于判断硬件是否可以发送或接受数据
#define rUTRSTAT0 \
	*(volatile unsigned*)0x50000010

//串口发送数据的缓冲寄存器
//此寄存器会把写入的数据发送出去
#define rUTXH0 \
	*(volatile unsigned*)0x50000020

//串口接受数据的缓冲寄存器
//用于把接受的数据暂时存放在此
#define rURXH0 \
	*(volatile unsigned*)0x50000024

//串口波特率配置寄存器
//用于设定异步串口工作的波特率
#define rUBRDIV0 \
	*(volatile unsigned*)0x50000028

//该寄存器的[7：4]用于设定异步串口的管脚复用
#define rGPHCON \
	*(volatile unsigned*)0x56000070
 

void init_uart0()
{
	rULCON0 = 0x3;// 8N1
	rUCON0 =  0x5;
	/*
	  11 10 9 8  7 6 5 4  3 2 1 0
	  0  0  0 0  0 0 0 0  0 1 0 1
	 [1:0] = b01,中断或轮寻方式接受;
	 [3:2] = b01,中断或轮寻方式发送;
	 [11:10] = b00,b01,PCLK
	 其他位默认值
	 */
	rUBRDIV0 = (int)(50000000/(115200*16)) - 1;
	/*
	 UBRDIVn
	  = (int)( UART clock / ( buad rate x 16) ) –1
	 */
	rGPHCON = 0xa<<4; //0xa0
	/*把GPH2-3复用为uart0的收发线路*/
}

char get_char()
{
	while(1)
	{
		//rUTRSTAT0[0]==1,有数据来了
		if(rUTRSTAT0&0x1)
			return rURXH0;
	}
}
void put_char(char ch)
{
	while(1)
	{
		//rUTRSTAT0[2]==1，可以发送数据
		if(rUTRSTAT0&0x4){
			rUTXH0 = ch;
			return;
		}
	}
}


void put_string(const char* str)
{
	while(*str)
	{
		if(*str == '\n')
		{
			put_char('\r');
		}
		put_char(*str++);
	}
}

#if 0
UFCON0
0x50000008
UMCON0
0x5000000C
UERSTAT0
0x50000014
UFSTAT0
0x50000018
UMSTAT0
0x5000001C
ULCON1
0x50004000
UCON1
0x50004004
UFCON1
0x50004008
UMCON1
0x5000400C
UTRSTAT1
0x50004010
UERSTAT1
0x50004014
UFSTAT1
0x50004018
UMSTAT1
0x5000401C
UTXH1
0x50004023
URXH1
0x50004027
UBRDIV1
0x50004028
ULCON2
0x50008000
UCON2
0x50008004
UFCON2
0x50008008
UTRSTAT2
0x50008010
UERSTAT2
0x50008014
UFSTAT2
0x50008018
UTXH2
0x50008023
URXH2
0x50008027
UBRDIV2
0x50008028
#endif
