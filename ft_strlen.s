global	_ft_strlen

section .text
_ft_strlen:
		;push rcx
		mov rcx, 0		; count = 0
loop:
		cmp byte [rdi], 0	; while *s != 0
		jz done
		inc rcx			; count++
		inc rdi			; s++
		jmp loop
done:
		mov rax, rcx	; return (count)
		;pop rcx
		ret
