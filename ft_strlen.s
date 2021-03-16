global	_ft_strlen				; ft_strlen(const char *s)

section .text
_ft_strlen:
		xor rax, rax			; count = 0
loop:
		cmp byte [rdi + rax], 0	; while *s != 0
		jz done
		inc rax					; count++
		jmp loop				; repeat
done:
		ret						; return (count)
