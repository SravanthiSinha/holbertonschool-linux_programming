BITS 64

	global asm_puts 	; EXPORT our 'asm_puts' function
	EXTERN asm_strlen 	; IMPORT out 'asm_strlen' function
        section .text

        ; size_t asm_puts(const char *str)
        ; Prints the string

asm_puts:
	push rbp		; Setup stack frame
	mov rbp, rsp

	call asm_strlen		; Call asm_strlen to measure the string length
	mov edx, eax		; Use the length of the string as 3rd arg to write syscall
	mov esi, edi		; 2nd arg is the string
	mov edi, 1		; 1st arg is the file descriptor to write to (1 for STDOUT)
	mov eax, 1		; eax carries the syscall number (1 for write)
	syscall
	mov rsp, rbp 		; Restore previous stack frame
	pop rbp
	ret			; Return
