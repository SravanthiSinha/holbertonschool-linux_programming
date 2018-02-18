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


## Resources:

* [syscalls](https://filippo.io/linux-syscall-table/)
