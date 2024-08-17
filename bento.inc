macro @@ {}

SYSCALL_WRITE equ 1
SYSCALL_EXIT  equ 60

STDIN  equ 0
STDOUT equ 1
STDERR equ 2

macro pusha64 {
  push rax
  push rbx
  push rcx
  push rdx

  push rsi
  push rdi
  
  push rbp
  push rsp

  push r8
  push r9
  push r10
  push r11
  push r12
  push r13
  push r14
  push r15
}

macro popa64 {
  pop r15
  pop r14
  pop r13
  pop r12
  pop r11
  pop r10
  pop r9
  pop r8

  pop rsp
  pop rbp

  pop rdi
  pop rsi
  
  pop rdx
  pop rcx
  pop rbx
  pop rax
}

macro exit c {
  mov rax, SYSCALL_EXIT
  mov rdi, c
  syscall
}

macro @iter2 counter_reg, a, b {
  local __loop
  mov r15, b
  inc r15

  macro @done2 \{
    inc counter_reg
    cmp counter_reg, r15
    jne __loop
  \}

  mov counter_reg, a
  __loop:
}

macro @iter1 counter_reg, a, b {
  local __loop
  mov r15, b
  inc r15

  macro @done1 \{
    inc counter_reg
    cmp counter_reg, r15
    jne __loop
  \}

  mov counter_reg, a
  __loop:
}

macro @iter0 counter_reg, a, b {
  local __loop
  mov r15, b
  inc r15

  macro @done0 \{
    inc counter_reg
    cmp counter_reg, r15
    jne __loop
  \}

  mov counter_reg, a
  __loop:
}

macro @mkstr name, string {
  local __mkstr
  __mkstr:
    name db string
    name#.len dq $-__mkstr
  @@
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

macro puts string {
  local .loop
  pusha64
  mov rbx, string
  .loop:
    write STDOUT, rbx, 1

    inc rbx
    cmp byte [rbx], 0
    jne .loop
  @@

  write STDOUT, newline, 1
  popa64
}
