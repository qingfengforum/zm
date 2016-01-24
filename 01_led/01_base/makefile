head:head.s
	arm-linux-gcc -c -o head.o head.s
	arm-linux-ld -Ttext 0x0 head.o -o head.elf
	arm-linux-objcopy -O binary -S head.elf head.bin

.PHONY:head clean
clean:
	rm -rf *.o *.elf *.bin
