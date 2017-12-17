BITS 64

	;; declare prerequistes
	global asm_strchr 	; EXPORT our 'asm_strchr' function

	section .text
	; char *asm_strchr(const char *s, int c)
	; return pointer to string from postion of 'c' in string s
asm_strchr:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp
	;;prologue end
	mov rax, rdi

	;loop_str - while loop
loop_str:
	cmp byte [rax],  sil	; (*s != c)
	je end
	cmp byte [rax], byte 0 	; (*s == '\0')
	je nullend
	inc rax			; Increment the first string *s++;
	jmp loop_str

nullend:
	mov rax, 0x0

end:
	;;epilogue
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end
	ret			; Return from procedure
