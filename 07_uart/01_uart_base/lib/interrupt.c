//中断源悬挂寄存器：有中断来了，某位置位，但是还没处理或没处理完
#define rSRCPND 		\
	*(volatile unsigned*)0X4A000000

//中断模式寄存器：可以配置某种类型的中断为快中断，但只允许一个为快中断;
#define rINTMOD 		\
	*(volatile unsigned*)0X4A000004 

//中断掩码寄存器：每个位对应一个中断，为1表示屏蔽此中断，为0表示打开;默认是屏蔽所有中断！
#define rINTMSK 		\
	*(volatile unsigned*)0X4A000008 

//中断优先级寄存器：该寄存器用于对多个中断实现排序和仲裁，一般用默认值即可
#define rPRIORITY 	\
	*(volatile unsigned*)0X4A00000C 

//中断悬挂寄存器：此寄存器每位表示一种中断，为1表示该中断要被cpu异常代码处理;只能有一个位为1！！！
#define rINTPND 		\
	*(volatile unsigned*)0X4A000010  

//中断偏移号寄存器：该寄存器表示一个整数，该整数值是某个中断在INTPND中置位的偏移量
#define rINTOFFSET 	\
	*(volatile unsigned*)0X4A000014  

//子中断源悬挂寄存器：表示已经到来，还未处理或没处理完的子中断
#define rSUBSRCPND 	\
	*(volatile unsigned*)0X4A000018 

//子中断掩码寄存器：用于屏蔽子中断，默认是子中断都屏蔽
#define rINTSUBMSK 	\
	*(volatile unsigned*)0X4A00001C

//扩展中断悬挂寄存器：某位置1,表示某个扩展中断发生;
#define rEINTPEND	\
	*(volatile unsigned*)0x560000a8

//扩展中断屏蔽寄存器：用于屏蔽扩展中断，默认是全部屏蔽;
#define rEINTMASK	\
	*(volatile unsigned*)0x560000a4

//以下三个寄存器用于对扩展中断的管脚，设定中断信号的发生方式：
//000=低电平，001=高电平，01X=下降沿，10X=上升沿，11X=上升沿或下降沿
#define rEXTINT0	\
	*(volatile unsigned*)0x56000088
#define rEXTINT1  	\
	*(volatile unsigned*)0x5600008c
#define rEXTINT2	\
	*(volatile unsigned*)0x56000090

#define rGPGCON	*(volatile unsigned*)0x56000060
#define rGPGDAT	*(volatile unsigned*)0x56000064
    
void init_interrupt_for_timer0()
{
	rINTMSK &= ~(1<<10);
}
void init_interrupt_for_timer4()
{
	rINTMSK &= ~(1<<14);
//	rINTMSK &= ~(1<<10);
}
  
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

void int_key();
void int_timer4();
void interrupt_f()
{
	switch(rINTOFFSET)
	{
		case 5:
			int_key();
			break;
		case 14:
			int_timer4();
			break;
		case 10:

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
	int i=0xfff;
	if(rEINTPEND &(1<<8)){
		//k1 press
		write_TCNTB4(31250/2);
	//	if(read_TCNTB4()==0)
	//		write_TCNTB4(1);
	}else if(rEINTPEND &(1<<11)){
		write_TCNTB4(31250*2);
	}	

}
void int_timer4()
{
#if 1
	static int i=-1;
	i++;
	switch(i%8)
	{
	case 0:
		led_on(1);
		beep_on();
		break;
	case 2:
		led_on(2);
		beep_on();
		break;
	case 4:
		led_on(3);
		beep_on();
		break;
	case 6:
		led_on(4);
		beep_on();
		break;
	default:
		led_off_all();
		beep_off();
		break;
	}
	/*
	if(i%2){
		led_on_all();
		beep_on();
	}
	else{
		led_off_all();
		beep_off();
	}*/
#else
	//testing
	*(volatile unsigned*)0x56000014=
	~*(volatile unsigned*)0x56000014;

#endif
}
