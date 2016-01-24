OUTPUT_ARCH(arm)	 
ENTRY(_start)
SECTIONS
{
	. = 0x0 ;
	. = ALIGN(4) ;
	.text :
	{
		./head.o ;
		*(.text);
	}
	. = ALIGN(4) ;
	.rodata : {*(.rodata)}
	. = ALIGN(4) ;
	.data : {*(.data)}
	. = ALIGN(4) ;
	__bss_start = .;
	.bss : {*(.bss)}
	__bss_end = . ;

}
