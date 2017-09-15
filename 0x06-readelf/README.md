## 0x06. C - ELF: readelf
### System programming & Algorithm ― Linux programming

0-hreadelf -  a program that displays the information contained in the ELF file header of an ELF file.
```
Usage: 0-hreadelf elf_filename
```
standard output, error output and status are exact same as readelf -W -h

1-hreadelf - a program that displays the information contained in the ELF sections' headers of an ELF file.
```
Usage: 1-hreadelf elf_filename
```
standard output, error output and status are the exact same as readelf -W -S

2-hreadelf - a program that displays the information contained in the ELF program headers of an ELF file.
```
Usage: 2-hreadelf elf_filename
```
standard output, error output and status are the exact same as readelf -W -l

100-hreadelf - a program that displays the information contained in the ELF symbol tables of an ELF file.
```
Usage: 100-hreadelf elf_filename
```
standard output, error output and status are the exact same as readelf -W -s

## Useful Resources:
* man elf(5), man readelf(1)
* See also /usr/include/elf.h
* [ELF wiki](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format)
* [ELF](http://www.cs.stevens.edu/~jschauma/810/elf.html)
* [The ELF Object File Format: Introduction ](http://www.linuxjournal.com/article/1059)
* [The ELF Object File Format by Dissection](http://www.linuxjournal.com/node/1060/print)
* [ELF_Tutorial](http://wiki.osdev.org/ELF_Tutorial#ELF_Data_Types)
* [FILE Format](https://docs.oracle.com/cd/E19683-01/816-1386/6m7qcoblj/index.html#chapter6-73445)
