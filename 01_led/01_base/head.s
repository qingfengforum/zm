.text
.global _start
_start:
	mov sp,#4096

stop:
	b .	@=>b stop
