BITS 64

	;; declare prerequistes
	global asm_strncasecmp 	; EXPORT our 'asm_strncasecmp' function

	section .text

	; int asm_strncasecmp(const char *s1, const char *s2, size_t n);
	; compares n bytes of the 2 string
asm_strncasecmp:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp

	push rcx
	push r15
	push r14
	;;prologue end

	mov r15b, 0		; variable c1
	mov r14b, 0		; variable c2
	mov rcx, rdx			; counter i
	;loop_str - while loop
loop_str:
	mov r15b, [rdi] 	; c1 = *s1;
	mov r14b, [rsi]  	; c2 = *cs2;
	add rdi, 1		; Increment the first string *cs1++;
	add rsi, 1		; Increment the second string *cs2++;

	cmp rcx,  0		; (count > 0)
	jle eq
	cmp r15b, 41h
	jb end1

	cmp r15b, 5bh
	jg end1

	add r15b,20H
end1:
	cmp r14b, 41h
	jb end2

	cmp r14b, 5bh
	jg end2

	add r14b,20H
end2:

	cmp r15b, r14b		; (c1 != c2)
	jne loopend
	cmp [rsi], byte 0 	; (!c1)
	je eq
	sub rcx, 1;
	jmp loop_str
loopend:
	mov rax, r15
	sub rax, r14
	jmp end
eq:
	mov rax, 0x0		; Set return value 0
	jmp end

end:
	;;epilogue
	pop r14
	pop r15
	pop rcx
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end
	ret			; Return from procedure
