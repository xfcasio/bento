format ELF64 executable 3
include '../bento.inc'

segment executable readable
entry $
  @mkstr hello_world, <"Hello, World", 0>
  @mkstr nums, "123456789"

  xor eax, eax
  .if (eax = 0)
    @iter1 r8, 0, 9
      @iter2 rax, 0, 9
        @iter3 rbx, 0, 9
          mov qword [dummy], rbx
          add qword [dummy], 48
          write STDOUT, dummy, 1
        @done3
        write STDOUT, newline, 1
      @done2
      write STDOUT, newline, 1
    @done1
  .endif

  puts hello_world
  exit 0
@@

segment readable writeable 
dummy: dq 0
newline: db 0xA
