global	_ft_strcmp					; ft_strcmp(const char *s1, const char *s2)

section .text
_ft_strcmp:
		xor rax, rax				; ret = 0
loop:
		mov al, byte [rdi]
		cmp al, 0
		jz done
		cmp byte [rsi], 0
		jz done
		;cmp byte [rdi], byte [rsi]
		cmp al, byte [rsi]
		jnz done
		inc rdi
		inc rsi
		jmp loop
done:
		sub al, byte [rsi]
		;adc al, 255
		ret
