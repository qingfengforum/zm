head:head.s
	arm-linux-gcc -c -o head.o head.s
	arm-linux-gcc -c -o led.o led.c
	arm-linux-gcc -c -o main.o main.c
	arm-linux-ld -Ttext 0x0 head.o led.o main.o -o head.elf
	arm-linux-objcopy -O binary -S head.elf led.bin

#.PHONY:head clean
clean:
	rm -rf *.o *.elf *.bin
