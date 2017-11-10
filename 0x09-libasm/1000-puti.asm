BITS 64
	EXTERN asm_putc 	; IMPORT out 'asm_putc' function
	global asm_puti 	; EXPORT our 'asm_puti' function
        section .text
	; size_t asm_puti(int n);
        ; Prints the lowercase alphabet
asm_puti:
	;; prologue
        push rbp                ; Setup stack frame
        mov rbp, rsp
                                ; Save registers that are gonna be used in this
        push rsi                ; procedure, in case they were used before
        push rdi
        push rdx
        push r13
	push r14
	push r8
	;;  prologue end

        mov rsi, 0  		;size_t counter = 0
	xor r13, r13
        mov r13, rdi		;long no = n
        cmp r13d, 0 		;if(no<0)
        js negative
	mov rax, r13
	jmp print_number

	negative:
		mov r8, 1
		movsx r13, edi
		neg r13
		inc rsi
		mov rdi, 45
		call asm_putc
		mov rax, r13
	print_number:
		mov r13, rax
		inc rsi
		cdq
	        mov rbx, 10
	        xor rdx, rdx
	        idiv rbx
		push rdx
	        cmp r13, 10 		;if(n >= 10)
	        jge print_number
		mov r14, rsi
		cmp r8, 1
		jne loop
		dec r14
	loop:
		cmp r14, byte 0
		je end
		pop rdi
	        add rdi, 48
	        call asm_putc
		dec r14
		jmp loop
	end:
		mov rax, rsi
	
	;; epilogue
	pop r8
	pop r14
	pop r13
	pop rdx ; Restore used registers
	pop rdi
	pop rsi
	mov rsp, rbp
	pop rbp
	;; epilogue end

	ret
