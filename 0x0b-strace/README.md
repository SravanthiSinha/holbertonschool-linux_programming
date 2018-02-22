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

* strace_4.c -  A program that executes and traces a given command. Each time a syscall is intercepted, prints its name, char * parameters , other s in hexadecimal and its return value in hexadecimal, followed by a new line

  Usage: ./strace_4 command [args...]

```
$make strace_4
[...]
$./strace_4 /bin/echo Holberton
execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 75 vars */]) = 0
brk(0) = 0xce3000
access("/etc/ld.so.nohwcap", 0) = 0xfffffffffffffffe
mmap(0, 0x2000, 0x3, 0x22, 0xffffffff, 0) = 0x7f92c4de2000
access("/etc/ld.so.preload", 0x4) = 0xfffffffffffffffe
open("/etc/ld.so.cache", 0x80000) = 0x3
fstat(0x3, 0x7fff2ef1fef0) = 0
mmap(0, 0x173e6, 0x1, 0x2, 0x3, 0) = 0x7f92c4dca000
close(0x3) = 0
access("/etc/ld.so.nohwcap", 0) = 0xfffffffffffffffe
open("/lib/x86_64-linux-gnu/libc.so.6", 0x80000) = 0x3
read(0x3, 0x7fff2ef20090, 0x340) = 0x340
fstat(0x3, 0x7fff2ef1ff40) = 0
mmap(0, 0x3c82c0, 0x5, 0x802, 0x3, 0) = 0x7f92c47f9000
mprotect(0x7f92c49b7000, 0x200000, 0) = 0
mmap(0x7f92c4bb7000, 0x6000, 0x3, 0x812, 0x3, 0x1be000) = 0x7f92c4bb7000
mmap(0x7f92c4bbd000, 0x42c0, 0x3, 0x32, 0xffffffff, 0) = 0x7f92c4bbd000
close(0x3) = 0
mmap(0, 0x1000, 0x3, 0x22, 0xffffffff, 0) = 0x7f92c4dc9000
mmap(0, 0x2000, 0x3, 0x22, 0xffffffff, 0) = 0x7f92c4dc7000
arch_prctl(0x1002, 0x7f92c4dc7740) = 0
mprotect(0x7f92c4bb7000, 0x4000, 0x1) = 0
mprotect(0x606000, 0x1000, 0x1) = 0
mprotect(0x7f92c4de4000, 0x1000, 0x1) = 0
munmap(0x7f92c4dca000, 0x173e6) = 0
brk(0) = 0xce3000
brk(0xd04000) = 0xd04000
open("/usr/lib/locale/locale-archive", 0x80000) = 0x3
fstat(0x3, 0x7f92c4bbcb60) = 0
mmap(0, 0x6e1e30, 0x1, 0x2, 0x3, 0) = 0x7f92c4117000
close(0x3) = 0
fstat(0x1, 0x7fff2ef20650) = 0
mmap(0, 0x1000, 0x3, 0x22, 0xffffffff, 0) = 0x7f92c4de1000
write(0x1, 0x7f92c4de1000, 0xaHolberton
) = 0xa
close(0x1) = 0
munmap(0x7f92c4de1000, 0x1000) = 0
close(0x2) = 0
exit_group(0) = ?
```

* strace_5.c -  A program that executes and traces a given command. Each time a syscall is intercepted, prints its name, arguments and return values, followed by a new line

  Note: Handles only following type of parameters
  - int
  - long
  - size_t
  - ssize_t
  - u64
  - uint32_t
  - unsigned int
  - unsigned long
  - pid_t


  Usage: ./strace_5 command [args...]

