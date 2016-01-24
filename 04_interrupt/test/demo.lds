OUTPUT_ARCH(arm)	//指定ld程序生成for arm的代码
ENTRY(_start)	//入口指令的地址符号
SECTIONS
{
	. = 0x0 ;	//指定第一条指令从0x0编址
	. = ALIGN(4) ;//以下内容按照4字节对齐
	.text :	//指定代码段
	{
		./head.o ;	//指定head.o放在第一个位置
		*(.text);//由makefile指定链接顺序
	}
	. = ALIGN(4) ;
	.rodata : {*(.rodata)}//只读数据段
	. = ALIGN(4) ;
	.data : {*(.data)}//普通数据段
	. = ALIGN(4) ;
	__bss_start = .;
	.bss : {*(.bss)}//未初始化的数据段
	__bss_end = . ;

}
