global _ft_list_create_elem			; t_list *ft_list_create_elem(void *data)
extern _malloc

section .text
_ft_list_create_elem:
		push rdi					; save data pointer
		mov rdi, 16					; size of 2 pointers
		call _malloc				; pointer to a new element
		pop rdi
		cmp rax, 0
		jz done						; got NULL - exit
		mov [rax], rdi				; elem->data = data
		mov qword [rax + 8], 0		; elem->next = 0
done:
		ret
