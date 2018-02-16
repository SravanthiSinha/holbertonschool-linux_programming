# 0x0B. C - Strace
### System programming & Algorithm ― Linux programming

* strace_0.c -  A program that executes and traces a given command.

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
