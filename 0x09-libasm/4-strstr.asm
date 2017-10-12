BITS 64

	;; declare prerequistes
	global asm_strstr 	; EXPORT our 'asm_strstr' function

	section .text
	; int asm_strstr(const char *str, const char *substr);
	; finds the first occurrence of the substring in the string
asm_strstr:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp
	push r15
	push r14
	push r13
	;;prologue end

	mov r15b, 0		; variable char *str
	mov r14b, 0		; variable char *substr
	mov r13b, 0
	;loop_str - while loop
loop_str:
	cmp [rdi], byte 0 	;  while (*str)
	je nullend
	mov r15, rdi 		; *Begin = *str;
	mov r14, rsi  		; *pattern = *substr;
loop_str_str:
	cmp [rdi], byte 0 	; (*str)
	je e
	cmp [r14], byte 0 	; (*pattern)
	je e
	mov r13b, [rdi]
	cmp r13b, [r14]		; (*str == *pattern)
	jne e
	add rdi, 1		; Increment the first string *str++;
	add r14, 1		; Increment the second string *pattern++;
	jmp loop_str_str
e:
	cmp [r14], byte 0
	je end
	add r15, 1		; Begin + 1;
	mov rdi, r15		; str = Begin + 1;
	jmp loop_str
loopend:
nullend:
	mov r15, 0x0
end:
	mov rax, r15		; Return Begin;

	;;epilogue
	pop r13			; Restore previous stack frame
	pop r14
	pop r15
	mov rsp, rbp
	pop rbp
	;;epilogue end
	ret			; Return from procedure
