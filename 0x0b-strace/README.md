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

## Resources:

* [syscalls](https://filippo.io/linux-syscall-table/)
