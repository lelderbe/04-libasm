global _ft_read					; ft_read(int fd, void *buf, size_t nbyte)
extern ___error

section .text
_ft_read:
		mov rax, 0x2000003		; read's system call number (MacOS)
		syscall
		jnc done				; no CF - no error
		push rax				; save error code
		call ___error			; get int *errno for error code in rax
		pop qword [rax]			; put error code to errno
		mov rax, -1				; return -1 - error
done:
		ret
