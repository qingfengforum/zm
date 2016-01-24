#define rCLKDIVN \
	*(volatile unsigned*)0x4C000014
#define rMPLLCON	\
	*(volatile unsigned*)0x4C000004

void init_clock()
{
	//f=200M, H = 100M, P= 50M
	//1:2:4
	//f=400M, H= 100M, p=50M
	//1:4:8
	rCLKDIVN = 3;	//1:2:4 
	__asm__(
	"mrc p15,0,r0,c1,c0,0\n"
	"orr r0,r0,#0xc0000000\n"
	"mcr p15,0,r0,c1,c0,0\n"
	);//bus mode = 异步通信

	rMPLLCON = 0x5c<<12|0x1<<4|0x2;
		//200MHz
}
   
