global _ft_strdup				; ft_strdup(const char *s1)
extern _malloc
extern _ft_strlen
extern _ft_strcpy

section .text
_ft_strdup:
		push rdi				; save s1 pointer
		call _ft_strlen			; get length of s1
		inc rax					; length + 1 (\0)
		mov rdi, rax			; put length to rdi for malloc
		call _malloc			; ask for memory length bytes
		mov rdi, rax			; put result into rdi
		pop rsi					; restore s1 pointer
		cmp rdi, 0
		jz done					; got NULL - exit, ENOMEM
		push rdi				; save dst pointer
		call _ft_strcpy			; copy s1 to dst
		pop rax					; result in rax
done:
		ret
