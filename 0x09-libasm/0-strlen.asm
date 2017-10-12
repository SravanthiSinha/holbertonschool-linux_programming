BITS 64

	;; declare prerequistes
	global asm_strlen 	; EXPORT our 'asm_strlen' function

	section .text
	; size_t asm_strlen(char *s)
	; returns the size of the string
asm_strlen:
	;;prologue
	push rbp		; Set up stack fram
	mov rbp, rsp
	;;prologue end

	mov cl, 0 		; Declare a counter

	;loop_str - while (*s ! = '\0')
loop_str:
	cmp [rdi], byte 0	; Compare the value with NULL
	je end
	add rdi, 1		; Increment the string
	inc cl			; Increment the counter
	jmp loop_str
end:
	mov rax, rcx		; Set the return value
	;;epilogue
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end
	ret			; Return from procedure
