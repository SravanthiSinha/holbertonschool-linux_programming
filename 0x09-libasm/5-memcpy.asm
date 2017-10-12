BITS 64

	;; declare prerequistes
	global asm_memcpy 	; EXPORT our 'asm_memcpy' function

	section .text
	; int asm_memcpy(void *dest, const void *src, size_t n);
	; copies n bytes from memory area src to memory area dest
asm_memcpy:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp
	push rcx
	push r15
	;;prologue end

	mov r15b, 0		; variable c
	mov rcx, rdx		; counter i

;loop_str - while loop
loop_str:
	cmp [rdi], byte 0 	; (!dest)
	je loopend
	mov r15b, [rsi] 	; c = *src
	mov [rdi], r15b         ; *dest = c
	add rdi, 1		; Increment the first string *dest++;
	add rsi, 1		; Increment the second string *src++;
	cmp rcx,  0		; (count > 0)
	jle loopend
	cmp [rsi], byte 0 	; (!src)
	je loopend
	sub rcx, 1;
	jmp loop_str
loopend:
	;;epilogue
	pop r15
	pop rcx
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end
	ret			; Return from procedure
