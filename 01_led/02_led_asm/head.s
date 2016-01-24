.text
.global _start
_start:
	mov sp,#4096

	@配置GPB5为输出模式
	ldr r0,=0x56000010	@GPBCON addr
	ldr r1,=0x400	@[11:10] 
					@01 00 00 00 00 00
					@0x400
			@mov r1,#1
			@mov r1,r1,lsl #5*2
	str r1,[r0]

loop:	
	@熄灭led1,把GPB5管脚电平推高,此时发光二极管led1是非导通状态;
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

