global	_ft_strlen			; ft_strlen(const char *s)
global	ft_strlen			; ft_strlen(const char *s)

section .text
_ft_strlen:
ft_strlen:
		xor rcx, rcx		; count = 0
loop:
		cmp byte [rdi], 0	; while *s != 0
		jz done
		inc rcx				; count++
		inc rdi				; s++
		jmp loop
done:
		mov rax, rcx	; return (count)
		ret
