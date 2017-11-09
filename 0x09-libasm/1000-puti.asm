BITS 64
	EXTERN asm_putc 	; IMPORT out 'asm_putc' function
	global asm_puti 	; EXPORT our 'asm_puti' function
        section .text
	; size_t asm_puti(int n);
        ; Prints the lowercase alphabet
print_number:
	;; prologue
	push rbp                ; Setup stack frame
	mov rbp, rsp
				; Save registers that are gonna be used in this
	push rdi
	push rdx
	;;  prologue end
        mov rax, rdi
        cdq
        mov rbx, 10
        xor rdx, rdx
        idiv rbx
        cmp rdi, 10 		;if(n >= 10)
        jge recur
        inc rsi
        xor rdi, rdi
        mov edi, edx
        add edi, 48
        call asm_putc
        jmp endprint_number
recur:
        mov rdi, rax
        inc rsi
        call print_number
        xor rdi, rdi
        mov edi, edx
        add edi, 48
        call asm_putc
        mov rdi, rax
endprint_number:
        ;; epilogue
        pop rdx 		; Restore used registers
        pop rdi
        mov rsp, rbp
        pop rbp
        ;; epilogue end

        ret

asm_puti:
	;; prologue
        push rbp                ; Setup stack frame
        mov rbp, rsp
                                ; Save registers that are gonna be used in this
        push rsi                ; procedure, in case they were used before
        push rdi
        push rdx
        push r13
	;;  prologue end

        mov rsi, 0  		;size_t counter = 0
        mov r13, rdi		;long no = n
        cmp r13d, 0 		;if(no<0)
        jns end
        movsx r13, edi
        neg r13
        inc rsi
        mov rdi, 45
        call asm_putc
end:
	mov rdi, r13
	call print_number 	;print_number(no, &counter);
	mov rax, rsi

	;; epilogue
	pop r13
	pop rdx ; Restore used registers
	pop rdi
	pop rsi
	mov rsp, rbp
	pop rbp
	;; epilogue end

	ret
