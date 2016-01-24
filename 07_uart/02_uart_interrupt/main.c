#include "include/led.h"
#include "include/beep.h"
#include "include/key.h"

void delay(int n)
{
	while(n--);
}

#define __DEBUG__
#ifdef __DEBUG__
#define put_string	put_string
#else
#define put_string	
#endif


int main()
{
	init_clock();
	init_uart0();
	init_interrupt_for_uart0();

	put_string("\n");
	//("\n");

	put_string("init_led\n");
	init_led();
	led_on_all();
	put_string("init_beep\n");
	init_beep();

	while(1)
	{
	}
	 return 0;
}
