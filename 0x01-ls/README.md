# 0x01. C - ls


The project aims at Rewriting the ls command.

Task 0: To create a program that lists the content of the current directory.

```
$ls
hls  inc  Makefile  obj  README.md  src
$./hls
hls  inc  Makefile  obj  README.md  src

```

Task 1: To create a program should now take one or more file or directory names as parameters.

```
$ ls test
abc  ABC  file  File2  file3  folder1  Folder2  folder3
$ ./hls test
abc  ABC  file  File2  file3  folder1  Folder2  folder3
$ ./hls test/folder1/ test
test:
abc  ABC  file  File2  file3  folder1  Folder2  folder3

test/folder1/:
folder1-1  folder1-2  folder1-3
$ ./hls test/random
hls: cannot access test/random: No such file or directory
$
```
