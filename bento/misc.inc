macro @mkstr name, string {
  local __mkstr, data
  jmp __mkstr
  data db string
  name:
    .len dq $ - data
    .ptr dq ?
  __mkstr:
  lea r15, [data]
  mov QWORD [name#.ptr], r15
}

macro @open_data {
  local data_label
  jmp data_label

  macro @end_data \{
    data_label:
  \}
}

macro puts string {
  local .loop
  push rbx
  push rax

  mov rbx, QWORD [string#.ptr]
  sub rsp, 8
  mov rax, [string#.len]
  mov QWORD [rsp], rax

  .loop:
    write STDOUT, rbx, 1

    inc rbx
    dec QWORD [rsp]
    jnz .loop
  @@

  add rsp, 8
  
  pop rax
  pop rbx
}
