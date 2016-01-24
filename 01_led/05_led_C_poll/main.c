int main()
{
	unsigned *WDT=0x53000000;
	*WDT = 0;

	//设置GPB5～8为输出模式
	unsigned * GPBCON = 0x56000010;
	unsigned gpbcon_info = 0x15400;
	*GPBCON = gpbcon_info;

	unsigned *GPBDAT = 0x56000014;
	int i,k;
	//进入循环
	while(1)
	{
		for(k=5;k<=8;k++)
		{
			*GPBDAT = 0xffffffff;
			for(i=0xfff;i--;);
			*GPBDAT = ~(0x1<<k);
			for(i=0xfff;i--;);
		}
	}
	 return 0;
}
