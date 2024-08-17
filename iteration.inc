macro @iter3 counter_reg, a, b {
  local __loop
  mov r15, b
  inc r15

  macro @done3 \{
    inc counter_reg
    cmp counter_reg, r15
    jne __loop
  \}

  mov counter_reg, a
  __loop:
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

