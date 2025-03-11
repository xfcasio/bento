format ELF64 executable 3
include '../bento.inc'

segment executable readable writeable
entry $
  @mkstr hello_world, "Hello, World"

  xor eax, eax
  .if (eax = 0)
    @for i, 0, 9
      @for j, 0, 9
        @for k, 0, 9
          mov r14, QWORD [k]
          mov QWORD [dummy], r14
          add QWORD [dummy], 48
          write STDOUT, dummy, 1
        @k
        write STDOUT, newline, 1
      @j
      write STDOUT, newline, 1
    @i
  .endif

  puts hello_world
  exit 0
@@

segment readable writeable 
dummy: dq 0
newline: db 0xA
