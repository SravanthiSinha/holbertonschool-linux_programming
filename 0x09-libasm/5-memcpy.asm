BITS 64

	;; declare prerequistes
	global asm_memcpy 	; EXPORT our 'asm_memcpy' function

	section .text
	; int asm_memcpy(void *dest, const void *src, size_t n);
	; copies n bytes from memory area src to memory area dest
asm_memcpy:
	mov rax, rdi		; Copy the pointer to @dest string to be returned
	mov ecx, edx		; Copy the length @n to the counter
	cld			; Clear the direction flag, DL
	rep movsb		; Copy @n bytes from ESI (source) to EDI (destination)
	ret			; Return
