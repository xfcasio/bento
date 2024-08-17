macro @@ {}

SYSCALL_WRITE equ 1
SYSCALL_EXIT  equ 60

STDIN  equ 0
STDOUT equ 1
STDERR equ 2

include 'syscalls.inc'
include 'iteration.inc'
include 'misc.inc'
