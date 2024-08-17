format ELF64 executable 3
include 'bento.inc'

segment executable readable
entry $
  @iter0 r8, 0, 1
    @iter1 rax, 0, 1
      @iter2 rbx, 0, 1
        mov qword [dummy], rbx
        add qword [dummy], 48
        write STDOUT, dummy, 1
      @done2
      write STDOUT, newline, 1
    @done1
    write STDOUT, newline, 1
  @done0

  puts hello_world
  exit 0
@@

segment readable writeable 
@mkstr hello_world, <"Hello, World", 0>
@mkstr nums, "123456789"
dummy: dq 0
newline: db 0xA
