#include "include/led.h"
#include "include/beep.h"
#include "include/key.h"

void delay(int n)
{
	while(n--);
}

//#define __DEBUG__
#ifdef __DEBUG__
#define put_string	put_string
#else
#define put_string	
#endif


int main()
{
	init_clock();
	init_uart0();
	put_string("\n");
	//("\n");

	put_string("init_led\n");
	init_led();
	led_on_all();
	put_string("init_beep\n");
	init_beep();

//	int m =200;
//	put_int(m);

	char ch;
	while(1)
	{
		put_string("waiting input char...\n");
		ch = get_char();
		
		put_string("your char is: ");
		put_char(ch);
		put_string("\n");
	}
	 return 0;
}
