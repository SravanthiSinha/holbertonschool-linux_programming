# 0x02. Python - /proc filesystem

### System programming & Algorithm ― Linux programming


Task : Hack the VM

Write a script that finds a string in the heap of a running process, and replaces it.

* Usage: read_write_heap.py pid search_string replace_string
  * where pid is the pid of the running process
  * and strings are ASCII
* The script should look only in the heap of the process
* Output: you can print whatever you think is interesting
* On usage error, print an error message on stdout and exit with status code 1



File: read_write_heap.py


### Usefull Links:

https://www.kernel.org/doc/Documentation/filesystems/proc.txt

https://unix.stackexchange.com/questions/6301/how-do-i-read-from-proc-pid-mem-under-linux/6302#6302

https://stackoverflow.com/questions/12977179/reading-living-process-memory-without-interrupting-it-proc-kcore-is-an-option
