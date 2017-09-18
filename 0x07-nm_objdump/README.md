## 0x07. C - ELF: nm/objdump
### System programming & Algorithm ― Linux programming

nm.c -   A program that reproduce the GNU nm command
```
Usage: hnm [objfile ...]
```
standard output, error output and status are exact same as nm -p

objdump.c - A program that reproduce the GNU nmobjdump command
```
Usage: hobjdump [objfile ...]
```
standard output, error output and status are exact same as objdump -sf

## Useful Resources:
* man elf(5), man readelf(1)
* See also /usr/include/elf.h
* [ELF wiki](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format)
* [ELF](http://www.cs.stevens.edu/~jschauma/810/elf.html)
* [The ELF Object File Format: Introduction ](http://www.linuxjournal.com/article/1059)
* [The ELF Object File Format by Dissection](http://www.linuxjournal.com/node/1060/print)
* [ELF_Tutorial](http://wiki.osdev.org/ELF_Tutorial#ELF_Data_Types)
* [FILE Format](https://docs.oracle.com/cd/E19683-01/816-1386/6m7qcoblj/index.html#chapter6-73445)
