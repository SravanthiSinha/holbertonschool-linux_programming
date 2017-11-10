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
	push rcx
	push rdx
	push rdi
	;;prologue end

	; Setup 'write' syscall
	mov eax, 1		; Write syscall
	mov edx, 1		; Write 1 byte
	lea rsi, [rsp]		; Address of the character to be printed (Address of the stack)
	mov edi, 1		; write to stdout
	syscall

	;; epilogue
	pop rdi			; Restore used registers
	pop rdx
	pop rcx
	pop rsi
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end

	ret			; Return from procedure
