BITS 64

	;; declare prerequistes
	global asm_strcmp 	; EXPORT our 'asm_strcmp' function

	section .text
	; int asm_strcmp(const char *s1, const char *s2)
	; compares the 2 string
asm_strcmp:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp

	push r15
	push r14
	;;prologue end

	mov r15b, 0		; variable c1
	mov r14b, 0		; variable c2

	;loop_str - while loop
loop_str:
	mov r15b, byte [rdi] 	; c1 = *s1;
	mov r14b, byte [rsi]  	; c2 = *s2;
	add rdi, 1		; Increment the first string *s1++;
	add rsi, 1		; Increment the second string *s2++;
	cmp r15b, r14b		; (c1 != c2)
	jne loopend
	cmp r15b, byte 0 	; (!c1)
	je eq
	jmp loop_str
loopend:

	cmp r15b, r14b		; c1 < c2
	jl neg
	jmp pos

neg:
	mov rax, 0xFFFFFFFF 	; Set return value -1
	jmp end

pos:
	mov rax, 0x1		; Set return value 1
	jmp end

eq:
	mov rax, 0x0		; Set return value 0
	jmp end

end:
	;;epilogue
	pop r14
	pop r15
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end
	ret			; Return from procedure