```
$make strace_5
[...]
$./strace_5 /bin/echo Holberton
execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 75 vars */]) = 0
brk(0) = 27238400
access("/etc/ld.so.nohwcap", 0) = -2
mmap(0, 8192, 3, 34, -1, 0) = 0x7f8a29bf2000
access("/etc/ld.so.preload", 4) = -2
open("/etc/ld.so.cache", 524288) = 3
fstat(3, 0x7ffe44a07da0) = 0
mmap(0, 95206, 1, 2, 3, 0) = 0x7f8a29bda000
close(3) = 0
access("/etc/ld.so.nohwcap", 0) = -2
open("/lib/x86_64-linux-gnu/libc.so.6", 524288) = 3
read(3, 0x7ffe44a07f40, 832) = 832
fstat(3, 0x7ffe44a07df0) = 0
mmap(0, 3965632, 5, 2050, 3, 0) = 0x7f8a29609000
mprotect(0x7f8a297c7000, 2097152, 0) = 0
mmap(0x7f8a299c7000, 24576, 3, 2066, 3, 0x1be000) = 0x7f8a299c7000
mmap(0x7f8a299cd000, 17088, 3, 50, -1, 0) = 0x7f8a299cd000
close(3) = 0
mmap(0, 4096, 3, 34, -1, 0) = 0x7f8a29bd9000
mmap(0, 8192, 3, 34, -1, 0) = 0x7f8a29bd7000
arch_prctl(4098, 140231382497088) = 0
mprotect(0x7f8a299c7000, 16384, 1) = 0
mprotect(0x606000, 4096, 1) = 0
mprotect(0x7f8a29bf4000, 4096, 1) = 0
munmap(0x7f8a29bda000, 95206) = 0
brk(0) = 27238400
brk(0x1a1b000) = 27373568
open("/usr/lib/locale/locale-archive", 524288) = 3
fstat(3, 0x7f8a299ccb60) = 0
mmap(0, 7216688, 1, 2, 3, 0) = 0x7f8a28f27000
close(3) = 0
fstat(1, 0x7ffe44a08500) = 0
mmap(0, 4096, 3, 34, -1, 0) = 0x7f8a29bf1000
write(1, 0x7f8a29bf1000, 10Holberton
) = 10
close(1) = 0
munmap(0x7f8a29bf1000, 4096) = 0
close(2) = 0
exit_group(0) = ?
$
```

* strace_6.c -  A program that executes and traces a given command. Each time a syscall is intercepted, prints its name, arguments and return values, followed by a new line

  Note: Handles only following macros and flags
  - NULL
  - All the flags for the mmap, open and access functions

  Usage: ./strace_6 command [args...]

```
$make strace_6
[...]
$./strace_6 /bin/echo Holberton
execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 75 vars */]) = 0
brk(0) = 23924736
access("/etc/ld.so.nohwcap", F_OK) = -2
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f6d10c76000
access("/etc/ld.so.preload", R_OK) = -2
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, 0x7ffd6f887a30) = 0
mmap(NULL, 95206, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f6d10c5e000
close(3) = 0
access("/etc/ld.so.nohwcap", F_OK) = -2
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, 0x7ffd6f887bd0, 832) = 832
fstat(3, 0x7ffd6f887a80) = 0
mmap(NULL, 3965632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f6d1068d000
mprotect(0x7f6d1084b000, 2097152, 0) = 0
mmap(0x7f6d10a4b000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1be000) = 0x7f6d10a4b000
mmap(0x7f6d10a51000, 17088, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f6d10a51000
close(3) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f6d10c5d000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f6d10c5b000
arch_prctl(4098, 140106409555776) = 0
mprotect(0x7f6d10a4b000, 16384, 1) = 0
mprotect(0x606000, 4096, 1) = 0
mprotect(0x7f6d10c78000, 4096, 1) = 0
munmap(0x7f6d10c5e000, 95206) = 0
brk(0) = 23924736
brk(0x16f2000) = 24059904
open("/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
fstat(3, 0x7f6d10a50b60) = 0
mmap(NULL, 7216688, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f6d0ffab000
close(3) = 0
fstat(1, 0x7ffd6f888190) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f6d10c75000
write(1, 0x7f6d10c75000, 10Holberton
) = 10
close(1) = 0
munmap(0x7f6d10c75000, 4096) = 0
close(2) = 0
exit_group(0) = ?
$
```


## Resources:

* [syscalls](https://filippo.io/linux-syscall-table/)
