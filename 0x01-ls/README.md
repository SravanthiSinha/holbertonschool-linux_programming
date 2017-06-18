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


Task 2: To Implement the -1 option.

```
$ ls test -1
abc
ABC
file
File2
file3
folder1
Folder2
folder3
$ ./hls test -1
abc
ABC
file
File2
file3
folder1
Folder2
folder3
$
```

Task 3: To Implement the -a option.

Usage : hls [-a1] [FILE]...

```
$ ls -a test
.  ..  abc  ABC  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
$ ./hls -a test
.  ..  abc  ABC  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
$ ./hls -a test/folder1
.  ..  folder1-1  folder1-2  folder1-3
$  
```

Task 4: Implement the -A option.

Usage : hls [-A] [FILE]...

```
$ ls -A test
abc  ABC  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
$ ./hls -A test
abc  ABC  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
$ ./hls -A test/folder1
folder1-1  folder1-2  folder1-3
$
```

Task 5:Implement the -l option.

Usage : hls [-l] [FILE]...
```
$ ls -l test
total 12
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 abc
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 ABC
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 File2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file3
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 18 10:17 folder1
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 Folder2
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 folder3
lrwxrwxrwx 1 hybridivy hybridivy    8 Jun 18 10:17 myfile -> Makefile
$./hls -l test
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 abc
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 ABC
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 File2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file3
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 18 10:17 folder1
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 Folder2
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 folder3
lrwxrwxrwx 1 hybridivy hybridivy    8 Jun 18 10:17 myfile -> Makefile
$
```

Task 6: All options together. (still need to fix the sorting for hidden files)

Usage : hls [-1aAl] [FILE]...

```
$./hls -lA test
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 ..hidden3
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 .hidden1
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 .hidden2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 abc
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 ABC
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 File2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file3
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 18 10:17 folder1
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 Folder2
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 folder3
lrwxrwxrwx 1 hybridivy hybridivy    8 Jun 18 10:17 myfile -> Makefile
$./hls -lA -a test
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 18 10:17 .
drwxrwxr-x 6 hybridivy hybridivy 4096 Jun 18 14:18 ..
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 ..hidden3
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 .hidden1
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 .hidden2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 abc
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 ABC
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 File2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 18 10:17 file3
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 18 10:17 folder1
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 Folder2
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 18 10:17 folder3
lrwxrwxrwx 1 hybridivy hybridivy    8 Jun 18 10:17 myfile -> Makefile

```


Task 7: Implement the -r option.
Usage : hls [-1aAlr] [FILE]...

```
$ ./hls test
abc ABC file File2 file3 folder1 Folder2 folder3
$ ./hls test -r
folder3  Folder2  folder1  file3  File2  file  ABC  abc
$ ./hls test/folder1/ test/folder3/ -r
test/folder3/:
symlink  folder3-1  file2  file1

test/folder1/:
folder1-3  folder1-2  folder1-1
$
```

Task 8: Implement the -S option.
Usage : hls [-1aAlrS] [FILE]...
```
$./hls -l test
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 abc
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 ABC
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 file
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 File2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 file3
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 14 14:37 folder1
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 14 14:36 Folder2
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 14 14:36 folder3
$./hls -lS test
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 14 14:37 folder1
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 14 14:36 Folder2
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 14 14:36 folder3
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 abc
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 ABC
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 file
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 File2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 file3
$./hls -lSr test
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 file3
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 File2
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 file
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 ABC
-rw-rw-r-- 1 hybridivy hybridivy    0 Jun 14 14:35 abc
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 14 14:36 folder3
drwxrwxr-x 2 hybridivy hybridivy 4096 Jun 14 14:36 Folder2
drwxrwxr-x 5 hybridivy hybridivy 4096 Jun 14 14:37 folder1
```
