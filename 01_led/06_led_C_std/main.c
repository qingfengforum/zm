#include "include/led.h"


void delay(int n)
{
	while(n--);
}

int main()
{
	init_led();

	int i;
	while(1)
	{
		for(i=1;i<=4;i++)
		{
			led_on(i);
			delay(0xfff);
			led_off(i);
			delay(0xfff);
		}
	
	}
	 return 0;
}
