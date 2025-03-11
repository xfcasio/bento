macro @for counter, a, b {
  local loop

  mov QWORD [counter], a
  
  jmp loop
    counter: dq ?
  loop:

  macro @#counter \{
    inc QWORD [counter]
    cmp QWORD [counter], b
    jne loop
  \}
}
