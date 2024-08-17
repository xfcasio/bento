macro @mkstr name, string {
  local __mkstr
  __mkstr:
    name db string
    name#.len dq $-__mkstr
  @@
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
  popa64
}

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


