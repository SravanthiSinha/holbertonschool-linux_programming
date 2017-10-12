BITS 64

	global asm_putc	; EXPORT our 'asm_putc' function

	section .text

	; size_t asm_putc(int c);
	; Prints the input char

asm_putc:
	;;prologue
	push rbp		; Setup stack frame
	mov rbp, rsp
				; Save registers that are gonna be used in this
	push rsi		; procedure, in case they were used before
	push rdi
	push rdx
	;;prologue end
	
	add rsp, -1		; Increase the stack by 1 byte to store a char
	mov [rsp], rdi		; Store the ascii value of input char c

	; Setup 'write' syscall
	mov rax, 1		; Write syscall
	mov rdi, 1		; write to stdout
	mov rdx, 1		; Write 1 byte
	mov rsi, rsp		; Address of the character to be printed (Address of the stack)

	syscall
end:
	add rsp, 1		; Discard our local variable
	mov rax, 0x1
	
	;; epilogue
	pop rdx			; Restore used registers
	pop rdi
	pop rsi
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end
	
	ret			; Return from procedure
