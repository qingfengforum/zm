#include "include/led.h"
#include "include/beep.h"
#include "include/key.h"

void delay(int n)
{
	while(n--);
}

int main()
{
	init_clock();
	init_led();
	init_beep();
	//init_key();
	//init_interrupt_for_key();

	led_off_all();
//	led_on_all();

	int i;
	while(1)
	{
		for(i=1;i<=4;i++)
		{
			led_on(i);
			beep_on();
			delay(0xffff);
			led_off(i);
			beep_off();
			delay(0xffff);
		}
	}
	 return 0;
}
