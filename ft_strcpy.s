global	_ft_strcpy			; ft_strcpy(char *dst, const char *src)

section .text
_ft_strcpy:
		push rdi			; save dst pointer
loop:
		mov al, byte [rsi]	; al <- *src
		mov byte [rdi], al	; al -> *dst
		cmp al, 0			; was it \0?
		jz done				; if so - exit
		inc rdi				; dst++
		inc rsi				; src++
		jmp loop			; do repeat
done:
		pop rax				; return (dst)
		ret
