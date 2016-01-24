#define rSRCPND 		\
	*(volatile unsigned*)0X4A000000
#define rINTMOD 		\
	*(volatile unsigned*)0X4A000004 
#define rINTMSK 		\
	*(volatile unsigned*)0X4A000008 
#define rPRIORITY 	\
	*(volatile unsigned*)0X4A00000C 
#define rINTPND 		\
	*(volatile unsigned*)0X4A000010  
#define rINTOFFSET 	\
	*(volatile unsigned*)0X4A000014  
#define rSUBSRCPND 	\
	*(volatile unsigned*)0X4A000018 
#define rINTSUBMSK 	\
	*(volatile unsigned*)0X4A00001C


#define rEINTPEND	\
	*(volatile unsigned*)0x560000a8
#define rEINTMASK	\
	*(volatile unsigned*)0x560000a4
#define rEXTINT0	\
	*(volatile unsigned*)0x56000088
#define rEXTINT1  	\
	*(volatile unsigned*)0x5600008c
#define rEXTINT2	\
	*(volatile unsigned*)0x56000090

#define rGPGCON	*(volatile unsigned*)0x56000060
#define rGPGDAT	*(volatile unsigned*)0x56000064
    
  
void init_interrupt_for_key()
{
	rINTMSK &= ~(1<<5);//打开按键中断屏蔽
	rEINTMASK &= ~(1<<8);
	rEINTMASK &= ~(1<<11);
	rEINTMASK &= ~(1<<13);
	rEINTMASK &= ~(1<<14);
	rEINTMASK &= ~(1<<15);
	rEINTMASK &= ~(1<<19);

	rGPGCON |= 2<<0*2;
	rGPGCON |= 2<<3*2;
	rGPGCON |= 2<<5*2;
	rGPGCON |= 2<<6*2;
	rGPGCON |= 2<<7*2;
	rGPGCON |= 2<<11*2;

	//此处可以添加改变扩展GPIO复用中断类型的选择代码
	rEXTINT1 = 0;
}

void interrupt_f()
{
	switch(rINTOFFSET)
	{
		case 5:
			int_key();
			break;
		default:
			break;
	}

	rSRCPND = rSRCPND;
	rINTPND = rINTPND;
	rEINTPEND = rEINTPEND;
}

void int_key()
{
	if(rEINTPEND &(1<<8)){
		//k1 press
		led_on(1);
		beep_on();
	}	

}
