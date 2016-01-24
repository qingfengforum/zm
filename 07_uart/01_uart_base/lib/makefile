CC	:=	arm-linux-gcc
LD	:=	arm-linux-ld
OBJCOPY	:=	arm-linux-objcopy

C_SRC	:=	$(wildcard *.c)
OBJS	:=	${C_SRC:%.c=%.o} 

all:$(OBJS)
	ar cr libarm.a $(OBJS)
%.o:%.c
	$(CC) -c -o $@ $^
	
.PHONY:clean
clean:
	rm -rf *.o *.elf *.bin *.a
