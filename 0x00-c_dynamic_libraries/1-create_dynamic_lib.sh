#!/bin/bash
gcc -c -Wall -Werror -Wextra -pedantic -fPIC -g *.c
gcc -shared -Wl,-soname,liball.so -o liball.so *.o -lc
rm -rf *.o
