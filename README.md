<h1 align='center'> 🍱 bento (弁当) </h1>
A collection of macros intended at making assembly more convenient to write and a bit closer to C. Only for x86_64 linux and the FASM assembler (for now).

<h2> Example: </h2>


```
format ELF64 executable 3
include 'bento.inc'

segment executable readable
entry $
  ;; 3 default copies of the @iter macro to allow sound nesting
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

  puts hello_world
  exit 0
@@

segment readable writeable 
@mkstr hello_world, <"Hello, World", 0>
@mkstr nums, "123456789"
dummy: dq 0
newline: db 0xA
```

<h3>simply compile with:<h3>
```
fasm main.s
./main
```
