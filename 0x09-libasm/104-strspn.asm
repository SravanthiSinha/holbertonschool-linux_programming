BITS 64

	;; declare prerequistes
	global asm_strspn 	; EXPORT our 'asm_strspn' function

	section .text
	; size_t strspn(const char *s, const char *accept);
	; Calculate the length of the initial substring of @s which only contain letters in @accept
asm_strspn:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp
  push rcx
	push r15
	push r14
	push r13
	;;prologue end

	mov r15b, 0		; variable char *p
	mov r14b, 0		; variable char *a
	mov r13b, 0
  mov rcx, 0h

	mov r15, rdi 		; p = s;
	;loop_str - while loop
loop_str:
	cmp [r15], byte 0 	;  while (*p != '\0')
	je loopend
	mov r14, rsi  		; a = accept;
loop_str_str:
	cmp [r14], byte 0 	; (*a != '\0')
	je e
	mov r13b, [r15]
	cmp r13b, [r14]		; (*p == *a)
	je e
	add r14, 1		; ++a
	jmp loop_str_str
e:
	cmp [r14], byte 0  ; (*a != '\0')
	je loopend
	add r15, 1		; ++p;
  inc rcx
	jmp loop_str
loopend:
	mov rax, rcx		; Return count

	;;epilogue
	pop r13			; Restore previous stack frame
	pop r14
	pop r15
  pop rcx
	mov rsp, rbp
	pop rbp
	;;epilogue end
	ret			; Return from procedure
