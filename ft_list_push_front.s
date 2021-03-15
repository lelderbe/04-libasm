global _ft_list_push_front		; ft_list_push_front(t_list **lst, t_list *new)

section .text
_ft_list_push_front:
		cmp rdi, 0
		jz done					; lst is 0
		cmp rsi, 0
		jz done					; no new element
		mov rax, [rdi]			; *lst -> rax
		mov [rsi + 8], rax		; new->next = *lst
		mov [rdi], rsi			; *lst = new
done:
		ret
