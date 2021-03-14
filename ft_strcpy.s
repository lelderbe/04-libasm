global	ft_strcpy			; ft_strcpy(char *dst, const char *src)

section .text
ft_strcpy:
		push rdi			; save *dst
loop:
		mov al, byte [rsi]
		mov byte [rdi], al
		cmp al, 0
		jz done
		inc rdi
		inc rsi
		jmp loop
done:
		pop rax
		ret
