#include "include/led.h"
#include "include/beep.h"

void delay(int n)
{
	while(n--);
}

int main()
{
	init_led();
	init_beep();

	int i;

	while(1)
	{
		for(i=1;i<=4;i++)
		{
			led_on(i);
			beep_on();
			delay(0xfff);
			led_off(i);
			beep_off();
			delay(0xfff);
		}
	
	}
	 return 0;
}
