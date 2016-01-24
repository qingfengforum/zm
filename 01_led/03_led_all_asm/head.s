.text
.global _start
_start:
	mov sp,#4096

	@配置GPB5~8为输出模式
	ldr r0,=0x56000010	@GPBCON addr
	ldr r1,=0x15400	
	@[17:16][15:14][13:12][11:10] 
	@01 0101 0100 0000 0000
	@0x15400
			@mov r1,#1
			@mov r1,r1,lsl #5*2
	str r1,[r0]

loop:	
	@熄灭led1-4,把GPB5~8管脚电平推高,此时发光二极管led1-4是非导通状态;
	ldr r0,=0x56000014	@GPBDAT addr
	ldr r1,=0xffffffff	@GPB5 set
						@10 0000
						@0x20
		@mov r1,#1
		@mov r1,r1,lsl#5
	str r1,[r0]

	bl delay @跳转延时代码,手动延时，效率低

	@点亮led
	ldr r0,=0x56000014	@GPBDAT addr
	ldr r1,=0x0		@GPB5 clear 
		@ldr r1,[r0]
		@mov r2,#1
		@mvn r2,r2,lsl#5
		@and r1,r1,r2
	str r1,[r0]
	bl delay

	b loop 
stop:
	b .	@=>b stop

delay:
	ldr r3,=0xffff
wait:
	sub r3,r3,#1
	cmp r3,#0
	bne wait
	mov pc,lr

