#inline-x86

###What?
Assembly language can be written in an inline mode. Some examples in C.

###Build Instruction
For the main program, use the makefile included.

For the other one:

```
/lib/cpp -m32 softint.S softint.s
a --32 -o softint.o softint.s
ld -m elf_i386 softint.o
```

A word of warning: this does not use /lib/ld-linux.so.2 for running.
