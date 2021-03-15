global	_ft_strcmp					; ft_strcmp(const char *s1, const char *s2)

section .text
_ft_strcmp:
		xor rax, rax				; *s1
		xor rcx, rcx				; *s2
loop:
		mov al, byte [rdi]			; al <- *s1
		mov cl, byte [rsi]			; cl <- *s2
		cmp al, 0					; al is \0?
		jz done						; exit then
		cmp cl, 0					; cl is \0?
		jz done						; exit then
		cmp al, cl					; al == cl ?
		jnz done					; exit if not
		inc rdi						; s1++
		inc rsi						; s2++
		jmp loop					; check next byte
done:
		sub rax, rcx				; return (*s1 - *s2)
		ret
