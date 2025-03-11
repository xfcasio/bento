<h1 align='center'> 🍱 bento (弁当) </h1>
A collection of macros intended at making assembly more convenient to write and a bit closer to C. Only for x86_64 linux and the FASM assembler (for now).

<h2> Example: </h2>


```asm
format ELF64 executable 3
include 'bento.inc'

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
```

> [!IMPORTANT]  
> As of now, using any macros that make and modify labels like `@for` (the counter is a label) requires that the executable (current) segment be also writeable, which may be a security concern.

<h3>compile with:<h3>


```
$ fasm main.s
$ ./main
```
