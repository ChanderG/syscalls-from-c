#Example of syscall

#include <asm/unistd.h>
#include <syscall.h>
#define STDOUT_FILENO 1
#define STDIN_FILENO 0

.file "softint.S"
.section        .rodata
L1:
.string "Testing software interrupt\n"
L2:
.space 10
L3:

.text
.globl _start
_start:

  # reads only a single character
	#movl  $(SYS_read), %eax
	#movl  $(STDIN_FILENO), %ebx
	#movl  $L2, %ecx
	#movl  $(L3-L2), %edx
	int   $128

  # reads only a single character
	#movl  $(SYS_read), %eax
	#movl  $(STDOUT_FILENO), %ebx
	#movl  $L2, %ecx
	#movl  $(L3-L2), %edx
	#int   $128

  #writes entire string
	movl  $(SYS_write), %eax
	movl  $(STDOUT_FILENO), %ebx
	movl  $L1, %ecx
	movl  $(L2-L1), %edx
	int   $128

	movl  $(SYS_exit), %eax
	movl  $0, %ebx
	int   $128

