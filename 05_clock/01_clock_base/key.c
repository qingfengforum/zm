#define	rGPGCON	\
	*(volatile unsigned*)0x56000060
#define	rGPGDAT	\
	*(volatile unsigned*)0x56000064

#define	GPG0_IN		~(3<<0*2)
#define	GPG3_IN		~(3<<3*2)
#define	GPG5_IN		~(3<<5*2)
#define	GPG6_IN		~(3<<6*2)
#define	GPG7_IN		~(3<<7*2)
#define	GPG11_IN	~(3<<11*2)
void init_key()
{
	//rGPGCON &= ~(3<<0);
	rGPGCON &= GPG0_IN&GPG3_IN&GPG5_IN
		&GPG6_IN&GPG7_IN&GPG11_IN;
}

int isKEY(int num)
{
	switch(num)
	{
	case 1:
		return rGPGDAT&(1<<0)?0:1;
	case 2:
		return rGPGDAT&(1<<3)?0:1;
	case 3:
		return rGPGDAT&(1<<5)?0:1;
	case 4:
		return rGPGDAT&(1<<6)?0:1;
	case 5:
		return rGPGDAT&(1<<7)?0:1;
	case 6:
		return rGPGDAT&(1<<11)?0:1;
	default:
		return 0;
	}
}

int key_press()
{
	int i;
	for(i=1;i<=6;i++)
		if(isKEY(i))return i;


	return 0;
}


//void int_key()
//{
	

//}
