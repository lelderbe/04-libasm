global _ft_list_size				; ft_list_size(t_list *lst)

section .text
_ft_list_size:
		xor rcx, rcx				; count = 0
loop:
		cmp rdi, 0					; lst == 0 ?
		jz done
		inc rcx						; count++
		mov rdi, [rdi + 8]			; lst = lst->next
		jmp loop
done:
		mov rax, rcx				; return (count)
		ret
