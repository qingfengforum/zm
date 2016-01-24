.text
.global _start
_start:
	@关闭看门狗
	ldr r0,=0x53000000
	mov r1,#0
	str r1,[r0]

	mov sp,#4096
	bl main
stop:
	b .	@=>b stop

