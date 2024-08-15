format ELF64 executable 3
include 'bento.inc'

segment executable readable
entry $
  @iter r15, 1, [nums.len]
    write STDOUT, nums, r15
    write STDOUT, newline, 1
  @done

  puts hello_world
  exit 0
@@

segment readable writeable 
@mkstr hello_world, <"Hello, World", 0>
@mkstr nums, "123456789"
newline: db 0xA
