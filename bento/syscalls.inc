macro exit c {
  mov rax, SYSCALL_EXIT
  mov rdi, c
  syscall
}


macro write fd, string, strlen {
  pusha64
  mov rdx, strlen
  mov rsi, string
  mov rdi, fd
  mov rax, SYSCALL_WRITE
  syscall
  popa64
}


