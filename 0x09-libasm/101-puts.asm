BITS 64
	EXTERN asm_strlen 	; IMPORT out 'asm_strlen' function

	global asm_puts 	; EXPORT our 'asm_puts' function
        section .text

        ; size_t asm_puts(const char *str);
        ; Prints the lowercase alphabet

asm_puts:
	;; prologue
        push rbp                ; Setup stack frame
        mov rbp, rsp
                                ; Save registers that are gonna be used in this
        push rsi                ; procedure, in case they were used before
        push rdi
        push rdx
        push r14
	;;  prologue end
	
        call asm_strlen
	
        mov r14, rax
        mov r13, rdi
	
loop_str:
        cmp [r13], byte 0
        je end

        ; Setup 'write' syscall
        mov rax, 1              ; Write syscall
	mov rdi, 1              ; write to stdout
	mov rdx, 1              ; Write 1 byte
	mov rsi, r13            ; Address of the character to be printed (Address of the stack)

	syscall
	add r13, 1
	jmp loop_str
end:
	mov rax, r14

	;; epilogue
	pop r14			; Restore used registers
	pop rdx
	pop rdi
	pop rsi
	mov rsp, rbp
	pop rbp
	;; epilogue end
	
	ret
