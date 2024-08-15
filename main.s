format ELF64 executable 3
include 'macros.inc'

segment executable readable
entry $
  @iter r15, 1, [nums.len]
    write STDOUT, nums, r15
    write STDOUT, newline, 1
  @done

  mov rbx, [nums.len]
  add rbx, 47
  write STDOUT, rbx, 1 
  write STDOUT, newline, 1

  puts nums
  write STDOUT, newline, 1

  exit 0
@@

segment readable writeable 
@mkstr hello_world, <"Hello, World", 0xA, 0>
@mkstr nums, <"123456789", 0>
newline: db 0xA
