# 0x00. C - Dynamic libraries



Task 0 : To create the dynamic library libholberton.so

Files :libholberton.so, holberton.h

```
$ls -la lib*
-rwxrwxr-x 1 hybridivy hybridivy 21808 Jun  6 17:03 libholberton.so
$nm -D libholberton.so
0000000000000ae5 T _abs
0000000000000afe T _atoi
0000000000202060 B __bss_start
                 w __cxa_finalize
0000000000202060 D _edata
0000000000202068 B _end
000000000000113c T _fini
                 w __gmon_start__
0000000000000948 T _init
0000000000000ba8 T _isalpha
0000000000000bc9 T _isdigit
0000000000000bea T _islower
0000000000000c0b T _isupper
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 w _Jv_RegisterClasses
0000000000001071 T _memcmp
0000000000000c2c T _memcpy
0000000000000c7d T _memset
0000000000000cbc T _putchar
0000000000000ce1 T _puts
0000000000000d1f T _strcat
0000000000000d9e T _strchr
0000000000000dd9 T _strcmp
0000000000000e28 T _strcpy
0000000000000e91 T _strlen
0000000000000ebf T _strncat
0000000000000f49 T _strncpy
0000000000000fcb T _strpbrk
000000000000101f T _strspn
00000000000010dc T _strstr
                 U write
$cat 0-main.c
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	printf("%d\n", _strlen("Holberton"));
	return (EXIT_SUCCESS);
}
$gcc -Wall -pedantic -Werror -Wextra -L. 0-main.c -lholberton -o len
$ldd len
	linux-vdso.so.1 =>  (0x00007ffea18e8000)
	libholberton.so => not found
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd8dc770000)
	/lib64/ld-linux-x86-64.so.2 (0x0000564b75259000)
$export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
$ldd len
	linux-vdso.so.1 =>  (0x00007ffc2d5c7000)
	libholberton.so => ./libholberton.so (0x00007f5c6e533000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f5c6e156000)
	/lib64/ld-linux-x86-64.so.2 (0x000055be4ecad000)
$./len
9
```

Task 1: To create a script that creates a dynamic library called liball.so from all the .c files that are in the current directory.

File: 1-create_dynamic_lib.sh

```
$ls *.c
_abs.c      _islower.c  _memset.c     _strcat.c  _strlen.c   _strspn.c
_atoi.c     _isupper.c  operations.c  _strchr.c  _strncat.c  _strstr.c
_isalpha.c  main.c      _putchar.c    _strcmp.c  _strncpy.c
_isdigit.c  _memcpy.c   _puts.c       _strcpy.c  _strpbrk.c
$./1-create_dynamic_lib.sh
$nm -D --defined-only liball.so
0000000000000bf5 T _abs
0000000000000df6 T add
0000000000000c0e T _atoi
0000000000202068 B __bss_start
0000000000000e33 T div
0000000000202068 D _edata
0000000000202070 B _end
00000000000012dc T _fini
0000000000000a48 T _init
0000000000000cb8 T _isalpha
0000000000000cd9 T _isdigit
0000000000000cfa T _islower
0000000000000d1b T _isupper
0000000000000d3c T main
0000000000001210 T _memcmp
0000000000000d66 T _memcpy
0000000000000db7 T _memset
0000000000000e46 T mod
0000000000000e20 T mul
0000000000000e5b T _putchar
0000000000000e80 T _puts
0000000000000ebe T _strcat
0000000000000f3d T _strchr
0000000000000f78 T _strcmp
0000000000000fc7 T _strcpy
0000000000001030 T _strlen
000000000000105e T _strncat
00000000000010e8 T _strncpy
000000000000116a T _strpbrk
00000000000011be T _strspn
000000000000127b T _strstr
0000000000000e0a T sub
$
```

Task 3:To create a dynamic library that contains C functions that can be called from Python.

File: 100-operations.so
```
$cat 100-tests.py
import random
import ctypes

cops = ctypes.CDLL('./100-operations.so')
a = random.randint(-111, 111)
b = random.randint(-111, 111)
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
$python3 100-tests.py
54 + -23 = 31
54 - -23 = 77
54 x -23 = -1242
54 / -23 = -2
54 % -23 = 8
$

```

Blog : [Static vs Dynamic Libraries](https://medium.com/@SravanthiSinha/static-vs-dynamic-libraries-3559c6274e5c)
