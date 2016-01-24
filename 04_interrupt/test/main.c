#include "include/led.h"
#include "include/beep.h"
#include "include/key.h"

void delay(int n)
{
	while(n--);
}

int flag=0;
int main()
{
	init_led();
	init_beep();
	//init_key();
	//init_interrupt_for_key();

	led_off_all();
	if(flag){
		led_on_all();
		beep_on();
	}

	while(1)
	{
	}
	 return 0;
}
