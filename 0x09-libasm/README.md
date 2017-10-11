# 0x09. x86 Assembly - libASM
### System programming & Algorithm ― Linux programming

The Assembly syntax used is:
* x86 Assembly
* 64-bit architecture
* Intel

The tools used in the project are
* Ubuntu 14.04 LTS
* NASM version 2.10.09
* gcc version 4.8.4
* gdb - for debugging

Command used to assemble the asm files
```
 nasm -f elf64 <file.asm>
```

* libasm.h - The prototypes of all  functions are included in this header

* 0-strlen.asm - a copycat of the function strlen(3), in x86-64 Assembly

```
$ gcc -Wall -Wextra -Werror -pedantic -g3 -c -o 0-main.o 0-main.c
$ nasm -f elf64 -o 0-strlen.o 0-strlen.asm
$ gcc -o 0-strlen 0-main.o 0-strlen.o
$ ./0-strlen
All good!
$
```

# Useful Resources:
* [[EYNTK] x86-64 Assembly](https://intranet.hbtn.io/concepts/82)
* [List of registers](https://en.wikipedia.org/wiki/Processor_register)
* [List of Intel Instructions](http://www.penguin.cz/~literakl/intel/intel.html)
* [A video to explain how the stack frame works](https://www.youtube.com/watch?v=KRaJoeVXF_8)
* [Github repository containing the sources use](https://github.com/holbertonschool/0x09-libasm_concept)
