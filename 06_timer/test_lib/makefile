CC	:=	arm-linux-gcc
LD	:=	arm-linux-ld
OBJCOPY	:=	arm-linux-objcopy

BIN	:=	`pwd|xargs basename`
#``可以把shell命令的结果当作字符串传递给makefile的变量

$(BIN):
	make -C ./lib	#生成静态库
	$(CC) -c -o head.o head.s 
	$(CC) -c -o main.o main.c 
	$(LD) -Tlink.lds head.o main.o ./lib/libarm.a -o $(BIN).elf
#$(LD) -Ttext 0x0  $(OBJS) -o $(BIN).elf
	$(OBJCOPY) -S $(BIN).elf -O binary $(BIN).bin

	
.PHONY:clean
clean:
	rm -rf *.o *.elf *.bin
	make clean -C ./lib
