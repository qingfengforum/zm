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
	init_key();
	init_interrupt_for_key();

	init_timer4();
	init_interrupt_for_timer4();

	led_off_all();
//	led_on_all();

	while(1)
	{
	}
	 return 0;
}
