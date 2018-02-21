# 0x0B. C - Strace
### System programming & Algorithm ― Linux programming

* strace_0.c -  A program that executes and traces a given command. Each time a syscall is intercepted, it prints its number, followed by a new line

  Usage: ./strace_0 command [args...]

```
$make strace_0
[...]
$./strace_0 /bin/echo Holberton
59
12
12
21
21
9
9
21
21
2
2
5
5
9
9
3
3
21
21
2
2
0
0
5
5
9
9
10
10
9
9
9
9
3
3
9
9
9
9
158
158
10
10
10
10
10
10
11
11
12
12
12
12
5
5
9
9
1
Holberton
1
3
3
11
11
3
3
231
$
```

* strace_1.c -  A program that executes and traces a given command. Each time a syscall is intercepted, it prints its name, followed by a new line

  Usage: ./strace_1 command [args...]

```
$make strace_1
[...]
$./strace_1 /bin/echo Holberton
execve
brk
access
mmap
access
open
fstat
mmap
close
access
open
read
fstat
mmap
mprotect
mmap
mmap
close
mmap
mmap
arch_prctl
mprotect
mprotect
mprotect
munmap
brk
brk
open
fstat
mmap
close
fstat
mmap
write
Holberton
close
munmap
close
exit_group
$
```

* strace_2.c -  A program that executes and traces a given command. Each time a syscall is intercepted, prints its name and its return value in hexadecimal, followed by a new line

  Usage: ./strace_2 command [args...]

```
$make strace_2
[...]
$./strace_2 /bin/echo Holberton
execve = 0
brk = 0xf81000
access = 0xfffffffffffffffe
mmap = 0x7fe5259b7000
access = 0xfffffffffffffffe
open = 0x3
fstat = 0
mmap = 0x7fe52599f000
close = 0
access = 0xfffffffffffffffe
open = 0x3
read = 0x340
fstat = 0
mmap = 0x7fe5253ce000
mprotect = 0
mmap = 0x7fe52578c000
mmap = 0x7fe525792000
close = 0
mmap = 0x7fe52599e000
mmap = 0x7fe52599c000
arch_prctl = 0
mprotect = 0
mprotect = 0
mprotect = 0
munmap = 0
brk = 0xf81000
brk = 0xfa2000
open = 0x3
fstat = 0
mmap = 0x7fe524cec000
close = 0
fstat = 0
mmap = 0x7fe5259b6000
writeHolberton
 = 0xa
close = 0
munmap = 0
close = 0
exit_group = ?
$
```


* strace_3.c -  A program that executes and traces a given command. Each time a syscall is intercepted, prints its name , its parameters in hexadecimal, and its return value in hexadecimal, followed by a new line

  Usage: ./strace_3 command [args...]

```
$make strace_3
[...]
$./strace_3 /bin/echo Holberton
execve(0x7ffdc3dbb03b, 0x7ffdc3dbab20, 0x7ffdc3dbab38) = 0
brk(0) = 0x1bf1000
access(0x7f8b61f4caa0, 0) = 0xfffffffffffffffe
mmap(0, 0x2000, 0x3, 0x22, 0xffffffff, 0) = 0x7f8b62150000
access(0x7f8b61f4f5b0, 0x4) = 0xfffffffffffffffe
open(0x7f8b61f4cfd6, 0x80000) = 0x3
fstat(0x3, 0x7ffde86f1930) = 0
mmap(0, 0x173e6, 0x1, 0x2, 0x3, 0) = 0x7f8b62138000
close(0x3) = 0
access(0x7f8b61f4caa0, 0) = 0xfffffffffffffffe
open(0x7f8b6214ce31, 0x80000) = 0x3
read(0x3, 0x7ffde86f1ad0, 0x340) = 0x340
fstat(0x3, 0x7ffde86f1980) = 0
mmap(0, 0x3c82c0, 0x5, 0x802, 0x3, 0) = 0x7f8b61b67000
mprotect(0x7f8b61d25000, 0x200000, 0) = 0
mmap(0x7f8b61f25000, 0x6000, 0x3, 0x812, 0x3, 0x1be000) = 0x7f8b61f25000
mmap(0x7f8b61f2b000, 0x42c0, 0x3, 0x32, 0xffffffff, 0) = 0x7f8b61f2b000
close(0x3) = 0
mmap(0, 0x1000, 0x3, 0x22, 0xffffffff, 0) = 0x7f8b62137000
mmap(0, 0x2000, 0x3, 0x22, 0xffffffff, 0) = 0x7f8b62135000
arch_prctl(0x1002, 0x7f8b62135740) = 0
mprotect(0x7f8b61f25000, 0x4000, 0x1) = 0
mprotect(0x606000, 0x1000, 0x1) = 0
mprotect(0x7f8b62152000, 0x1000, 0x1) = 0
munmap(0x7f8b62138000, 0x173e6) = 0
brk(0) = 0x1bf1000
brk(0x1c12000) = 0x1c12000
open(0x7f8b61cefae0, 0x80000) = 0x3
fstat(0x3, 0x7f8b61f2ab60) = 0
mmap(0, 0x6e1e30, 0x1, 0x2, 0x3, 0) = 0x7f8b61485000
close(0x3) = 0
fstat(0x1, 0x7ffde86f2090) = 0
mmap(0, 0x1000, 0x3, 0x22, 0xffffffff, 0) = 0x7f8b6214f000
write(0x1, 0x7f8b6214f000, 0xaHolberton
) = 0xa
close(0x1) = 0
munmap(0x7f8b6214f000, 0x1000) = 0
close(0x2) = 0
exit_group(0) = ?
```
## Resources:

* [syscalls](https://filippo.io/linux-syscall-table/)
