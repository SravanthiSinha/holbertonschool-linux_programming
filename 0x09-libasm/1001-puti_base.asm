BITS 64

	;; declare prerequistes
	global asm_puti_base		; EXPORT our 'asm_puti_base' function
	extern asm_putc, asm_strlen	; Import our function from external file
	section .text
	; size_t asm_puti_base(int n, const char *base)
	; Prints a signed integer in a given base on the standard output

asm_puti_base:
	;;prologue
	push rbp		; Set up stack frame
	mov rbp, rsp
	push rdx
	push r8
	push r9
	push rdi
	;;prologue end

	mov rdi, rsi

	call asm_strlen		; Call to strlen, measure the length of string
	pop rdi
	push rax
	lea rdx, [rsp]
	xor r9d, r9d
	mov eax, edi
	test eax, eax
	js negative
print:
	mov ebx, [rdx]		; Copy the length of string to ebx
	xor ecx, ecx		; set  counter to 0
	not ecx			; Invert ecx bits to count backwards
iloop:	xor edx, edx		; Reset edx to make the division
	div ebx			; Divide the number (in edx:eax) by length of string
	sub rsp, 1		; Reserve one byte on stack to put the remainder
	mov [rsp], dl		; Save the remainder of division (number / length)
	test eax, eax		; Check when we reach zero
	loopnz iloop		; While not zero, decrement ecx and loop
	not ecx			; Invert bits again to get positive number of bytes
pstr:	movzx r8d, BYTE [rsp]	; After we reach zero start copying bytes from stack
	movzx edi, BYTE [rsi + r8] ; in reverse order to be printed
	call asm_putc		   ; Print each digit
	add r9b, al		   ; Transfer the result of call to putc to our counter
	add rsp, 1		   ; Restore each byte from the stack
	loopnz pstr		   ; While not zero, decrement the counter (ecx) and loop
	mov eax, r9d		   ; When zero, copy the acumulator to return value

end:
	add rsp, 8		; Remove 8 bytes from stack (used by rax)

	;;epilogue
	pop r9
	pop r8
	pop rdx
	mov rsp, rbp		; Restore previous stack frame
	pop rbp
	;;epilogue end
	ret			; Return from procedure

negative:			; Subroutine to deal with negative numbers
	neg eax			; Make positive (flip sign)
	push rax		; Preserve the number on stack
	mov edi, '-'		; Define 1st arg to putc
	call asm_putc		; Call putc to print the minus sign
	add r9b, al		; Add the return value to r9 to be returned later
	pop rax			; Restore the number
	mov edi, eax		; Use the number as 1st argument to next routine
	jmp print		; Jump to 'print' subroutine
