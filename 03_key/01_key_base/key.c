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

int key_press()
{
	switch(rGPGDAT&0x1)
	{
	case 1:
		return 0;
	default:
		return 1;
	}

}
