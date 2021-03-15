global _ft_list_push_front		; ft_list_push_front(t_list **lst, void *data)
extern _ft_list_create_elem

section .text
_ft_list_push_front:
		cmp rdi, 0
		jz done					; lst is 0
		cmp rsi, 0
		jz done					; no new element data
		push rdi
		mov rdi, rsi
		call _ft_list_create_elem
		pop rdi
		mov rsi, rax			; rsi <- new
		mov rax, [rdi]			; *lst -> rax
		mov [rsi + 8], rax		; new->next = *lst
		mov [rdi], rsi			; *lst = new
done:
		ret
