global _ft_write				; ft_write(int fd, const void *buf, size_t nbyte)
extern ___error

section .text
_ft_write:
		mov rax, 0x2000004		; write's system call number (MacOS)
		syscall
		jnc done				; no CF - no error
		push rax				; save error code
		call ___error			; get int *errno for error code in rax
		;pop qword [rax]			; put error code to errno
		pop rcx					; pop error code
		mov dword [rax], ecx	; ecx -> *errno
		mov rax, -1				; return -1 - error
done:
		ret
