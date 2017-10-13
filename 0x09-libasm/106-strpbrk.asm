BITS 64

	;; declare prerequistes
	global asm_strpbrk 	; EXPORT our 'asm_strpbrk' function

	section .text
	; size_t strbrk(const char *s, const char *accept)
	; Find the first occurrence of a set of characters
asm_strpbrk:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp
	push r15
	push r14
	push r13
	;;prologue end

	mov r15b, 0		; variable char *cs1
	mov r14b, 0		; variable char *cs2
	mov r13b, 0

	mov r15, rdi 		; cs1 = s;
	;loop_str - while loop
loop_str:
	cmp [r15], byte 0 	;  while (*cs1 != '\0')
	je loopend
	mov r14, rsi  		; cs2 = accept;
loop_str_str:
	cmp [r14], byte 0 	; (*cs2 != '\0')
	je e
	mov r13b, [r15]
	cmp r13b, [r14]		; (*cs1 == *cs2)
	je end
	add r14, 1		; ++cs2
	jmp loop_str_str
e:
	add r15, 1		; ++cs1;
	jmp loop_str
loopend:
	mov r15, 0x0		; Return NULL
end:
	mov rax, r15		; Return the first occurrence

	;;epilogue
	pop r13			; Restore previous stack frame
	pop r14
	pop r15
	mov rsp, rbp
	pop rbp
	;;epilogue end
	ret			; Return from procedure
