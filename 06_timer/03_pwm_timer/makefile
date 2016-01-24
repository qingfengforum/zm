CC	:=	arm-linux-gcc
LD	:=	arm-linux-ld
OBJCOPY	:=	arm-linux-objcopy

BIN	:=	`pwd|xargs basename`
#``可以把shell命令的结果当作字符串传递给makefile的变量
S_SRC	:=	$(wildcard *.s)
OBJS	:=	${S_SRC:%.s=%.o}
C_SRC	:=	$(wildcard *.c)
OBJS	+=	${C_SRC:%.c=%.o} 

$(BIN):$(OBJS)
	$(LD) -Tlink.lds $(OBJS) -o $(BIN).elf
#$(LD) -Ttext 0x0  $(OBJS) -o $(BIN).elf
	$(OBJCOPY) -S $(BIN).elf -O binary $(BIN).bin

%.o:%.c
	$(CC) -c -o $@ $^
#arm-linux-gcc -c -o main.o main.c
#此处发生循环执行命令，make将对所有的c文件进行逐一的编译
%.o:%.s
	$(CC) -c -o $@ $^
	
.PHONY:clean
clean:
	rm -rf *.o *.elf *.bin
